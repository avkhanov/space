#include <iostream>
#include "state/GlobalState.h"
#include "threads/console.h"
#include "threads/rendering.h"

using namespace std;

int main(int argc, char** argv) {
    GlobalState *state = new GlobalState();

    start_console_thread(state);
    start_render_thread(state);

    while(!state->stop_execution);

    stop_console_thread(state);
    stop_render_thread(state);

    delete state;

    return 0;
}

