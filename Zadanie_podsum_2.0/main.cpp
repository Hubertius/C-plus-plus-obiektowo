#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <thread>

DWORD WINAPI f1(LPVOID lpPARAM);
DWORD WINAPI f2(LPVOID lpPARAM);
DWORD WINAPI generator(LPVOID lpPARAM);
using std::cout;
using std::endl;

CRITICAL_SECTION CriticalSection;
HANDLE gMutex;

int main()
{
    DWORD thread_id[3];
    HANDLE thread_handlers[3];
    std::vector<int> data;
    if( !InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
    {
        return 1;
    }
        
    gMutex = CreateMutex( 
        NULL, 
        false, 
        NULL);
    if( gMutex == NULL )
    {
        cout << "Create Mutex Error!";
        return 1;
    }
    LPVOID thread_param = reinterpret_cast<LPVOID>(&data);

    thread_handlers[0] = CreateThread(
        NULL,   // default security attributes
        0,      // use default stack size
        generator,     // thread function name
        thread_param,   // argument to thread function
        0,      // use default creation flags
        &thread_id[1]   // returns the thread identifier
    );

    thread_handlers[2] = CreateThread(
        NULL,   // default security attributes
        0,      // use default stack size
        f1,     // thread function name
        thread_param,   // argument to thread function
        0,      // use default creation flags
        &thread_id[1]   // returns the thread identifier
    );

     thread_handlers[2]= CreateThread(
        NULL,   // default security attributes
        0,      // use default stack size
        f2,     // thread function name
        thread_param,   // argument to thread function
        0,      // use default creation flags
        &thread_id[2]   // returns the thread identifier
    );

    if(thread_handlers[0] == NULL || thread_handlers[2] == NULL || thread_handlers[2] == NULL )
    {
        cout << "Error when create thread." << endl;
        ExitProcess(3);
    }

    WaitForMultipleObjects(2, thread_handlers, TRUE, INFINITE);
    DeleteCriticalSection(&CriticalSection);
    CloseHandle(thread_handlers[1]);
    CloseHandle(thread_handlers[2]);
    return 0;
}

DWORD WINAPI f1(LPVOID lpPARAM)
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    ReleaseMutex(gMutex);
    if( dwWaitResult == WAIT_OBJECT_0 )
    {
        std::vector<int> * collection = reinterpret_cast<std::vector<int>*>(lpPARAM);
        int sum = 0;
        for(auto i: *collection)
        {
            sum += i;
            cout << "-";
            Sleep(10);
        }
        cout << endl;
        EnterCriticalSection(&CriticalSection);
        cout << "Suma wynosi: " << sum << endl;
        LeaveCriticalSection(&CriticalSection);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;

}

DWORD WINAPI f2(LPVOID lpPARAM)
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    ReleaseMutex(gMutex);
    if( dwWaitResult == WAIT_OBJECT_0 )
    {
        std::vector<int> * collection = reinterpret_cast<std::vector<int>*>(lpPARAM);
        int multiplication = 1;
        for(auto i: *collection)
        {
            multiplication *= i;
            cout << "*";
            Sleep(10);
        }
        cout << endl;
        EnterCriticalSection(&CriticalSection);
        cout << "Iloczyn wynosi: " << multiplication << endl;    
        LeaveCriticalSection(&CriticalSection);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;
}




DWORD WINAPI generator(LPVOID lpPARAM)
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    if( dwWaitResult == WAIT_OBJECT_0 )
    {    
        std::vector<int> * collection = reinterpret_cast<std::vector<int>*>(lpPARAM);
        srand(time(NULL));
        for(int i = 0; i <= 9; i++)
        {
            (*collection).push_back(rand() % 100 + 1);
            cout << "g";
        }
        cout << endl;
        ReleaseMutex(gMutex);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;
}