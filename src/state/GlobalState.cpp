//
// Created by akhanov on 11/28/2015.
//

#include <iostream>
#include "GlobalState.h"

void GlobalState::register_signal_handler(unsigned short signal, std::function<void (GlobalState *, void *)> callback) {
    callbacks[signal].push_back(callback);
}

void GlobalState::raise_signal(TYPE_SIGNAL signal, void *data) {
    for(std::function<void (GlobalState*, void*)> &i : callbacks[signal]) {
        i(this, data);
    }
}

// void exit_callback(GlobalState* state, void* data) {
//     state->threads.stop_console = 1;
//     state->threads.stop_rendering = 1;
//     state->threads.stop_ui = 1;
//     state->executing = false;
// }

GlobalState::GlobalState() {
    // register_signal_handler(SIGNAL_EXIT, exit_callback);
}

void GlobalState::spawn_thread(const std::string& name, std::function<void(bool&, void*)> thread_func) {
    if(threads.find(name) != threads.end()) {
        std::string s("Thread with the name '" + name + "' already exists");
        std::cout << s << std::endl;
        throw s;
    } else {
        threads[name] = ThreadContainer(thread_func);
        bool stop = false;
    }
}

GlobalState::ThreadContainer::ThreadContainer() {
    t = NULL;
    stop = false;
}

GlobalState::ThreadContainer::ThreadContainer(std::function<void(bool &, void *)> thread_func) {
    ThreadContainer();
    set(thread_func);
}

void GlobalState::ThreadContainer::set(std::function<void(bool&, void*)> thread_func) {
    t = new std::thread(thread_func, std::ref(stop), (void*)NULL);
}

GlobalState::ThreadContainer::~ThreadContainer() {
    if(t != NULL) {
        t->join();
        delete t;
        t = NULL;
    }
}