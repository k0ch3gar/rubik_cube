//
// Created by KOSTJA on 12.02.2024.
//

#include "Rotation.h"

void Rotation::rotateLayer(Camera *camera, Rubik *rubik, vec3 rotationAxis, GLfloat angle) {
    for (int i = 0; i < 60; i++) {
        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        rubik->rotateLayer(rotationAxis, radians(angle / 60.0f));
        camera->updateVectors();
        rubik->drawRubik();
        Window::swapBuffers();
    }
    rubik->updateVector(rotationAxis, radians(angle));
}
