//
// Created by akhanov on 11/28/2015.
//

#include "Thread.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __gnu_linux
#include <pthread.h>
#include <stdlib.h>
#endif

Thread::Thread(SPACE_THREAD_FUNC (*func)(SPACE_THREAD_DATA_PTR), SPACE_THREAD_DATA_PTR data) {
    this->thread_function = func;
    this->thread_data = data;
}

void Thread::start() {
#ifdef _WIN32
    this->thread_handle = CreateThread(NULL, 0, this->thread_function, this->thread_data, 0, 0);
#endif
#ifdef __gnu_linux__
    // this->thread_handle = pthread_create(this->thread_function, 
    // this->thread_handle = (pthread_t*)malloc(sizeof(pthread_t));
    pthread_create(&(this->thread_handle), NULL, this->thread_function, this->thread_data);
#endif
}

void Thread::join() {
#ifdef _WIN32
    WaitForSingleObject(this->thread_handle, INFINITE);
#endif
#ifdef __gnu_linux__
    pthread_join(this->thread_handle, NULL);
#endif
}
