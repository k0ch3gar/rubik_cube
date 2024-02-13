//
// Created by KOSTJA on 10.02.2024.
//

#ifndef RUBIK_CUBE_RUBIK_H
#define RUBIK_CUBE_RUBIK_H

#include "cube/Cube.h"
#include "../camera/Camera.h"

#include <vector>

class Rubik : Cube {
    Camera* camera;
public:
    std::vector<std::vector<std::vector<Cube>>> cubes;
    Rubik(Camera* camera);

    void drawRubik();
    void rotateLayer(vec3 layer, GLfloat angle);
    void updateVector(vec3 layer, GLfloat angle);

};


#endif //RUBIK_CUBE_RUBIK_H
