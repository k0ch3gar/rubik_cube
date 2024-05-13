//
// Created by KOSTJA on 11.02.2024.
//

#include "BasicAlgorithm.h"

void BasicAlgorithm::pifPaf(vec3 axisR, vec3 axisU) {
    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign2 = axisU.x + axisU.y + axisU.z;
    Rotation::rotateLayer( axisR, -90.0f * sign1);
    Rotation::rotateLayer( axisU, -90.0f * sign2);
    Rotation::rotateLayer( axisR, 90.0f * sign1);
    Rotation::rotateLayer( axisU, 90.0f * sign2);

}

vec3 BasicAlgorithm::findCube(int index) {

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                if (Rubik::getCube(vec3(x,y,z))->index == index) {
                    return vec3(x, y, z);
                }
            }
        }
    }
    return vec3(1, 1, 1);
}

vec3 BasicAlgorithm::getIndVec(Cube *cube, int ind) {
    if (ind == 7) {
        return -cube->getVector(Rubik::R);
    }
    if (ind == 25) {
        return cube->getVector(Rubik::R);
    }
    if (ind == 15) {
        return -cube->getVector(Rubik::F);
    }
    if (ind == 17) {
        return cube->getVector(Rubik::F);
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

void BasicAlgorithm::secondEdgePlacementR(vec3 axisR, vec3 axisU, vec3 axisF) {
    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign2 = axisU.x + axisU.y + axisU.z;
    int sign3 = axisF.x + axisF.y + axisF.z;

    Rotation::rotateLayer(axisU, -90.0f * sign2);
    Rotation::rotateLayer( axisR, -90.0f * sign1);
    Rotation::rotateLayer( axisU, 90.0f * sign2);
    Rotation::rotateLayer( axisR, 90.0f * sign1);
    Rotation::rotateLayer( axisU, 90.0f * sign2);
    Rotation::rotateLayer( axisF, 90.0f * sign3);
    Rotation::rotateLayer( axisU, -90.0f * sign2);
    Rotation::rotateLayer( axisF, -90.0f * sign3);

}

void BasicAlgorithm::secondEdgePlacementL( vec3 axisL, vec3 axisU, vec3 axisF) {
    int sign1 = axisL.x + axisL.y + axisL.z;
    int sign2 = axisU.x + axisU.y + axisU.z;
    int sign3 = axisF.x + axisF.y + axisF.z;

    Rotation::rotateLayer( axisU, 90.0f * sign2);
    Rotation::rotateLayer( axisL, 90.0f * sign1);
    Rotation::rotateLayer( axisU, -90.0f * sign2);
    Rotation::rotateLayer( axisL, -90.0f * sign1);
    Rotation::rotateLayer( axisU, -90.0f * sign2);
    Rotation::rotateLayer( axisF, -90.0f * sign3);
    Rotation::rotateLayer( axisU, 90.0f * sign2);
    Rotation::rotateLayer( axisF, 90.0f * sign3);
}

void BasicAlgorithm::yellowEdgesFlip(vec3 axisR, vec3 axisU, vec3 axisF, int type) {

    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign3 = axisF.x + axisF.y + axisF.z;

    Rotation::rotateLayer( axisF, -90 * sign3);
    if (type == 2) {
        Rotation::rotateLayer( axisR, -90 * sign1);
        Rotation::rotateLayer( axisU, 90);
        Rotation::rotateLayer( axisR, 90 * sign1);
        Rotation::rotateLayer( axisU, -90);
    }
    else {
        Rotation::rotateLayer( axisU, 90);
        Rotation::rotateLayer( axisR, -90 * sign1);
        Rotation::rotateLayer( axisU, -90);
        Rotation::rotateLayer( axisR, 90 * sign1);
    }
    Rotation::rotateLayer( axisF, 90 * sign3);
}

void BasicAlgorithm::moveYellowEdges( vec3 axisR, vec3 axisU) {
    int sign1 = axisR.x + axisR.y + axisR.z;

    Rotation::rotateLayer( axisU, 90);
    Rotation::rotateLayer( axisR, -90 * sign1);
    Rotation::rotateLayer( axisU, 90);
    Rotation::rotateLayer( axisR, 90 * sign1);
    Rotation::rotateLayer( axisU, 90);
    Rotation::rotateLayer( axisR, -90 * sign1);
    Rotation::rotateLayer( axisU, 90);
    Rotation::rotateLayer( axisU, 90);
    Rotation::rotateLayer( axisR, 90 * sign1);
}

void BasicAlgorithm::moveYellowCorners( vec3 axisR, vec3 axisU, vec3 axisL) {
    int sign1 = axisR.x + axisR.y + axisR.z;
    int sign2 = axisL.x + axisL.y + axisL.z;

    Rotation::rotateLayer( axisU, 90);
    Rotation::rotateLayer( axisR, -90 * sign1);
    Rotation::rotateLayer( axisU, -90);
    Rotation::rotateLayer( axisL, 90 * sign2);
    Rotation::rotateLayer( axisU, 90);
    Rotation::rotateLayer( axisR, 90 * sign1);
    Rotation::rotateLayer( axisU, -90);
    Rotation::rotateLayer( axisL, -90 * sign2);
}


