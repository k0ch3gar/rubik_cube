//
// Created by KOSTJA on 12.02.2024.
//

#ifndef RUBIK_CUBE_ROTATION_H
#define RUBIK_CUBE_ROTATION_H

#include "basicAlgorithm/BasicAlgorithm.h"

class Rotation {

public:

    static void rotateLayer(Camera* camera, Rubik* rubik, vec3 rotationAxis, GLfloat angle);
};


#endif //RUBIK_CUBE_ROTATION_H
