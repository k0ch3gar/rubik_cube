//
// Created by KOSTJA on 10.02.2024.
//

#include "Camera.h"

#include "../window/Window.h"
#include "glm/gtx/rotate_vector.hpp"
#include <cmath>

void Camera::updateVectors() {
    position.x = sin(yaw) * cos(pitch) * distance;
    position.y = sin(pitch) * distance;
    position.z = cos(yaw) * cos(pitch) * distance;
    eye = vec3(vec4(0, 0, -1, 1));
    object = vec3(0, 0, 0);
    up = vec3(0, cos(pitch), 0);
}

Camera::Camera(vec3 position, float fov, float distance) : position(position), fov(fov), distance(distance) {
    this->pitch = 0.0f;
    this->yaw = 0.0f;
    updateVectors();
}

void Camera::setCameraAngle(float pitch, float yaw) {
    this->pitch = pitch;
    this->yaw = yaw;
    updateVectors();
}

mat4 Camera::getProjection() {
    float aspect = (float)Window::width / (float)Window::height;
    return glm::perspective(fov, aspect, 1.0f, 100.0f);
}

mat4 Camera::getView() {
    return glm::lookAt(position, object, up);
}

