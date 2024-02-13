//
// Created by KOSTJA on 09.02.2024.
//

#ifndef WINDOW_H
#define WINDOW_H

class GLFWwindow;

class Window {

public:
    static GLFWwindow* window;
    static int width;
    static int height;

    static int init(int width, int height, const char* title);
    static void terminate();

    static bool isShouldClose();
    static void setShouldClose(bool flag);
    static void swapBuffers();
};



#endif //WINDOW_H
