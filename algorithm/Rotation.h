//
// Created by KOSTJA on 12.02.2024.
//

#ifndef RUBIK_CUBE_ROTATION_H
#define RUBIK_CUBE_ROTATION_H

#include "basicAlgorithm/BasicAlgorithm.h"
#include "../logger/Logger.h"

class Rotation {
    static int rotationSpeed;
    static Shader* shader;
public:
    static void setShader(Shader* shader1);
    static void rotateLayer(vec3 rotationAxis, GLfloat angle);
    static void setRotationSpeed(int speed);
};


#endif //RUBIK_CUBE_ROTATION_H
