//
// Created by KOSTJA on 10.02.2024.
//

#include "Cube.h"

float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.9f, 0.5f, 0.05f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.9f, 0.5f, 0.05f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.9f, 0.5f, 0.05f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.9f, 0.5f, 0.05f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.9f, 0.5f, 0.05f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.9f, 0.5f, 0.05f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
};


Cube::Cube(Camera* camera) : camera(camera) {
    shader = load_shader("../res/main.glslv", "../res/main.glslf");

    model = mat4(1.0f);
    offset = vec3(0.0f);

    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(5 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

Cube::~Cube() {

}

void Cube::drawCube() {

    glBindVertexArray(VAO);
    shader->use();
    shader->uniformMatrix("model", model);
    shader->uniformMatrix("view", camera->getView());
    shader->uniformMatrix("projection", camera->getProjection());

    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}

void Cube::rotateCube(GLfloat angle, vec3 rotationAxis) {

    model = translate(model, offset);
    if (rotationAxis == up || rotationAxis == -up) {
        int sign = up.x + up.y + up.z;
        model = rotate(model, angle, (sign > 0 ? vec3(0.0f, 1.0f, 0.0f) : -vec3(0.0f, 1.0f, 0.0f)));
    }
    else if (rotationAxis == right || rotationAxis == -right) {
        int sign = right.x + right.y + right.z;
        model = rotate(model, angle, (sign > 0 ? vec3(1.0f, 0.0f, 0.0f) : -vec3(1.0f, 0.0f, 0.0f)));
    }
    else if (rotationAxis == front || rotationAxis == -front) {
        int sign = front.x + front.y + front.z;
        model = rotate(model, angle, (sign > 0 ? vec3(0.0f, 0.0f, 1.0f) : -vec3(0.0f, 0.0f, 1.0f)));
    }
    model = translate(model, -offset);
    //model = translate(model, -offset);
    //model = rotate(mat4(1.0f), angle, rotationAxis);
    //model = translate(model, offset);
}

void Cube::moveCube(vec3 offset) {
    this->offset = offset;
    model = translate(model, offset);
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

    if (rotationAxis == white || rotationAxis == -white) {
        vec3 tmp = (angle < 0 ? orange : -orange);
        orange = (angle < 0 ? -green : green);
        green = tmp;
    }
    else if (rotationAxis == green || rotationAxis == -green) {
        vec3 tmp = (angle > 0 ? white : -white);
        white = (angle > 0 ? -orange : orange);
        orange = tmp;
    }
    else if (rotationAxis == orange || rotationAxis == -orange) {
        vec3 tmp = (angle > 0 ? green : -green);
        green = (angle > 0 ? white : -white);
        white = tmp;
    }
}

Cube::Cube() {
    camera = nullptr;
}
