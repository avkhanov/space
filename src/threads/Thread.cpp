//
// Created by akhanov on 11/28/2015.
//

#include "Thread.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

Thread::Thread(SPACE_THREAD_FUNC (*func)(SPACE_THREAD_DATA_PTR), SPACE_THREAD_DATA_PTR data) {
    this->thread_function = func;
    this->thread_data = data;
}

void Thread::start() {
#ifdef _WIN32
    this->thread_handle = CreateThread(NULL, 0, this->thread_function, this->thread_data, 0, 0);
#endif
}

void Thread::join() {
#ifdef _WIN32
    WaitForSingleObject(this->thread_handle, INFINITE);
#endif
}