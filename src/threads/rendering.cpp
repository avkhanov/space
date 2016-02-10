//
// Created by akhanov on 11/29/2015.
//

#include "rendering.h"
#include <iostream>
#include "GLFW/glfw3.h"
#include <cstdio>
#include "../util/utils.h"

static GlobalState *__state = NULL;

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
        // __state->raise_signal(SIGNAL_EXIT, NULL);
    }
}

void __render_thread(GlobalState& state, bool& stop_execution) {
    //__state = (GlobalState*)data;
    __state = &state;

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
        __state->raise_signal(SIGNAL_EXIT, NULL);
    }

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);

    if (!window) {
        glfwTerminate();
        __state->raise_signal(SIGNAL_EXIT, NULL);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window) && !stop_execution) {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    __state->raise_signal(SIGNAL_EXIT, NULL);
    glfwDestroyWindow(window);
    glfwTerminate();
    //exit(EXIT_SUCCESS);
    //__state->raise_signal(SIGNAL_EXIT, NULL);
}

void start_render_thread(GlobalState &state) {
    /* state.threads.stop_rendering = 0;
    state.threads.render_thread = new Thread(__render_thread, (SPACE_THREAD_DATA_PTR)(&state));
    state.threads.render_thread->start(); */
}

void stop_render_thread(GlobalState &state) {
    /* state.threads.stop_rendering = 1;

    if(state.threads.render_thread != NULL) {
        state.threads.render_thread->join();
        delete state.threads.render_thread;
    }

    state.threads.render_thread = NULL; */
}
