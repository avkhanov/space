//
// Created by akhanov on 11/28/2015.
//

#include "GlobalState.h"

void GlobalState::register_signal_handler(unsigned short signal, function<void (GlobalState *, void *)> callback) {
    callbacks[signal].push_back(callback);
}

void GlobalState::raise_signal(TYPE_SIGNAL signal, void *data) {
    for(function<void (GlobalState*, void*)> &i : callbacks[signal]) {
        i(this, data);
    }
}

void exit_callback(GlobalState* state, void* data) {
    state->threads.stop_console = 1;
    state->threads.stop_rendering = 1;
    state->threads.stop_ui = 1;
    state->executing = false;
}

GlobalState::GlobalState() {
    register_signal_handler(SIGNAL_EXIT, exit_callback);
}
