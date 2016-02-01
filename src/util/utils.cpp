//
// Created by akhanov on 11/29/2015.
//

#include "utils.h"

void exit_program(GlobalState *state) {
    state->stop_execution = 1;
}