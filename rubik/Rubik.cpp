//
// Created by KOSTJA on 10.02.2024.
//

#include "Rubik.h"
#include <iostream>

Rubik::Rubik(Camera *camera) : camera(camera) {
    this->cubes = std::vector<std::vector<std::vector<Cube>>>(3, std::vector(3, std::vector(3, Cube(camera))));
    int index = 0;
    for (int x = -1; x < 2; x++) {
        for (int y = -1; y < 2; y++) {
            for (int z = -1; z < 2; z++) {
                cubes[x + 1][y + 1][z + 1].moveCube(vec3(x,y,z));
                cubes[x + 1][y + 1][z + 1].index = index++;

            }
        }
    }
}

void Rubik::drawRubik() {
    for (int x = -1; x < 2; x++) {
        for (int y = -1; y < 2; y++) {
            for (int z = -1; z < 2; z++) {
                cubes[x + 1][y + 1][z + 1].drawCube();
            }
        }
    }
}

void Rubik::rotateLayer(vec3 layer, GLfloat angle) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            int i;
            int j;
            int k;
            if (layer.x != 0) {
                i = layer.x + 1;
                j = x;
                k = y;
            }
            if (layer.y != 0) {
                i = x;
                j = layer.y + 1;
                k = y;
            }
            if (layer.z != 0) {
                i = x;
                j = y;
                k = layer.z + 1;
            }
            //printf("%d %d %d\n", i, j, k);
            cubes[i][j][k].rotateCube(angle, layer);
        }
    }
}

void Rubik::updateVector(vec3 layer, GLfloat angle) {
    std::vector buf(3, std::vector(3, Cube(camera)));
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            int i = x;
            int j = y;
            if (angle < 0.0f) {
                i = 2 - i;
            }
            else {
                j = 2 - j;
            }
            if (layer.x != 0) {
                buf[j][i] = cubes[layer.x + 1][x][y];
            }
            if (layer.y != 0) {
                buf[2 - j][2 - i] = cubes[x][layer.y + 1][y];
            }
            if (layer.z != 0) {
                buf[j][i] = cubes[x][y][layer.z + 1];
            }
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (layer.x != 0) {
                cubes[layer.x + 1][x][y] = buf[x][y];
                cubes[layer.x + 1][x][y].updateVectors(layer, angle);
            }
            if (layer.y != 0) {
                cubes[x][layer.y + 1][y] = buf[x][y];
                cubes[x][layer.y + 1][y].updateVectors(layer, angle);
            }
            if (layer.z != 0) {
                cubes[x][y][layer.z + 1] = buf[x][y];
                cubes[x][y][layer.z + 1].updateVectors(layer, angle);
            }
        }
    }
}
