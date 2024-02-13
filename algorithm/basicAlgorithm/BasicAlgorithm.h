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
    //Camera* camera;
    //Rubik* rubik;
public:

    static void pifPaf(Camera* camera, Rubik* rubik, vec3 axisR, vec3 axisU);
    static void secondEdgePlacementR(Camera* camera, Rubik* rubik, vec3 axisR, vec3 axisU, vec3 axisF);
    static void secondEdgePlacementL(Camera* camera, Rubik* rubik, vec3 axisL, vec3 axisU, vec3 axisF);
    static void yellowEdgesFlip(Camera* camera, Rubik* rubik, vec3 axisR, vec3 axisU, vec3 axisF, int type);
    static void moveYellowEdges(Camera* camera, Rubik* rubik, vec3 axisR, vec3 axisU);
    static void moveYellowCorners(Camera* camera, Rubik* rubik, vec3 axisR, vec3 axisU, vec3 axisL);
    static vec3 findCube(Rubik& rubik, int index);
    static vec3 getIndVec(Cube* cube, int ind);
};

#endif
