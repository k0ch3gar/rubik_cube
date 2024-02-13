//
// Created by KOSTJA on 13.02.2024.
//

#ifndef RUBIK_CUBE_BUILDSECONDEDGES_H
#define RUBIK_CUBE_BUILDSECONDEDGES_H

#include "../basicAlgorithm/BasicAlgorithm.h"

class BuildSecondEdges {
public:
    static void buildSecondEdges(Camera* camera, Rubik* rubik, int ind);
    static void yellowEdgesFlips(Camera* camera, Rubik* rubik);
    static void moveYellowEdges(Camera* camera, Rubik* rubik);
    static void moveYellowCorners(Camera* camera, Rubik* rubik);
    static void rotateYellowCorners(Camera* camera, Rubik* rubik);
};


#endif //RUBIK_CUBE_BUILDSECONDEDGES_H
