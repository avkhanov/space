//
// Created by akhanov on 11/28/2015.
//

#ifndef SPACE_GLOBALSTATE_H
#define SPACE_GLOBALSTATE_H

#include <map>
#include <vector>
#include <functional>
#include <string>
#include <thread>

// using namespace std;

#define TYPE_SIGNAL unsigned short int
#define SIGNAL_EXIT 0

#define THREAD_SIGNATURE std::function<void(GlobalState&, bool&)>

class GlobalState {
protected:
    class ThreadContainer {
    public:
        std::thread* t = NULL;
        // std::thread t;
        bool stop = false;

        ThreadContainer();
        //ThreadContainer(std::function<void(bool&, void*)> thread_func);
        ThreadContainer(THREAD_SIGNATURE thread_func, GlobalState& s);
        void set(THREAD_SIGNATURE thread_func, GlobalState& s);
        ~ThreadContainer();
    };

    std::map<TYPE_SIGNAL, std::vector<std::function<void (GlobalState*, void*)>>> callbacks;
    std::map<std::string, ThreadContainer> threads;
    //std::map<std::string, std::function<void(bool&, void*)>> threads;

public:
    /* struct {
        bool stop_console = 0;
        bool stop_rendering = 0;
        bool stop_ui = 0;

        Thread *console_thread = NULL;
        Thread *render_thread = NULL;
    } threads; */

    bool executing = true;

    GlobalState();
    void register_signal_handler(TYPE_SIGNAL signal, std::function<void(GlobalState*, void*)> callback);
    void raise_signal(TYPE_SIGNAL signal, void* data);
    void spawn_thread(const std::string& name, THREAD_SIGNATURE thread_func);

    void shutdown();
};


#endif //SPACE_GLOBALSTATE_H
