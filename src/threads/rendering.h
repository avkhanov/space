//
// Created by akhanov on 11/29/2015.
//

#ifndef SPACE_RENDERING_H
#define SPACE_RENDERING_H

#include "../state/GlobalState.h"

void start_render_thread(GlobalState &state);
void stop_render_thread(GlobalState &state);
void __render_thread(bool& stop_execution, void* data);

#endif //SPACE_RENDERING_H
