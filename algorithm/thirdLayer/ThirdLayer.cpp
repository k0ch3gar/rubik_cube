//
// Created by KOSTJA on 25.02.2024.
//

#include "ThirdLayer.h"


void ThirdLayer::moveYellowEdges() {
    vec3 pos = BasicAlgorithm::findCube( 1);
    Cube* cube1 = Rubik::getCube(pos);
    while (pos != vec3(0, 0, 1)) {
        Rotation::rotateLayer( -cube1->getVector(Rubik::Rubik::U), 90.0f);
        pos = BasicAlgorithm::findCube( 1);
        cube1 = Rubik::getCube(pos);
    }
    pos = BasicAlgorithm::findCube( 9);
    while (pos != vec3(1, 0, 0)) {
        BasicAlgorithm::moveYellowEdges( vec3(0, 0, 1), -vec3(0, 1, 0));
        BasicAlgorithm::moveYellowEdges( vec3(1, 0, 0), -vec3(0, 1, 0));
        pos = BasicAlgorithm::findCube( 9);
    }
    pos = BasicAlgorithm::findCube( 19);
    if (pos != vec3(2, 0, 1)) {
        BasicAlgorithm::moveYellowEdges( vec3(0, 0, 1), -vec3(0, 1, 0));
    }
}

void ThirdLayer::yellowEdgesFlips() {

    vec3 pos = BasicAlgorithm::findCube( 1);
    Cube* cube1 = Rubik::getCube(pos);
    pos = BasicAlgorithm::findCube( 9);
    Cube* cube9 = Rubik::getCube(pos);
    pos = BasicAlgorithm::findCube( 11);
    Cube* cube11 = Rubik::getCube(pos);
    pos = BasicAlgorithm::findCube( 19);
    Cube* cube19 = Rubik::getCube(pos);
    while (cube1->getVector(Rubik::Rubik::U) != Rubik::U || cube19->getVector(Rubik::Rubik::U) != Rubik::U || cube9->getVector(Rubik::Rubik::U) != Rubik::U || cube11->getVector(Rubik::Rubik::U) != Rubik::U) {
        BasicAlgorithm::yellowEdgesFlip(Rubik::F, Rubik::D, Rubik::R, 1);
        if (cube1->getVector(Rubik::Rubik::U) != Rubik::U || cube19->getVector(Rubik::Rubik::U) != Rubik::U || cube9->getVector(Rubik::Rubik::U) != Rubik::U || cube11->getVector(Rubik::Rubik::U) != Rubik::U) {
            BasicAlgorithm::yellowEdgesFlip(Rubik::R, Rubik::D, Rubik::B, 1);
        }
        else {
            break;
        }
    }

}

void ThirdLayer::moveYellowCorners() {
    vec3 pos = BasicAlgorithm::findCube( 0);
    if (pos == vec3(0,0,0)) {
        pos = BasicAlgorithm::findCube( 2);
        while (pos != vec3(0,0,2)) {
            BasicAlgorithm::moveYellowCorners(Rubik::B, Rubik::D, Rubik::F);
            pos = BasicAlgorithm::findCube( 2);
        }
        return;
    }
    pos = BasicAlgorithm::findCube( 2);
    if (pos == vec3(0,0,2)) {
        pos = BasicAlgorithm::findCube( 0);
        while (pos != vec3(0,0,0)) {
            BasicAlgorithm::moveYellowCorners(Rubik::L, Rubik::D, Rubik::R);
            pos = BasicAlgorithm::findCube( 0);
        }
        return;
    }
    pos = BasicAlgorithm::findCube( 18);
    if (pos == vec3(2,0,0)) {
        pos = BasicAlgorithm::findCube( 2);
        while (pos != vec3(0,0,2)) {
            BasicAlgorithm::moveYellowCorners( Rubik::R, Rubik::D, Rubik::L);
            pos = BasicAlgorithm::findCube( 2);
        }
        return;
    }
    pos = BasicAlgorithm::findCube( 20);
    if (pos == vec3(2,0,2)) {
        pos = BasicAlgorithm::findCube( 2);
        while (pos != vec3(0,0,2)) {
            BasicAlgorithm::moveYellowCorners( Rubik::F, Rubik::D, Rubik::B);
            pos = BasicAlgorithm::findCube( 2);
        }
        return;
    }
    BasicAlgorithm::moveYellowCorners( Rubik::F, Rubik::D, Rubik::B);


    ThirdLayer::moveYellowCorners();
}

void ThirdLayer::rotateYellowCorners() {
    vec3 pos = BasicAlgorithm::findCube( 0);
    Cube* cube0 = Rubik::getCube(pos);
    while (cube0->getVector(Rubik::Rubik::U) != Rubik::U) {
        BasicAlgorithm::pifPaf( Rubik::L, Rubik::U);
        pos = BasicAlgorithm::findCube( 0);
        cube0 = Rubik::getCube(pos);
    }
    Rotation::rotateLayer( Rubik::D, -90.0f);
    pos = BasicAlgorithm::findCube( 2);
    Cube* cube2 = Rubik::getCube(pos);
    while (cube2->getVector(Rubik::Rubik::U) != Rubik::U) {
        BasicAlgorithm::pifPaf( Rubik::L, Rubik::U);
        pos = BasicAlgorithm::findCube( 2);
        cube2 = Rubik::getCube(pos);
    }
    Rotation::rotateLayer( Rubik::D, -90.0f);
    pos = BasicAlgorithm::findCube( 20);
    Cube* cube20 = Rubik::getCube(pos);
    while (cube20->getVector(Rubik::U) != Rubik::U) {
        BasicAlgorithm::pifPaf( Rubik::L, Rubik::U);
        pos = BasicAlgorithm::findCube( 20);
        cube20 = Rubik::getCube(pos);
    }

    Rotation::rotateLayer( Rubik::D, -90.0f);
    pos = BasicAlgorithm::findCube( 18);
    Cube* cube18 = Rubik::getCube(pos);
    while (cube18->getVector(Rubik::U) != Rubik::U) {
        BasicAlgorithm::pifPaf( Rubik::L, Rubik::U);
        pos = BasicAlgorithm::findCube( 18);
        cube18 = Rubik::getCube(pos);
    }
    Rotation::rotateLayer( Rubik::D, -90.0f);
}
