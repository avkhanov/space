//
// Created by akhanov on 11/28/2015.
//

#ifndef SPACE_THREAD_H
#define SPACE_THREAD_H

#ifdef _WIN32
#define PLATFORM "WINDOWS"
#include <windows.h>
#define SPACE_THREAD_FUNC DWORD WINAPI
#define SPACE_THREAD_DATA_PTR LPVOID
#define SPACE_THREAD_HANDLE HANDLE
#endif

#ifdef __gnu_linux__
#define PLATFORM "LINUX"
#include <pthread.h>
#define SPACE_THREAD_FUNC void*
#define SPACE_THREAD_DATA_PTR void*
#define SPACE_THREAD_HANDLE pthread_t
#endif

class Thread {
private:
    SPACE_THREAD_FUNC (*thread_function)(SPACE_THREAD_DATA_PTR) = NULL;

    SPACE_THREAD_DATA_PTR thread_data = NULL;
    SPACE_THREAD_HANDLE thread_handle;

public:
    Thread(SPACE_THREAD_FUNC (*func)(SPACE_THREAD_DATA_PTR), SPACE_THREAD_DATA_PTR data);
    void start();
    void join();
};


#endif //SPACE_THREAD_H
