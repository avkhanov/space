//
// Created by akhanov on 11/28/2015.
//

#include "console.h"
#include "../state/GlobalState.h"
#include "Thread.h"
#include <iostream>

SPACE_THREAD_FUNC __console_thread(SPACE_THREAD_DATA_PTR data) {
    GlobalState *state = (GlobalState*)data;

    while(!state->threads.stop_console) {

    }

    //std::cout << "Done!!!" << std::endl;

}

void start_console_thread(GlobalState *state) {
    state->threads.stop_console = 0;
    state->threads.console_thread = new Thread(__console_thread, (SPACE_THREAD_DATA_PTR)state);
    state->threads.console_thread->start();
}

void stop_console_thread(GlobalState *state) {
    state->threads.stop_console = 1;

    if(state->threads.console_thread != NULL) {
        state->threads.console_thread->join();
        delete state->threads.console_thread;
    }

    state->threads.console_thread = NULL;
}