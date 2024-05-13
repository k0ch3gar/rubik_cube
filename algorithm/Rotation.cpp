//
// Created by KOSTJA on 12.02.2024.
//

#include "Rotation.h"

int Rotation::rotationSpeed = 60;
Shader* Rotation::shader;

void Rotation::rotateLayer(vec3 rotationAxis, GLfloat angle) {
    for (int i = 0; i < rotationSpeed; i++) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        Rubik::rotateLayer(rotationAxis, radians(angle / (float)(rotationSpeed)));
        Rubik::drawRubik(shader);
        Window::swapBuffers();
    }
    Logger::print(rotationAxis, angle);
    Rubik::updateVector(rotationAxis, radians(angle));
}

void Rotation::setRotationSpeed(int speed) {
    rotationSpeed += speed * 60;
    rotationSpeed = std::max(rotationSpeed, 1);
}

void Rotation::setShader(Shader* shader1) {
    shader = shader1;
}
