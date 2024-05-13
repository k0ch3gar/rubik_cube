//
// Created by KOSTJA on 10.02.2024.
//

#include "Cube.h"

#include <iostream>
#include "../Rubik.h"

Cube::~Cube() {

}

void Cube::drawCube(Shader* shader) {
    model = trnm * rotm;
    shader->uniformMatrix("model", model);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cube::rotateCube(GLfloat angle, vec3 rotationAxis) {

    rotm = rotm * inverse(trnm);

    if (rotationAxis == up || rotationAxis == -up) {
        int sign = up.x + up.y + up.z;
        rotm = rotate(rotm, angle, (sign > 0 ? Rubik::U : Rubik::D));
    }
    else if (rotationAxis == right || rotationAxis == -right) {
        int sign = right.x + right.y + right.z;
        rotm = rotate(rotm, angle, (sign > 0 ? Rubik::R : Rubik::L));
    }
    else if (rotationAxis == front || rotationAxis == -front) {
        int sign = front.x + front.y + front.z;
        rotm = rotate(rotm, angle, (sign > 0 ? Rubik::F : Rubik::B));
    }
    rotm = rotm * trnm;
}

void Cube::moveCube(vec3 offset) {
    this->offset = offset;
    trnm = translate(trnm, offset);
}

void Cube::updateVectors(vec3 rotationAxis, GLfloat angle) {
    if (rotationAxis == up || rotationAxis == -up) {
        int sign = up.x + up.y + up.z;
        vec3 tmp = (angle * sign < 0 ? front : -front);
        front = (angle * sign < 0 ? -right : right);
        right = tmp;
    }
    else if (rotationAxis == right || rotationAxis == -right) {
        int sign = right.x + right.y + right.z;
        vec3 tmp = (angle * sign < 0 ? up : -up);
        up = (angle * sign < 0 ? -front : front);
        front = tmp;
    }
    else if (rotationAxis == front || rotationAxis == -front) {
        int sign = front.x + front.y + front.z;
        vec3 tmp = (angle * sign < 0 ? right : -right);
        right = (angle * sign < 0 ? -up : up);
        up = tmp;
    }
}

Cube::Cube() = default;

vec3 Cube::getVector(vec3 vector) {

    if (vector == Rubik::R) {
        return right;
    }
    if (vector == Rubik::U) {
        return up;
    }
    if (vector == Rubik::F) {
        return front;
    }
    std::cerr << "ERROR: no such vector.";
    exit(-1);
}
