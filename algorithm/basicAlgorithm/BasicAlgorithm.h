//
// Created by KOSTJA on 11.02.2024.
//

#ifndef RUBIK_CUBE_BASICALGORITHM_H
#define RUBIK_CUBE_BASICALGORITHM_H

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../../window/Window.h"
#include "../../window/EventHandler.h"
#include "../../graphics/Shader.h"
#include "../../camera/Camera.h"
#include "../../rubik/Rubik.h"
#include "../Rotation.h"

class BasicAlgorithm {
public:
    static void pifPaf(vec3 axisR, vec3 axisU);
    static void secondEdgePlacementR(vec3 axisR, vec3 axisU, vec3 axisF);
    static void secondEdgePlacementL(vec3 axisL, vec3 axisU, vec3 axisF);
    static void yellowEdgesFlip(vec3 axisR, vec3 axisU, vec3 axisF, int type);
    static void moveYellowEdges(vec3 axisR, vec3 axisU);
    static void moveYellowCorners(vec3 axisR, vec3 axisU, vec3 axisL);
    static vec3 findCube(int index);
    static vec3 getIndVec(Cube* cube, int ind);
};

#endif
