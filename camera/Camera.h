//
// Created by KOSTJA on 10.02.2024.
//

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
using namespace glm;


class Camera {
    static vec3 up;
    static vec3 object;
    static vec3 position;

    static float fov;
    static float distance;
    static float pitch;
    static float yaw;

    static float speed;
public:
    static void updateVectors();

    static void init(vec3 dposition, float dfov, float ddistance);
    static void setCameraAngle(float dpitch, float dyaw);
    static void setCameraSpeed(float dspeed);

    static mat4 getProjection();
    static mat4 getView();
};



#endif //CAMERA_H
