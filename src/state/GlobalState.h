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

class GlobalState {
protected:
    struct _thread {
        std::thread* t = NULL;
        bool halt = false;
    };

    std::map<TYPE_SIGNAL, std::vector<std::function<void (GlobalState*, void*)>>> callbacks;
    // std::map<std::string, _thread> threads;
    std::map<std::string, std::function<void(bool&, void*)>> threads;

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
    void spawn_thread(const std::string& name, std::function<void(bool&, void*)> thread_func);
};


#endif //SPACE_GLOBALSTATE_H
