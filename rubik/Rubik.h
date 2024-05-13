//
// Created by KOSTJA on 10.02.2024.
//

#ifndef RUBIK_CUBE_RUBIK_H
#define RUBIK_CUBE_RUBIK_H

#include "cube/Cube.h"
#include "../camera/Camera.h"

#include <vector>


class Rubik {
    static std::vector<std::vector<std::vector<Cube>>> cubes;
public:

    static vec3 U;
    static vec3 D;
    static vec3 R;
    static vec3 L;
    static vec3 F;
    static vec3 B;

    static void init();
    static void drawRubik(Shader* shader);
    static void rotateLayer(vec3 layer, GLfloat angle);
    static void updateVector(vec3 layer, GLfloat angle);
    static Cube* getCube(vec3 pos);

};


#endif //RUBIK_CUBE_RUBIK_H
