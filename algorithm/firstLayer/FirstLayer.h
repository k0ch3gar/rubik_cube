//
// Created by KOSTJA on 12.02.2024.
//

#ifndef RUBIK_CUBE_FIRSTLAYER_H
#define RUBIK_CUBE_FIRSTLAYER_H

#include "../basicAlgorithm/BasicAlgorithm.h"
#include <iostream>

class FirstLayer {
public:
    static void buildWhiteEdges(Camera* camera, Rubik* rubik, int ind);
    static void buildWhiteLayer(Camera* camera, Rubik* rubik, int ind);
    static bool isWhiteCrossCorrect(Rubik* rubik);
};


#endif //RUBIK_CUBE_FIRSTLAYER_H
