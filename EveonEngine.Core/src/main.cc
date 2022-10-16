#include "graphics/window.h"
#include <iostream>

void Loop(GLFWwindow *ctx)
{
    glClearColor(0.546f, 0.12f, 0.65, 1.0f);

    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

int main()
{

    eveon::graphics::EvWindow win("Eveon Engine", 1080, 720);
    win.Run(&Loop);
    return win.Exit(EV_GRACEFUL_EXIT);
}
