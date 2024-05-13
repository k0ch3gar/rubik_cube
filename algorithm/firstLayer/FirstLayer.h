//
// Created by KOSTJA on 12.02.2024.
//

#ifndef RUBIK_CUBE_FIRSTLAYER_H
#define RUBIK_CUBE_FIRSTLAYER_H

#include "../basicAlgorithm/BasicAlgorithm.h"
#include <iostream>

class FirstLayer {
public:
    static void buildWhiteEdges(int ind);
    static void buildWhiteCorners(int ind);
    static bool isWhiteCrossCorrect();
};


#endif //RUBIK_CUBE_FIRSTLAYER_H
