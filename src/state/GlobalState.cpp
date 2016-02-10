//
// Created by akhanov on 11/28/2015.
//

#include <iostream>
#include "GlobalState.h"

void GlobalState::register_signal_handler(unsigned short signal, std::function<void (GlobalState *, void *)> callback) {
    callbacks[signal].push_back(callback);
}

void GlobalState::raise_signal(TYPE_SIGNAL signal, void *data) {
    if(callbacks.find(signal) != callbacks.end()) {
        for (std::function<void(GlobalState *, void *)> &i : callbacks[signal]) {
            i(this, data);
        }
    }
}

 void exit_callback(GlobalState* state, void* data) {
     state->shutdown();
 }

GlobalState::GlobalState() {
    register_signal_handler(SIGNAL_EXIT, exit_callback);
}

void GlobalState::spawn_thread(const std::string& name, THREAD_SIGNATURE thread_func) {
    if(threads.find(name) != threads.end()) {
        std::string s("Thread with the name '" + name + "' already exists");
        std::cout << s << std::endl;
        throw s;
    } else {
        threads[name] = ThreadContainer(thread_func, (*this));
        bool stop = false;
    }
}

GlobalState::ThreadContainer::ThreadContainer() {
    t = NULL;
    stop = false;
}

GlobalState::ThreadContainer::ThreadContainer(THREAD_SIGNATURE thread_func, GlobalState& s) {
    ThreadContainer();
    set(thread_func, s);
}

void GlobalState::ThreadContainer::set(THREAD_SIGNATURE thread_func, GlobalState& s) {
    t = new std::thread(thread_func, std::ref(s), std::ref(stop));
}

GlobalState::ThreadContainer::~ThreadContainer() {
    if(t != NULL) {
        t->join();
        delete t;
        t = NULL;
    }
}

void GlobalState::shutdown() {
    for(auto& i : threads) {
        i.second.stop = true;
        i.second.t->join();
    }

    executing = false;
}