/* 

Hubert Kopeć 229274 Grupa 3D2
Zadanie "Laboratorium - podsumowanie - PROGRAM", Wariant B

*/

#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <thread>
#include <sstream>
#include <ctime>


using namespace std;

CRITICAL_SECTION CriticalSection;
HANDLE gMutex;
DWORD thread_id[4];
HANDLE thread_handlers[4];

class ParamForThreads
{
public:
    std::vector<int> data;
    int min;
    int max;
    double average;
};

void randomNumbersGenerator(vector<int> & data, const int how_many);
void saveNumbersToFile(vector<int> & data);
int process1( int inputParameter);

ParamForThreads * readFileForParameters(HANDLE file, ParamForThreads & object);
DWORD WINAPI min(LPVOID lpParam);
DWORD WINAPI max(LPVOID lpParam);
DWORD WINAPI avg(LPVOID lpParam);
DWORD WINAPI resultShow(LPVOID lpParam);
int process2();




int main(int argc, char **argv)
{
    if(argc < 2)
    {
        process2();
    }
    else
    {
        int parameterEntry;
        try
        {
            parameterEntry = stoi(argv[1]);
        }
        catch(const invalid_argument & e)
        {
            cout << "Something is wrong with entry argument." << endl;
            return 1;
        }
        process1(parameterEntry);
        STARTUPINFO startupinfo;
        PROCESS_INFORMATION process_information;

        ZeroMemory(&startupinfo, sizeof(startupinfo));
        startupinfo.cb = sizeof(startupinfo);
        ZeroMemory(&process_information, sizeof(process_information));

        CreateProcess(
                nullptr,
                argv[0],
                nullptr,
                nullptr,
                0,
                NORMAL_PRIORITY_CLASS,
                nullptr,
                nullptr,
                &startupinfo,
                &process_information
        );
        WaitForSingleObject(process_information.hProcess, INFINITE);
        CloseHandle(process_information.hProcess);
        CloseHandle(process_information.hThread);
    }
    return 0;
}

void randomNumbersGenerator(vector<int> & data, const int how_many)
{
    srand(time(NULL));
    /*
    data.resize(how_many);
    for(auto & element : data)
    {
        element = rand() % 10 + 1;
    }*/
    for(int i = 0; i < how_many; i++)
    {
        data.push_back(rand() % 10 + 1);
    }
}

void saveNumbersToFile(vector<int> & data)
{
    HANDLE file = CreateFile(
            "numbers.txt",
            GENERIC_WRITE,
            0,
            nullptr,
            CREATE_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            nullptr
    );

    if( file == INVALID_HANDLE_VALUE )
    {
        cout << "Something went wrong in the moment when file was created!" << endl;
        return;
    }


    string textStringToFile;
    unsigned int i = 0;
    for(auto element: data)
    {
        textStringToFile += to_string(element);
        if( i++ < (data.size() - 1)  )
        {
            textStringToFile += ",";
        }

    }


    if( WriteFile(file, textStringToFile.c_str(), textStringToFile.length(), nullptr, nullptr ) ) // Function returns bool true.
    {
        
    }
    else // Function returns bool false.
    {
        cout << "Something went wrong in attemption to write string with numbers into the file. ERROR!" << endl;
        return;
    }

    CloseHandle(file);
}

int process1(int inputParameter)
{
    std::vector<int> data;
    randomNumbersGenerator(data, inputParameter);
    saveNumbersToFile(data);
    return 0;
}

ParamForThreads * readFileForParameters(HANDLE file, ParamForThreads & object)
{
    ParamForThreads * pointerToThreadsParameters = &object;
    DWORD size_of_the_file = GetFileSize(file, nullptr);
    DWORD read;
    auto data_file = (LPSTR)GlobalAlloc(GPTR, size_of_the_file + 1);
    if( ReadFile(file, (LPSTR)data_file, size_of_the_file, &read, nullptr) ) // bool true
    {
        data_file[size_of_the_file] = 0;
        string contentOfTheFile(data_file);
        GlobalFree(data_file);
        stringstream input_stream(contentOfTheFile);
        int i;
        while( input_stream >> i )
        {
            cout << i << endl;
            pointerToThreadsParameters->data.push_back(i);
            if( input_stream.peek() == ',' )
            {
                input_stream.ignore();
            }
        }
    }
    else
    {
        CloseHandle(file);
    }
    return pointerToThreadsParameters;
}



DWORD WINAPI min(LPVOID lpParam) 
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    if (dwWaitResult == WAIT_OBJECT_0) {
        ParamForThreads *vectorObject = reinterpret_cast<ParamForThreads *>(lpParam);
        int minimum = vectorObject->data.at(0);
        for (int i = 0; i < vectorObject->data.size(); i++) {
            if (vectorObject->data[i] < minimum) 
            {
                minimum = vectorObject->data[i];
            }
            Sleep(10);
        }
        EnterCriticalSection(&CriticalSection);
        vectorObject->min = minimum;
        LeaveCriticalSection(&CriticalSection);
        ReleaseMutex(gMutex);
        return 0;
    }
    return -1;
}

DWORD WINAPI max(LPVOID lpParam)
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    if( dwWaitResult == WAIT_OBJECT_0 )
    {
        ParamForThreads * vectorObject = reinterpret_cast<ParamForThreads *>(lpParam);
        int maximum = vectorObject->data.at(0);
        for(int i = 0; i < vectorObject->data.size(); i++)
        {
            if( vectorObject->data[i] > maximum )
            {
                maximum = vectorObject->data[i];
            }
            Sleep(10);
        }
        EnterCriticalSection(&CriticalSection);
        vectorObject->max = maximum;
        LeaveCriticalSection(&CriticalSection);
        ReleaseMutex(gMutex);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;
}

DWORD WINAPI avg(LPVOID lpParam)
{
    DWORD dwWaitResult = WaitForSingleObject(gMutex, INFINITE);
    if( dwWaitResult == WAIT_OBJECT_0 )
    {
        ParamForThreads * vectorObject = reinterpret_cast<ParamForThreads *>(lpParam);
        double average = 0;
        int i;
        for(i = 0; i < vectorObject->data.size(); i++)
        {
            average += vectorObject->data[i];
            Sleep(10);
        }
        average /= i;
        EnterCriticalSection(&CriticalSection);
        vectorObject->average = average;
        ReleaseMutex(gMutex);
        LeaveCriticalSection(&CriticalSection);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;
}

DWORD WINAPI resultShow(LPVOID lpParam)
{
    DWORD dwaitResult = WaitForMultipleObjects(3, thread_handlers, TRUE, INFINITE);
    if( dwaitResult == WAIT_OBJECT_0 )
    {
        ParamForThreads * vectorObject = reinterpret_cast<ParamForThreads *>(lpParam);
        EnterCriticalSection(&CriticalSection);
        cout << endl;
        cout << "Minimum: " << vectorObject->min << endl;
        cout << "Maximum: " << vectorObject->max << endl;
        cout << "Average: " << vectorObject->average << endl;
        LeaveCriticalSection(&CriticalSection);
        ReleaseMutex(gMutex);
        return 0;
    }
    cout << "Error with thread synchronisation!" << endl;
    return -1;
}

int process2()
{
    HANDLE fileHandle;
    do
    {
        fileHandle = CreateFile(
                "numbers.txt",
                GENERIC_READ,
                 0,
                nullptr,
                OPEN_ALWAYS,
                FILE_ATTRIBUTE_NORMAL,
                nullptr
        );
    }while(fileHandle == INVALID_HANDLE_VALUE);
    ParamForThreads obj;
    ParamForThreads * paramObjectThreads;
    paramObjectThreads = readFileForParameters(fileHandle, obj);
    CloseHandle(fileHandle);
    if( !InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
    {
         return 1;
    }
    gMutex = CreateMutex(
            NULL,
            false,
            "m1");
    if( gMutex == nullptr )
    {
        cout << "Create Mutex Error!";
        return 1;
    }
    LPVOID thread_param = reinterpret_cast<LPVOID>(paramObjectThreads);
    WaitForSingleObject(gMutex, INFINITE);
    thread_handlers[0] = CreateThread(
            nullptr,   // default security attributes
            0,      // use default stack size
            min,     // thread function name
            thread_param,   // argument to thread function
            0,      // use default creation flags
            (LPDWORD)&thread_id[0]   // returns the thread identifier
        );

    thread_handlers[1] = CreateThread(
            nullptr,   // default security attributes
            0,      // use default stack size
            max,     // thread function name
            thread_param,   // argument to thread function
            0,      // use default creation flags
            (LPDWORD)&thread_id[1]   // returns the thread identifier
    );

    thread_handlers[2]= CreateThread(
            nullptr,   // default security attributes
            0,      // use default stack size
            avg,     // thread function name
            thread_param,   // argument to thread function
            0,      // use default creation flags
            (LPDWORD)&thread_id[2]   // returns the thread identifier
    );

    thread_handlers[3]= CreateThread(
            nullptr,   // default security attributes
            0,      // use default stack size
            resultShow,     // thread function name
            thread_param,   // argument to thread function
            0,      // use default creation flags
            (LPDWORD)&thread_id[3]   // returns the thread identifier
    );

    if(thread_handlers[0] == nullptr || thread_handlers[1] == nullptr || thread_handlers[2] == nullptr || thread_handlers[3] == nullptr )
    {
        cout << "Error when create thread." << endl;
        ExitProcess(3);
    }
    ReleaseMutex(gMutex);
    WaitForMultipleObjects(4, thread_handlers, TRUE, INFINITE);
    DeleteCriticalSection(&CriticalSection);
    CloseHandle(thread_handlers[0]);
    CloseHandle(thread_handlers[1]);
    CloseHandle(thread_handlers[2]);
    CloseHandle(gMutex);
    return 0;
 }

