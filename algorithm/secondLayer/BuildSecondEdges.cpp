//
// Created by KOSTJA on 13.02.2024.
//

#include "BuildSecondEdges.h"

void BuildSecondEdges::buildSecondEdges(Camera *camera, Rubik *rubik, int ind) {
    vec3 pos = BasicAlgorithm::findCube(*rubik, ind);
    Cube* cube = &rubik->cubes[pos.x][pos.y][pos.z];
    vec3 axisR, axisL, axisF, axisU = vec3(0.0f, -1.0f, 0.0f);
    if (pos.y == 1) {
        if (pos.x == pos.z) {
            axisR = (pos.x == 2 ? vec3(0.0f, 0.0f, 1.0f) : -vec3(0.0f, 0.0f, 1.0f));
            axisF = (pos.z == 2 ? vec3(1.0f, 0.0f, 0.0f) : -vec3(1.0f, 0.0f, 0.0f));
        } else {
            axisR = (pos.x == 2 ? vec3(1.0f, 0.0f, 0.0f) : -vec3(1.0f, 0.0f, 0.0f));
            axisF = (pos.z == 2 ? vec3(0.0f, 0.0f, 1.0f) : -vec3(0.0f, 0.0f, 1.0f));
        }

        BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
    }
    pos = BasicAlgorithm::findCube(*rubik, ind);
    cube = &rubik->cubes[pos.x][pos.y][pos.z];
    if (ind == 3) {
        while (cube->right != vec3(1.0f, 0.0f, 0.0f) && cube->front != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        if (cube->front == vec3(0.0f, 0.0f, 1.0f)) {
            axisL = vec3(-1.0f, 0.0f, 0.0f);
            axisF = vec3(0.0f, 0.0f, -1.0f);
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        else {
            axisR = vec3(0.0f, 0.0f, -1.0f);
            axisF = vec3(-1.0f, 0.0f, 0.0f);
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
    }
    if (ind == 5) {
        while (cube->right != vec3(1.0f, 0.0f, 0.0f) && cube->front != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        if (cube->front != vec3(0.0f, 0.0f, 1.0f)) {
            axisL = vec3(0.0f, 0.0f, 1.0f);
            axisF = vec3(-1.0f, 0.0f, 0.0f);
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        else {
            axisR = vec3(-1.0f, 0.0f, 0.0f);
            axisF = vec3(0.0f, 0.0f, 1.0f);
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
    }
    if (ind == 21) {
        while (cube->right != vec3(1.0f, 0.0f, 0.0f) && cube->front != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        if (cube->front != vec3(0.0f, 0.0f, 1.0f)) {
            axisL = vec3(0.0f, 0.0f, -1.0f);
            axisF = vec3(1.0f, 0.0f, 0.0f);
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        else {
            axisR = vec3(1.0f, 0.0f, 0.0f);
            axisF = vec3(0.0f, 0.0f, -1.0f);
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
    }
    if (ind == 23) {
        while (cube->right != vec3(1.0f, 0.0f, 0.0f) && cube->front != vec3(0.0f, 0.0f, 1.0f)) {
            Rotation::rotateLayer(camera, rubik, vec3(0.0f, -1.0f, 0.0f), 90.0f);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        if (cube->front == vec3(0.0f, 0.0f, 1.0f)) {
            axisL = vec3(1.0f, 0.0f, 0.0f);
            axisF = vec3(0.0f, 0.0f, 1.0f);
            BasicAlgorithm::secondEdgePlacementL(camera, rubik, axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
        else {
            axisR = vec3(0.0f, 0.0f, 1.0f);
            axisF = vec3(1.0f, 0.0f, 0.0f);
            BasicAlgorithm::secondEdgePlacementR(camera, rubik, axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube(*rubik, ind);
            cube = &rubik->cubes[pos.x][pos.y][pos.z];
        }
    }
}

void BuildSecondEdges::moveYellowEdges(Camera *camera, Rubik *rubik) {
    vec3 pos = BasicAlgorithm::findCube(*rubik, 1);
    Cube* cube1 = &rubik->cubes[pos.x][pos.y][pos.z];
    while (pos != vec3(0, 0, 1)) {
        Rotation::rotateLayer(camera, rubik, -cube1->up, 90.0f);
        pos = BasicAlgorithm::findCube(*rubik, 1);
        cube1 = &rubik->cubes[pos.x][pos.y][pos.z];
    }
    pos = BasicAlgorithm::findCube(*rubik, 9);
    Cube* cube9 = &rubik->cubes[pos.x][pos.y][pos.z];
    while (pos != vec3(1, 0, 0)) {
        BasicAlgorithm::moveYellowEdges(camera, rubik, vec3(0, 0, 1), -vec3(0, 1, 0));
        BasicAlgorithm::moveYellowEdges(camera, rubik, vec3(1, 0, 0), -vec3(0, 1, 0));
        pos = BasicAlgorithm::findCube(*rubik, 9);
        cube9 = &rubik->cubes[pos.x][pos.y][pos.z];
    }
    pos = BasicAlgorithm::findCube(*rubik, 19);
    Cube* cube19 = &rubik->cubes[pos.x][pos.y][pos.z];
    if (pos != vec3(2, 0, 1)) {
        BasicAlgorithm::moveYellowEdges(camera, rubik, vec3(0, 0, 1), -vec3(0, 1, 0));
    }
}

void BuildSecondEdges::yellowEdgesFlips(Camera *camera, Rubik *rubik) {

    vec3 pos = BasicAlgorithm::findCube(*rubik, 1);
    Cube* cube1 = &rubik->cubes[pos.x][pos.y][pos.z];
    pos = BasicAlgorithm::findCube(*rubik, 9);
    Cube* cube9 = &rubik->cubes[pos.x][pos.y][pos.z];
    pos = BasicAlgorithm::findCube(*rubik, 11);
    Cube* cube11 = &rubik->cubes[pos.x][pos.y][pos.z];
    pos = BasicAlgorithm::findCube(*rubik, 19);
    Cube* cube19 = &rubik->cubes[pos.x][pos.y][pos.z];
    while (cube1->up != vec3(0.0f, 1.0f, 0.0f) || cube19->up != vec3(0.0f, 1.0f, 0.0f) || cube9->up != vec3(0.0f, 1.0f, 0.0f) || cube11->up != vec3(0.0f, 1.0f, 0.0f)) {
        BasicAlgorithm::yellowEdgesFlip(camera, rubik, vec3(0.0f, 0.0f, 1.0f), vec3(0.0f, -1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f), 1);
        if (cube1->up != vec3(0.0f, 1.0f, 0.0f) || cube19->up != vec3(0.0f, 1.0f, 0.0f) || cube9->up != vec3(0.0f, 1.0f, 0.0f) || cube11->up != vec3(0.0f, 1.0f, 0.0f)) {
            BasicAlgorithm::yellowEdgesFlip(camera, rubik, vec3(1.0f, 0.0f, 0.0f), vec3(0.0f, -1.0f, 0.0f), -vec3(0.0f, 0.0f, 1.0f), 1);
        }
        else {
            break;
        }
    }

}

void BuildSecondEdges::moveYellowCorners(Camera *camera, Rubik *rubik) {
    vec3 pos = BasicAlgorithm::findCube(*rubik, 0);
    Cube* cube0 = &rubik->cubes[pos.x][pos.y][pos.z];
    if (pos == vec3(0,0,0)) {
        pos = BasicAlgorithm::findCube(*rubik, 2);
        Cube* cube2 = &rubik->cubes[pos.x][pos.y][pos.z];
        while (pos != vec3(0,0,2)) {
            BasicAlgorithm::moveYellowCorners(camera, rubik, -vec3(0.0f, 0.0f, 1.0f), -vec3(0.0f, 1.0f, 0.0f), vec3(0.0f, 0.0f, 1.0f));
            pos = BasicAlgorithm::findCube(*rubik, 2);
        }
        return;
    }
    pos = BasicAlgorithm::findCube(*rubik, 2);
    Cube* cube2 = &rubik->cubes[pos.x][pos.y][pos.z];
    if (pos == vec3(0,0,2)) {
        pos = BasicAlgorithm::findCube(*rubik, 0);
        Cube* cube0 = &rubik->cubes[pos.x][pos.y][pos.z];
        while (pos != vec3(0,0,0)) {
            BasicAlgorithm::moveYellowCorners(camera, rubik, -vec3(1.0f, 0.0f, 0.0f), -vec3(0.0f, 1.0f, 0.0f), vec3(1.0f, 0.0f, 0.0f));
            pos = BasicAlgorithm::findCube(*rubik, 0);
        }
        return;
    }
    pos = BasicAlgorithm::findCube(*rubik, 18);
    Cube* cube18 = &rubik->cubes[pos.x][pos.y][pos.z];
    if (pos == vec3(2,0,0)) {
        pos = BasicAlgorithm::findCube(*rubik, 2);
        Cube* cube2 = &rubik->cubes[pos.x][pos.y][pos.z];
        while (pos != vec3(0,0,2)) {
            BasicAlgorithm::moveYellowCorners(camera, rubik, vec3(1.0f, 0.0f, 0.0f), -vec3(0.0f, 1.0f, 0.0f), -vec3(1.0f, 0.0f, 0.0f));
            pos = BasicAlgorithm::findCube(*rubik, 2);
        }
        return;
    }
    pos = BasicAlgorithm::findCube(*rubik, 20);
    Cube* cube20 = &rubik->cubes[pos.x][pos.y][pos.z];
    if (pos == vec3(2,0,2)) {
        pos = BasicAlgorithm::findCube(*rubik, 2);
        Cube* cube2 = &rubik->cubes[pos.x][pos.y][pos.z];
        while (pos != vec3(0,0,2)) {
            BasicAlgorithm::moveYellowCorners(camera, rubik, vec3(0.0f, 0.0f, 1.0f), -vec3(0.0f, 1.0f, 0.0f), -vec3(0.0f, 0.0f, 1.0f));
            pos = BasicAlgorithm::findCube(*rubik, 2);
        }
        return;
    }
    pos = BasicAlgorithm::findCube(*rubik, 2);
    cube2 = &rubik->cubes[pos.x][pos.y][pos.z];
    BasicAlgorithm::moveYellowCorners(camera, rubik, vec3(0.0f, 0.0f, 1.0f), -vec3(0.0f, 1.0f, 0.0f), -vec3(0.0f, 0.0f, 1.0f));


    BuildSecondEdges::moveYellowCorners(camera, rubik);
}

void BuildSecondEdges::rotateYellowCorners(Camera *camera, Rubik *rubik) {
    vec3 pos = BasicAlgorithm::findCube(*rubik, 0);
    Cube* cube0 = &rubik->cubes[pos.x][pos.y][pos.z];
    while (cube0->up != vec3(0,1,0)) {
        BasicAlgorithm::pifPaf(camera, rubik, -vec3(1,0,0), vec3(0,1,0));
        pos = BasicAlgorithm::findCube(*rubik, 0);
        cube0 = &rubik->cubes[pos.x][pos.y][pos.z];
    }
    Rotation::rotateLayer(camera, rubik, -vec3(0,1,0), -90.0f);
    pos = BasicAlgorithm::findCube(*rubik, 2);
    Cube* cube2 = &rubik->cubes[pos.x][pos.y][pos.z];
    while (cube2->up != vec3(0,1,0)) {
        BasicAlgorithm::pifPaf(camera, rubik, -vec3(1,0,0), vec3(0,1,0));
        pos = BasicAlgorithm::findCube(*rubik, 2);
        cube2 = &rubik->cubes[pos.x][pos.y][pos.z];
    }
    Rotation::rotateLayer(camera, rubik, -vec3(0,1,0), -90.0f);
    pos = BasicAlgorithm::findCube(*rubik, 20);
    Cube* cube20 = &rubik->cubes[pos.x][pos.y][pos.z];
    while (cube20->up != vec3(0,1,0)) {
        BasicAlgorithm::pifPaf(camera, rubik, -vec3(1,0,0), vec3(0,1,0));
        pos = BasicAlgorithm::findCube(*rubik, 20);
        cube20 = &rubik->cubes[pos.x][pos.y][pos.z];
    }

    Rotation::rotateLayer(camera, rubik, -vec3(0,1,0), -90.0f);
    pos = BasicAlgorithm::findCube(*rubik, 18);
    Cube* cube18 = &rubik->cubes[pos.x][pos.y][pos.z];
    while (cube18->up != vec3(0,1,0)) {
        BasicAlgorithm::pifPaf(camera, rubik, -vec3(1,0,0), vec3(0,1,0));
        pos = BasicAlgorithm::findCube(*rubik, 18);
        cube18 = &rubik->cubes[pos.x][pos.y][pos.z];
    }
    Rotation::rotateLayer(camera, rubik, -vec3(0,1,0), -90.0f);
}
