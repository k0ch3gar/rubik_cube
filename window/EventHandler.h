//
// Created by KOSTJA on 09.02.2024.
//

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "Window.h"


class EventHandler {
public:
    static bool* keys;
    static unsigned int* frames;
    static unsigned int currentFrame;
    static float deltaX;
    static float deltaY;
    static float x;
    static float y;
    static bool cursorLocked;
    static bool cursorStarted;

    static int init();
    static void pullEvents();

    static bool isPressed(int keycode);
    static bool isJustPressed(int keycode);
    static bool isClicked(int keycode);
    static bool isJustClicked(int keycode);
};



#endif //EVENTHANDLER_H
