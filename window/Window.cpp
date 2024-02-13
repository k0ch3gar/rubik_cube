//
// Created by KOSTJA on 09.02.2024.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include <iostream>

GLFWwindow* Window::window;
int Window::width = 0;
int Window::height = 0;


int Window::init(int width, int height, const char *title) {
    glfwInit();
    glPointSize(1.0);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Couldn't create window!\n";
        glfwTerminate();
        return -1;
    }

    Window::width = width;
    Window::height = height;

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialized glew!\n";
        return -1;
    }
    glViewport(0, 0, width, height);
    return 0;
}

void Window::terminate() {
    glfwTerminate();
}

bool Window::isShouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool flag) {
    glfwSetWindowShouldClose(window, flag);
}

void Window::swapBuffers() {
    glfwSwapBuffers(window);
}
