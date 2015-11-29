//
// Created by akhanov on 11/28/2015.
//

#ifndef SPACE_GLOBALSTATE_H
#define SPACE_GLOBALSTATE_H

#include <thread>

class GlobalState {
public:
    struct {
        bool stop_console = 0;
        bool stop_rendering = 0;
        bool stop_ui = 0;

//        std::thread *console_thread = NULL;
//        std::thread *render_thread = NULL;

    } threads;
};


#endif //SPACE_GLOBALSTATE_H
