//
// Created by KOSTJA on 20.02.2024.
//

#include "Scramble.h"
#include "../Rotation.h"
#include <random>

vec3 sides[] = {
        vec3(1.0f, 0.0f, 0.0f),
        vec3(0.0f, 1.0f, 0.0f),
        vec3(0.0f, 0.0f, 1.0f),
        vec3(-1.0f, 0.0f, 0.0f),
        vec3(0.0f, -1.0f, 0.0f),
        vec3(0.0f, 0.0f, -1.0f)
};

void Scramble::scrumbleRubik() {
    srand((unsigned)time(0));
    for (int i = 0; i < 20; i++) {
        int side = rand() % 6;
        Rotation::rotateLayer( sides[side], 90.0f);
    }
}
