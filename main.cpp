#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <vector>
#include <thread>



#define GLM_ENABLE_EXPERIMENTAL

#include "window/Window.h"
#include "window/EventHandler.h"
#include "graphics/Shader.h"
#include "camera/Camera.h"
#include "rubik/Rubik.h"
#include "algorithm/basicAlgorithm/BasicAlgorithm.h"
#include "algorithm/firstLayer/FirstLayer.h"
#include "algorithm/secondLayer/BuildSecondEdges.h"


int WIDTH = 1280;
int HEIGHT = 720;

int main() {
    Window::init(WIDTH, HEIGHT, "title");
    EventHandler::init();

    glClearColor(0,0,0,1);

    Camera* camera = new Camera(vec3(0,0,2), 70, 10.0f);
    Rubik* rubik = new Rubik(camera);



    while (!Window::isShouldClose()) {
        EventHandler::pullEvents();
        if (EventHandler::isJustPressed(GLFW_KEY_ESCAPE)) {
            Window::setShouldClose(true);
        }
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (EventHandler::isJustClicked(GLFW_MOUSE_BUTTON_1)) {
            std::cout << (float)(EventHandler::x - WIDTH / 2) / WIDTH * 2 << ' ';
            std::cout << (float)(HEIGHT / 2 - EventHandler::y) / WIDTH * 2<< '\n';
        }

        if (EventHandler::isPressed(GLFW_KEY_S)) {
            camera->pitch -= 0.005f;
        }
        if (EventHandler::isPressed(GLFW_KEY_W)) {
            camera->pitch += 0.005f;
        }
        if (EventHandler::isPressed(GLFW_KEY_D)) {
            camera->yaw += 0.005f;
        }
        if (EventHandler::isPressed(GLFW_KEY_A)) {
            camera->yaw -= 0.005f;
        }
        if (EventHandler::isJustPressed(GLFW_KEY_F)) {
            //BasicAlgorithm::pifPaf(camera, rubik, vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
            while (!FirstLayer::isWhiteCrossCorrect(rubik)) {
                FirstLayer::buildWhiteEdges(camera, rubik, 7);
                FirstLayer::buildWhiteEdges(camera, rubik, 15);
                FirstLayer::buildWhiteEdges(camera, rubik, 17);
                FirstLayer::buildWhiteEdges(camera, rubik, 25);
            }

            FirstLayer::buildWhiteLayer(camera, rubik, 6);
            FirstLayer::buildWhiteLayer(camera, rubik, 8);
            FirstLayer::buildWhiteLayer(camera, rubik, 24);
            FirstLayer::buildWhiteLayer(camera, rubik, 26);

            BuildSecondEdges::buildSecondEdges(camera, rubik, 3);
            BuildSecondEdges::buildSecondEdges(camera, rubik, 5);
            BuildSecondEdges::buildSecondEdges(camera, rubik, 21);
            BuildSecondEdges::buildSecondEdges(camera, rubik, 23);

            BuildSecondEdges::yellowEdgesFlips(camera, rubik);
            BuildSecondEdges::moveYellowEdges(camera, rubik);
            BuildSecondEdges::moveYellowCorners(camera, rubik);
            BuildSecondEdges::rotateYellowCorners(camera, rubik);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_Z)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, 1.0f, 0.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_X)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, 0.0f, 1.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_C)) {
            Rotation::rotateLayer(camera, rubik, vec3(1.0f, 0.0f, 0.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_V)) {
            Rotation::rotateLayer(camera, rubik, -vec3(0.0f, 1.0f, 0.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_B)) {
            Rotation::rotateLayer(camera, rubik, -vec3(0.0f, 0.0f, 1.0f), 90.0f);
        }
        if (EventHandler::isJustPressed(GLFW_KEY_N)) {
            Rotation::rotateLayer(camera, rubik, -vec3(1.0f, 0.0f, 0.0f), 90.0f);
        }

        camera->updateVectors();
        rubik->drawRubik();
        Window::swapBuffers();
    }
    Window::terminate();
    return 0;
}