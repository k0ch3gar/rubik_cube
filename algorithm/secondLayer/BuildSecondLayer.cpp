//
// Created by KOSTJA on 13.02.2024.
//

#include "BuildSecondLayer.h"

void BuildSecondLayer::buildSecondEdges(int ind) {
    vec3 pos = BasicAlgorithm::findCube( ind);
    vec3 axisR, axisL, axisF, axisU = Rubik::D;
    if (pos.y == 1) {
        if (pos.x == pos.z) {
            axisR = (pos.x == 2 ? Rubik::F : -Rubik::F);
            axisF = (pos.z == 2 ? Rubik::R : Rubik::L);
        } else {
            axisR = (pos.x == 2 ? Rubik::R : Rubik::L);
            axisF = (pos.z == 2 ? Rubik::F : -Rubik::F);
        }

        BasicAlgorithm::secondEdgePlacementR( axisR, axisU, axisF);
    }
    pos = BasicAlgorithm::findCube( ind);
    Cube* cube = Rubik::getCube(pos);
    if (ind == 3) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != Rubik::F) {
            Rotation::rotateLayer( Rubik::D, 90.0f);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
        if (cube->getVector(Rubik::F) == Rubik::F) {
            axisL = Rubik::L;
            axisF = Rubik::B;
            BasicAlgorithm::secondEdgePlacementL( axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
        else {
            axisR = Rubik::B;
            axisF = Rubik::L;
            BasicAlgorithm::secondEdgePlacementR( axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
    }
    if (ind == 5) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != Rubik::F) {
            Rotation::rotateLayer( Rubik::D, 90.0f);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
        if (cube->getVector(Rubik::F) != Rubik::F) {
            axisL = Rubik::F;
            axisF = Rubik::L;
            BasicAlgorithm::secondEdgePlacementL( axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
        else {
            axisR = Rubik::L;
            axisF = Rubik::F;
            BasicAlgorithm::secondEdgePlacementR( axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
    }
    if (ind == 21) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != Rubik::F) {
            Rotation::rotateLayer( Rubik::D, 90.0f);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
        if (cube->getVector(Rubik::F) != Rubik::F) {
            axisL = Rubik::B;
            axisF = Rubik::R;
            BasicAlgorithm::secondEdgePlacementL( axisL, axisU, axisF);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
        else {
            axisR = Rubik::R;
            axisF = Rubik::B;
            BasicAlgorithm::secondEdgePlacementR( axisR, axisU, axisF);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
    }
    if (ind == 23) {
        while (cube->getVector(Rubik::R) != Rubik::R && cube->getVector(Rubik::F) != Rubik::F) {
            Rotation::rotateLayer( Rubik::D, 90.0f);
            pos = BasicAlgorithm::findCube( ind);
            cube = Rubik::getCube(pos);

        }
        if (cube->getVector(Rubik::F) == Rubik::F) {
            axisL = Rubik::Rubik::R;
            axisF = Rubik::F;
            BasicAlgorithm::secondEdgePlacementL( axisL, axisU, axisF);
        }
        else {
            axisR = Rubik::F;
            axisF = Rubik::Rubik::R;
            BasicAlgorithm::secondEdgePlacementR( axisR, axisU, axisF);
        }
    }
}

