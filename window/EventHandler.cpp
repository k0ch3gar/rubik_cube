//
// Created by KOSTJA on 09.02.2024.
//

#include "EventHandler.h"
#include <GLFW/glfw3.h>
#include <cstring>

bool* EventHandler::keys;
unsigned int* EventHandler::frames;
unsigned int EventHandler::currentFrame = 0;
float EventHandler::deltaX = 0.0f;
float EventHandler::deltaY = 0.0f;
float EventHandler::x = 0.0f;
float EventHandler::y = 0.0f;
bool EventHandler::cursorLocked = false;
bool EventHandler::cursorStarted = false;

int MOUSE_BUTTONS = 1024;

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    if (EventHandler::cursorLocked) {
        EventHandler::deltaX += xpos - EventHandler::x;
        EventHandler::deltaY += ypos - EventHandler::y;
    }
    else {
        EventHandler::cursorLocked = true;
    }
    EventHandler::x = xpos;
    EventHandler::y = ypos;
}

void windowResizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    Window::width = width;
    Window::height = height;
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mode) {
    if (action == GLFW_PRESS) {
        EventHandler::keys[MOUSE_BUTTONS + button] = true;
        EventHandler::frames[MOUSE_BUTTONS + button] = EventHandler::currentFrame;
    }
    else if (action == GLFW_RELEASE) {
        EventHandler::keys[MOUSE_BUTTONS + button] = false;
        EventHandler::frames[MOUSE_BUTTONS + button] = EventHandler::currentFrame;
    }
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (action == GLFW_PRESS) {
        EventHandler::keys[key] = true;
        EventHandler::frames[key] = EventHandler::currentFrame;
    }
    else if (action == GLFW_RELEASE) {
        EventHandler::keys[key] = false;
        EventHandler::frames[key] = EventHandler::currentFrame;
    }
}

int EventHandler::init() {
    GLFWwindow* window = Window::window;
    keys = new bool[1032];
    frames = new unsigned int[1032];

    memset(keys, false, 1032*sizeof(bool));
    memset(frames, 0, 1032*sizeof(unsigned int));

    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetWindowSizeCallback(window, windowResizeCallback);
    return 0;
}

void EventHandler::pullEvents() {
    currentFrame++;
    deltaX = 0.0f;
    deltaY = 0.0f;
    glfwPollEvents();
}

bool EventHandler::isPressed(int keycode) {
    if (keycode < 0 || keycode >= MOUSE_BUTTONS) {
        return false;
    }
    return keys[keycode];
}

bool EventHandler::isJustPressed(int keycode) {
    if (keycode < 0 || keycode >= MOUSE_BUTTONS) {
        return false;
    }
    return keys[keycode] && frames[keycode] == currentFrame;
}

bool EventHandler::isClicked(int keycode) {
    int index = keycode + MOUSE_BUTTONS;
    return keys[index];
}

bool EventHandler::isJustClicked(int keycode) {
    int index = keycode + MOUSE_BUTTONS;
    return keys[index] && frames[index] == currentFrame;
}
