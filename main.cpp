#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL

#include "window/Window.h"
#include "window/EventHandler.h"
#include "graphics/Shader.h"
#include "camera/Camera.h"
#include "rubik/Rubik.h"
#include "algorithm/RubikAlgorithm.h"
#include "algorithm/FileReader.h"
#include "logger/Logger.h"


int WIDTH = 1280;
int HEIGHT = 720;


int main() {

    Window::init(WIDTH, HEIGHT, "title");
    EventHandler::init();

    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    auto* shader = new Shader("../res/main.glslv", "../res/main.glslf");
    Camera::init(vec3(0,0,1), 70, 10.0f);
    Rubik::init();

    Rotation::setShader(shader);

    while (!Window::isShouldClose()) {
        EventHandler::pullEvents();
        if (EventHandler::isJustPressed(GLFW_KEY_ESCAPE)) {
            Window::setShouldClose(true);
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if (EventHandler::isPressed(GLFW_KEY_S)) {
            Camera::setCameraAngle(-0.001f, 0);
        }
        if (EventHandler::isPressed(GLFW_KEY_W)) {
            Camera::setCameraAngle(0.001f, 0);
        }
        if (EventHandler::isPressed(GLFW_KEY_D)) {
            Camera::setCameraAngle(0, 0.001f);
        }
        if (EventHandler::isPressed(GLFW_KEY_A)) {
            Camera::setCameraAngle(0, -0.001f);
        }

        if (EventHandler::isJustPressed(GLFW_KEY_P)) {
            FileReader::read("in.txt");
            FileReader::use();
        }

        if (EventHandler::isJustPressed(GLFW_KEY_F)) {
            Logger::print(vec3(0,0,0), 0);
            RubikAlgorithm::solve();
            Logger::print(vec3(0,0,0), 0);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_Q)) {
            Logger::print(vec3(0,0,0), 0);
            Scramble::scrumbleRubik();
            Logger::print(vec3(0,0,0), 0);
        }

        if (EventHandler::isJustPressed(GLFW_KEY_EQUAL)) {
            Rotation::setRotationSpeed(-1);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_MINUS)) {
            Rotation::setRotationSpeed(1);
        }

        if (EventHandler::isJustPressed(GLFW_KEY_Z)) {
            Rotation::rotateLayer(vec3(0.0f, 1.0f, 0.0f), 90.0f);
        }

        if (EventHandler::isJustPressed(GLFW_KEY_X)) {
            Rotation::rotateLayer(vec3(0.0f, 0.0f, 1.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_C)) {
            Rotation::rotateLayer(vec3(1.0f, 0.0f, 0.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_V)) {
            Rotation::rotateLayer(-vec3(0.0f, 1.0f, 0.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_B)) {
            Rotation::rotateLayer(-vec3(0.0f, 0.0f, 1.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_N)) {
            Rotation::rotateLayer(-vec3(1.0f, 0.0f, 0.0f), 90.0f);
        }


        Camera::updateVectors();
        Rubik::drawRubik(shader);

        Window::swapBuffers();
    }
    Window::terminate();

    return 0;
}