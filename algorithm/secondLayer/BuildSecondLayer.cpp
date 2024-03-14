//
// Created by KOSTJA on 13.02.2024.
//

#include "BuildSecondEdges.h"

void BuildSecondEdges::buildSecondEdges(Camera *camera, Rubik *rubik, int ind) {
    vec3 pos = BasicAlgorithm::findCube(*rubik, ind);
    vec3 axisR, axisL, axisF, axisU = vec3(0.0f, -1.0f, 0.0f);
    if (pos.y == 1) {
        if (pos.x == pos.z) {
            axisR = (pos.x == 2 ? vec3(0.0f, 0.0f, 1.0f) : -vec3(0.0f, 0.0f, 1.0f));
            axisF = (pos.z == 2 ? Rubik::R : Rubik::L);
        } else {
            axisR = (pos.x == 2 ? Rubik::R : Rubik::L);
            axisF = (pos.z == 2 ? vec3(0.0f, 0.0f, 1.0f) : -vec3(0.0f, 0.0f, 1.0f));
        }

        BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
    }
    pos = BasicAlgorithm::findCube(*rubik, ind);
    Cube* cube = rubik->getCube(pos);
    if (ind == 3) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
        if (cube->getVector(Rubik::F) == vec3(0.0f, 0.0f, 1.0f)) {
            axisL = vec3(-1.0f, 0.0f, 0.0f);
            axisF = vec3(0.0f, 0.0f, -1.0f);
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
        else {
            axisR = vec3(0.0f, 0.0f, -1.0f);
            axisF = vec3(-1.0f, 0.0f, 0.0f);
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
    }
    if (ind == 5) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
        if (cube->getVector(Rubik::F) != vec3(0.0f, 0.0f, 1.0f)) {
            axisL = vec3(0.0f, 0.0f, 1.0f);
            axisF = vec3(-1.0f, 0.0f, 0.0f);
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
        else {
            axisR = vec3(-1.0f, 0.0f, 0.0f);
            axisF = vec3(0.0f, 0.0f, 1.0f);
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
    }
    if (ind == 21) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
        if (cube->getVector(Rubik::F) != vec3(0.0f, 0.0f, 1.0f)) {
            axisL = vec3(0.0f, 0.0f, -1.0f);
            axisF = Rubik::R;
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
        else {
            axisR = Rubik::R;
            axisF = vec3(0.0f, 0.0f, -1.0f);
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
    }
    if (ind == 23) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = rubik->getCube(pos);

        }
        if (cube->getVector(Rubik::F) == vec3(0.0f, 0.0f, 1.0f)) {
            axisL = Rubik::Rubik::R;
            axisF = vec3(0.0f, 0.0f, 1.0f);
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
        }
        else {
            axisR = vec3(0.0f, 0.0f, 1.0f);
            axisF = Rubik::Rubik::R;
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
        }
    }
}

