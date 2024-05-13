//
// Created by KOSTJA on 12.02.2024.
//

#include "FirstLayer.h"

void FirstLayer::buildWhiteEdges(int ind) {

    vec3 pos = BasicAlgorithm::findCube(ind);
    Cube* cube = Rubik::getCube(pos);
    if (pos.y != 1 && (cube->getVector(Rubik::U) != Rubik::U && cube->getVector(Rubik::U) != Rubik::D)) {
        Rotation::rotateLayer(cube->getVector(Rubik::U), 90.0f);
        pos = BasicAlgorithm::findCube(ind);
        cube = Rubik::getCube(pos);

        Rotation::rotateLayer(BasicAlgorithm::getIndVec(cube, ind), 90.0f);
        pos = BasicAlgorithm::findCube(ind);
        cube = Rubik::getCube(pos);
    }

    while (cube->getVector(Rubik::U) != Rubik::D) {

        Rotation::rotateLayer(BasicAlgorithm::getIndVec(cube, ind), 90.0f);
        pos = BasicAlgorithm::findCube( ind);
        cube = Rubik::getCube(pos);
    }

    if (ind == 7 || ind == 25) {
        while (cube->getVector(Rubik::R) != Rubik::R) {
            Rotation::rotateLayer( cube->getVector(Rubik::U), 90.0f);
            pos = BasicAlgorithm::findCube(ind);
            cube = Rubik::getCube(pos);
        }
    }
    else {
        while (cube->getVector(Rubik::F) != Rubik::F) {
            Rotation::rotateLayer( cube->getVector(Rubik::U), 90.0f);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);
        }
    }

    while (cube->getVector(Rubik::U) != Rubik::U) {
        Rotation::rotateLayer( BasicAlgorithm::getIndVec(cube, ind), 90.0f);
        pos = BasicAlgorithm::findCube( ind);
        cube = Rubik::getCube(pos);
    }
}

bool FirstLayer::isWhiteCrossCorrect() {
    vec3 pos = BasicAlgorithm::findCube( 7);
    Cube* cube = Rubik::getCube(pos);
    if (!(cube->getVector(Rubik::U) == Rubik::U && pos == vec3(0, 2, 1))) {
        return false;
    }
    pos = BasicAlgorithm::findCube( 15);
    cube = Rubik::getCube(pos);
    if (!(cube->getVector(Rubik::U) == Rubik::U && pos == vec3(1, 2, 0))) {
        return false;
    }
    pos = BasicAlgorithm::findCube(17);
    cube = Rubik::getCube(pos);
    if (!(cube->getVector(Rubik::U) == Rubik::U && pos == vec3(1, 2, 2))) {
        return false;
    }
    pos = BasicAlgorithm::findCube(25);
    cube = Rubik::getCube(pos);
    if (!(cube->getVector(Rubik::U) == Rubik::U && pos == vec3(2, 2, 1))) {
        return false;
    }

    return true;
}

void FirstLayer::buildWhiteCorners(int ind) {
    vec3 pos = BasicAlgorithm::findCube(ind);
    Cube* cube = Rubik::getCube(pos);
    vec3 axisR, axisU = Rubik::D;
    if (pos.y == 2) {
        if (pos.x == pos.z) {
            axisR = (pos.x == 2 ? Rubik::F : Rubik::B);
        } else {
            axisR = (pos.x == 2 ? Rubik::R : Rubik::L);
        }
        BasicAlgorithm::pifPaf(axisR, axisU);
        pos = BasicAlgorithm::findCube(ind);
        cube = Rubik::getCube(pos);
    }
    vec3 rPos = BasicAlgorithm::getIndVec(cube, ind);
    while (pos.x != rPos.x || pos.z != rPos.z) {
        Rotation::rotateLayer( Rubik::D, 90.0f);
        pos = BasicAlgorithm::findCube( ind);
        cube = Rubik::getCube(pos);
    }
    if (rPos.x == rPos.z) {
        axisR = (rPos.x == 2 ? Rubik::F : Rubik::B);
    } else {
        axisR = (rPos.x == 2 ? Rubik::R : Rubik::L);
    }
    axisU = Rubik::D;
    while (cube->getVector(Rubik::U) != Rubik::U) {
        BasicAlgorithm::pifPaf( axisR, axisU);
        pos = BasicAlgorithm::findCube( ind);
        cube = Rubik::getCube(pos);
    }
}
