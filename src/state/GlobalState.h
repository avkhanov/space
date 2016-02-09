//
// Created by akhanov on 11/28/2015.
//

#ifndef SPACE_GLOBALSTATE_H
#define SPACE_GLOBALSTATE_H

#include <map>
#include <vector>
#include <functional>
#include "../threads/Thread.h"

using namespace std;

#define TYPE_SIGNAL unsigned short int
#define SIGNAL_EXIT 0

class GlobalState {
protected:
    map<TYPE_SIGNAL, vector<function<void (GlobalState*, void*)>>> callbacks;
public:
    struct {
        bool stop_console = 0;
        bool stop_rendering = 0;
        bool stop_ui = 0;

        Thread *console_thread = NULL;
        Thread *render_thread = NULL;
    } threads;

    bool executing = true;

    GlobalState();
    void register_signal_handler(TYPE_SIGNAL signal, function<void(GlobalState*, void*)> callback);
    void raise_signal(TYPE_SIGNAL signal, void *data);
};


#endif //SPACE_GLOBALSTATE_H
