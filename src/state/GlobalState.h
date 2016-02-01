//
// Created by akhanov on 11/28/2015.
//

#ifndef SPACE_GLOBALSTATE_H
#define SPACE_GLOBALSTATE_H

#include "../threads/Thread.h"

class GlobalState {
public:
    struct {
        bool stop_console = 0;
        bool stop_rendering = 0;
        bool stop_ui = 0;

        Thread *console_thread = NULL;
        Thread *render_thread = NULL;

    } threads;

    bool stop_execution = 0;
};


#endif //SPACE_GLOBALSTATE_H
