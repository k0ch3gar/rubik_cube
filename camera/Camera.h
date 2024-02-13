//
// Created by KOSTJA on 10.02.2024.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
using namespace glm;


class Camera {
public:
    void updateVectors();

    vec3 eye;
    vec3 up;
    vec3 object;

    float fov;
    float distance;
    float pitch;
    float yaw;

    vec3 position;
    Camera(vec3 position, float fov, float distance);

    void setCameraAngle(float pitch, float yaw);

    mat4 getProjection();
    mat4 getView();
};



#endif //CAMERA_H
