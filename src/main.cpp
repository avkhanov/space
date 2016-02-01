#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "interface/console/InterfaceTerminalConsole.h"
#include "threads/Thread.h"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    //Thread *t = new Thread();
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
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
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
//
//#include <iostream>
//
//using namespace std;
//
//SPACE_THREAD_FUNC my_thread(SPACE_THREAD_DATA_PTR data) {
//    std::cout << "HELLO WORLD!!!" << " I am a thread!" << " Your Value: " << *((int *)(data)) << std::endl;
//    // return 0;
//}
//int main(int argc, char** argv) {
//    int data = 15;
//    int data2 = 2389;
//
//    Thread *t = new Thread(my_thread, (SPACE_THREAD_DATA_PTR)(&data));
//    Thread *t2 = new Thread(my_thread, ((SPACE_THREAD_DATA_PTR)(&data2)));
//
//    t->start();
//    t2->start();
//
//    t->join();
//    t2->join();
//
//    return 0;
//}
