//
// Created by KOSTJA on 12.02.2024.
//

#include "FirstLayer.h"

void FirstLayer::buildWhiteEdges(Camera* camera, Rubik *rubik, int ind) {

    vec3 pos = BasicAlgorithm::findCube(*rubik, ind);
    //std::cout << pos.x << ' ' << pos.y << ' ' << pos.z << '\n';
    Cube* cube = &rubik->cubes[pos.x][pos.y][pos.z];
    if (pos.y != 1 && (cube->up != vec3(0.0f, 1.0f, 0.0f) && cube->up != vec3(0.0f, -1.0f, 0.0f))) {
        Rotation::rotateLayer(camera, rubik, cube->up, 90.0f);
        pos = BasicAlgorithm::findCube(*rubik, ind);
        cube = &rubik->cubes[pos.x][pos.y][pos.z];

        Rotation::rotateLayer(camera, rubik, BasicAlgorithm::getIndVec(cube, ind), 90.0f);
        pos = BasicAlgorithm::findCube(*rubik, ind);
        cube = &rubik->cubes[pos.x][pos.y][pos.z];
    }

    while (cube->up != vec3(0.0f, -1.0f, 0.0f)) {

        Rotation::rotateLayer(camera, rubik, BasicAlgorithm::getIndVec(cube, ind), 90.0f);
        pos = BasicAlgorithm::findCube(*rubik, ind);
        cube = &rubik->cubes[pos.x][pos.y][pos.z];
    }

    if (ind == 7 || ind == 25) {
        while (cube->right != vec3(1.0f, 0.0f, 0.0f)) {
            Rotation::rotateLayer(camera, rubik, cube->up, 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
    }
    else {
        while (cube->front != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, cube->up, 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
    }

    while (cube->up != vec3(0.0f, 1.0f, 0.0f)) {
        Rotation::rotateLayer(camera, rubik, BasicAlgorithm::getIndVec(cube, ind), 90.0f);
        pos = BasicAlgorithm::findCube(*rubik, ind);
        cube = &rubik->cubes[pos.x][pos.y][pos.z];
    }
}

bool FirstLayer::isWhiteCrossCorrect(Rubik *rubik) {
    vec3 pos = BasicAlgorithm::findCube(*rubik, 7);
    Cube* cube = &rubik->cubes[pos.x][pos.y][pos.z];
    if (!(cube->up == vec3(0.0f, 1.0f, 0.0f) && pos == vec3(0, 2, 1))) {
        return false;
    }
    pos = BasicAlgorithm::findCube(*rubik, 15);
    cube = &rubik->cubes[pos.x][pos.y][pos.z];
    if (!(cube->up == vec3(0.0f, 1.0f, 0.0f) && pos == vec3(1, 2, 0))) {
        return false;
    }
    pos = BasicAlgorithm::findCube(*rubik, 17);
    cube = &rubik->cubes[pos.x][pos.y][pos.z];
    if (!(cube->up == vec3(0.0f, 1.0f, 0.0f) && pos == vec3(1, 2, 2))) {
        return false;
    }
    pos = BasicAlgorithm::findCube(*rubik, 25);
    cube = &rubik->cubes[pos.x][pos.y][pos.z];
    if (!(cube->up == vec3(0.0f, 1.0f, 0.0f) && pos == vec3(2, 2, 1))) {
        return false;
    }

    return true;
}

void FirstLayer::buildWhiteLayer(Camera *camera, Rubik *rubik, int ind) {
    vec3 pos = BasicAlgorithm::findCube(*rubik, ind);
    Cube* cube = &rubik->cubes[pos.x][pos.y][pos.z];
    vec3 axisR, axisU = vec3(0.0f, -1.0f, 0.0f);
    if (pos.y == 2) {
        if (pos.x == pos.z) {
            axisR = (pos.x == 2 ? vec3(0.0f, 0.0f, 1.0f) : -vec3(0.0f, 0.0f, 1.0f));
        } else {
            axisR = (pos.x == 2 ? vec3(1.0f, 0.0f, 0.0f) : -vec3(1.0f, 0.0f, 0.0f));
        }
        BasicAlgorithm::pifPaf(camera, rubik, axisR, axisU);
        pos = BasicAlgorithm::findCube(*rubik, ind);
        cube = &rubik->cubes[pos.x][pos.y][pos.z];
    }
    vec3 rPos = BasicAlgorithm::getIndVec(cube, ind);
    //std::cout << rPos.x << ' ' << rPos.y << ' ' << rPos.z << '\n';
    while (pos.x != rPos.x || pos.z != rPos.z) {
        Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
        pos = BasicAlgorithm::findCube(*rubik, ind);
        cube = &rubik->cubes[pos.x][pos.y][pos.z];
    }
    if (rPos.x == rPos.z) {
        axisR = (rPos.x == 2 ? vec3(0.0f, 0.0f, 1.0f) : -vec3(0.0f, 0.0f, 1.0f));
    } else {
        axisR = (rPos.x == 2 ? vec3(1.0f, 0.0f, 0.0f) : -vec3(1.0f, 0.0f, 0.0f));
    }
    axisU = vec3(0.0f, -1.0f, 0.0f);
    while (cube->up != vec3(0.0f, 1.0f, 0.0f)) {
        BasicAlgorithm::pifPaf(camera, rubik, axisR, axisU);
        pos = BasicAlgorithm::findCube(*rubik, ind);
        cube = &rubik->cubes[pos.x][pos.y][pos.z];
    }
}
