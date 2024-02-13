//
// Created by KOSTJA on 11.02.2024.
//

#include "BasicAlgorithm.h"
#include <iostream>

void BasicAlgorithm::pifPaf(Camera* camera, Rubik* rubik, vec3 axisR, vec3 axisU) {
    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign2 = axisU.x + axisU.y + axisU.z;
    Rotation::rotateLayer(camera, rubik, axisR, -90.0f * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, -90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisR, 90.0f * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, 90.0f * sign2);

}

vec3 BasicAlgorithm::findCube(Rubik &rubik, int index) {

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                if (rubik.cubes[x][y][z].index == index) {
                    //std::cout << x << ' ' << y << ' ' << z << '\n';
                    return vec3(x, y, z);
                }
            }
        }
    }
    return vec3(1, 1, 1);
}

vec3 BasicAlgorithm::getIndVec(Cube *cube, int ind) {
    if (ind == 7) {
        return -cube->right;
    }
    if (ind == 25) {
        return cube->right;
    }
    if (ind == 15) {
        return -cube->front;
    }
    if (ind == 17) {
        return cube->front;
    }
    if (ind == 6) {
        return vec3(0, 2, 0);
    }
    if (ind == 8) {
        return vec3(0, 2, 2);
    }
    if (ind == 24) {
        return vec3(2, 2, 0);
    }
    if (ind == 26) {
        return vec3(2, 2, 2);
    }
    return glm::vec3();
}

void BasicAlgorithm::secondEdgePlacementR(Camera *camera, Rubik *rubik, vec3 axisR, vec3 axisU, vec3 axisF) {
    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign2 = axisU.x + axisU.y + axisU.z;
    int sign3 = axisF.x + axisF.y + axisF.z;

    Rotation::rotateLayer(camera, rubik, axisU, -90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisR, -90.0f * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, 90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisR, 90.0f * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, 90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisF, 90.0f * sign3);
    Rotation::rotateLayer(camera, rubik, axisU, -90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisF, -90.0f * sign3);

}

void BasicAlgorithm::secondEdgePlacementL(Camera *camera, Rubik *rubik, vec3 axisL, vec3 axisU, vec3 axisF) {
    int sign1 = axisL.x + axisL.y + axisL.z;
    int sign2 = axisU.x + axisU.y + axisU.z;
    int sign3 = axisF.x + axisF.y + axisF.z;

    Rotation::rotateLayer(camera, rubik, axisU, 90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisL, 90.0f * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, -90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisL, -90.0f * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, -90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisF, -90.0f * sign3);
    Rotation::rotateLayer(camera, rubik, axisU, 90.0f * sign2);
    Rotation::rotateLayer(camera, rubik, axisF, 90.0f * sign3);
}

void BasicAlgorithm::yellowEdgesFlip(Camera *camera, Rubik *rubik, vec3 axisR, vec3 axisU, vec3 axisF, int type) {

    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign2 = axisU.x + axisU.y + axisU.z;
    int sign3 = axisF.x + axisF.y + axisF.z;

    Rotation::rotateLayer(camera, rubik, axisF, -90 * sign3);
    if (type == 2) {
        Rotation::rotateLayer(camera, rubik, axisR, -90 * sign1);
        Rotation::rotateLayer(camera, rubik, axisU, 90);
        Rotation::rotateLayer(camera, rubik, axisR, 90 * sign1);
        Rotation::rotateLayer(camera, rubik, axisU, -90);
    }
    else {
        Rotation::rotateLayer(camera, rubik, axisU, 90);
        Rotation::rotateLayer(camera, rubik, axisR, -90 * sign1);
        Rotation::rotateLayer(camera, rubik, axisU, -90);
        Rotation::rotateLayer(camera, rubik, axisR, 90 * sign1);
    }
    Rotation::rotateLayer(camera, rubik, axisF, 90 * sign3);
}

void BasicAlgorithm::moveYellowEdges(Camera *camera, Rubik *rubik, vec3 axisR, vec3 axisU) {
    int sign1 = axisR.x + axisR.y + axisR.z;

    Rotation::rotateLayer(camera, rubik, axisU, 90);
    Rotation::rotateLayer(camera, rubik, axisR, -90 * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, 90);
    Rotation::rotateLayer(camera, rubik, axisR, 90 * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, 90);
    Rotation::rotateLayer(camera, rubik, axisR, -90 * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, 90);
    Rotation::rotateLayer(camera, rubik, axisU, 90);
    Rotation::rotateLayer(camera, rubik, axisR, 90 * sign1);
}

void BasicAlgorithm::moveYellowCorners(Camera *camera, Rubik *rubik, vec3 axisR, vec3 axisU, vec3 axisL) {
    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign2 = axisL.x + axisL.y + axisL.z;

    Rotation::rotateLayer(camera, rubik, axisU, 90);
    Rotation::rotateLayer(camera, rubik, axisR, -90 * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, -90);
    Rotation::rotateLayer(camera, rubik, axisL, 90 * sign2);
    Rotation::rotateLayer(camera, rubik, axisU, 90);
    Rotation::rotateLayer(camera, rubik, axisR, 90 * sign1);
    Rotation::rotateLayer(camera, rubik, axisU, -90);
    Rotation::rotateLayer(camera, rubik, axisL, -90 * sign2);
}


