#include <iostream>
#include "state/GlobalState.h"
#include "threads/console.h"
#include "threads/rendering.h"

using namespace std;

void callback_func(bool& running, void* data) {
}

int main(int argc, char** argv) {
    GlobalState state;

    // start_console_thread(state);
    // start_render_thread(state);
    state.spawn_thread("render_thread", __render_thread);
    //  state.spawn_thread("My Thread", callback_func);
    
    while(state.executing);

    // stop_console_thread(state);
    // stop_render_thread(state);

    return 0;
}
