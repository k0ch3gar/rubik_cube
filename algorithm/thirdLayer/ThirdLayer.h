//
// Created by KOSTJA on 25.02.2024.
//

#ifndef RUBIK_CUBE_THIRDLAYER_H
#define RUBIK_CUBE_THIRDLAYER_H

#include "../../camera/Camera.h"
#include "../../graphics/Shader.h"
#include "../../rubik/Rubik.h"
#include "../../window/Window.h"
#include "../Rotation.h"

class ThirdLayer {
public:
    static void yellowEdgesFlips();
    static void moveYellowEdges();
    static void moveYellowCorners();
    static void rotateYellowCorners();
};


#endif //RUBIK_CUBE_THIRDLAYER_H
