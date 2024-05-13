//
// Created by KOSTJA on 10.02.2024.
//

#include "Camera.h"

#include "../window/Window.h"
#include "glm/gtx/rotate_vector.hpp"
#include <cmath>

vec3 Camera::up;
vec3 Camera::object;
vec3 Camera::position;

float Camera::fov;
float Camera::distance;
float Camera::pitch;
float Camera::yaw;

float Camera::speed = 5.0f;

void Camera::updateVectors() {
    position.x = sin(yaw) * cos(pitch) * distance;
    position.y = sin(pitch) * distance;
    position.z = cos(yaw) * cos(pitch) * distance;
    object = vec3(0, 0, 0);
    up = vec3(0, cos(pitch), 0);
}



void Camera::setCameraAngle(float dpitch, float dyaw) {
    pitch += dpitch * speed;
    yaw += dyaw * speed;
    updateVectors();
}

mat4 Camera::getProjection() {
    float aspect = (float)Window::width / (float)Window::height;
    return glm::perspective(fov, aspect, 1.0f, 100.0f);
}

mat4 Camera::getView() {
    return glm::lookAt(position, object, up);
}

void Camera::setCameraSpeed(float dspeed) {
    speed += dspeed;
    speed = std::max(speed, 0.5f);
}

void Camera::init(vec3 dposition, float dfov, float ddistance) {
    position = dposition;
    fov = dfov;
    distance = ddistance;
}

