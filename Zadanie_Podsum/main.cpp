#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>


DWORD WINAPI f1(LPVOID lpPARAM);
DWORD WINAPI f2(LPVOID lpPARAM);
DWORD WINAPI generator(LPVOID lpPARAM);
using std::cout;
using std::endl;

CRITICAL_SECTION CriticalSection;
HANDLE gMutex;

class ParamForThreads
{
    public:
        std::vector<int> data;
        int count;
};

int main()
{
    DWORD thread_id[3];
    HANDLE thread_handlers[3];
    ParamForThreads paramObjectThreads;
    paramObjectThreads.count = 10;
    if( !InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
    {
        return 1;
    }
        
    gMutex = CreateMutex( 
        NULL, 
        false, 
        "m1");
    if( gMutex == NULL )
    {
        cout << "Create Mutex Error!";
        return 1;
    }
    LPVOID thread_param = reinterpret_cast<LPVOID>(&paramObjectThreads);
    WaitForSingleObject(gMutex, INFINITE);
    //OpenMutex(MUTEX_ALL_ACCESS, TRUE, gMutex);
    thread_handlers[2] = CreateThread(
        NULL,   // default security attributes
        0,      // use default stack size
        generator,     // thread function name
        thread_param,   // argument to thread function
        0,      // use default creation flags
        (LPDWORD)&thread_id[2]   // returns the thread identifier
    );

    thread_handlers[0] = CreateThread(
        NULL,   // default security attributes
        0,      // use default stack size
        f1,     // thread function name
        thread_param,   // argument to thread function
        0,      // use default creation flags
        (LPDWORD)&thread_id[0]   // returns the thread identifier
    );

     thread_handlers[1]= CreateThread(
        NULL,   // default security attributes
        0,      // use default stack size
        f2,     // thread function name
        thread_param,   // argument to thread function
        0,      // use default creation flags
        (LPDWORD)&thread_id[1]   // returns the thread identifier
    );

    if(thread_handlers[0] == NULL || thread_handlers[1] == NULL || thread_handlers[2] == NULL )
    {
        cout << "Error when create thread." << endl;
        ExitProcess(3);
    }
    WaitForSingleObject(thread_handlers[2], INFINITE);
    ReleaseMutex(gMutex);
    WaitForMultipleObjects(2, thread_handlers, TRUE, INFINITE);
    DeleteCriticalSection(&CriticalSection);
    CloseHandle(thread_handlers[0]);
    CloseHandle(thread_handlers[1]);
    CloseHandle(thread_handlers[2]);
    CloseHandle(gMutex);
    return 0;
}

DWORD WINAPI f1(LPVOID lpPARAM)
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    if( dwWaitResult == WAIT_OBJECT_0 )
    {
        ParamForThreads * vectorObject = reinterpret_cast<ParamForThreads *>(lpPARAM);
        int sum = 0;
        for(int i = 0; i < vectorObject->count; i++)
        {
            sum += vectorObject->data[i];
            cout << "-";
            Sleep(10);
        }
        EnterCriticalSection(&CriticalSection);
        cout << "\nSuma wynosi: " << sum << endl;
        ReleaseMutex(gMutex);
        LeaveCriticalSection(&CriticalSection);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;
}

DWORD WINAPI f2(LPVOID lpPARAM)
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    if( dwWaitResult == WAIT_OBJECT_0 )
    {
        ParamForThreads * vectorObject = reinterpret_cast<ParamForThreads *>(lpPARAM);
        int multiplication = 1;
        for(int i = 0; i < vectorObject->count; i++)
        {
            multiplication *= vectorObject->data[i];
           // cout << "i: (" << i <<  ")" << endl;
            //cout << "Multiplication: (" << multiplication <<  ")" << endl;
            cout << "*"; 
            Sleep(10);
        }
        EnterCriticalSection(&CriticalSection);
        cout << "\nIloczyn wynosi: " << multiplication << endl;
        ReleaseMutex(gMutex);   
        LeaveCriticalSection(&CriticalSection);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;
}




DWORD WINAPI generator(LPVOID lpPARAM)
{
    ParamForThreads * vectorObject = reinterpret_cast<ParamForThreads *>(lpPARAM);
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        int a = rand() % 10 + 1;
        //cout << endl;
        //cout << a << endl;
        vectorObject->data.push_back(a);
        cout << "g";
    }
    cout << endl;
    ReleaseMutex(gMutex);
    return 0;
}