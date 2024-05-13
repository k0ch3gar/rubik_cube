//
// Created by KOSTJA on 25.02.2024.
//

#ifndef RUBIK_CUBE_RUBIKALGORITHM_H
#define RUBIK_CUBE_RUBIKALGORITHM_H

#include "../camera/Camera.h"
#include "../graphics/Shader.h"
#include "../rubik/Rubik.h"
#include "../window/Window.h"
#include "firstLayer/FirstLayer.h"
#include "secondLayer/BuildSecondLayer.h"
#include "thirdLayer/ThirdLayer.h"
#include "scramble/Scramble.h"
#include "Rotation.h"

class RubikAlgorithm {
public:
    static void solve();
};

#endif //RUBIK_CUBE_RUBIKALGORITHM_H
