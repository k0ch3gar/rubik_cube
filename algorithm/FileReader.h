//
// Created by KOSTJA on 26.02.2024.
//

#ifndef RUBIK_CUBE_FILEREADER_H
#define RUBIK_CUBE_FILEREADER_H

#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "Rotation.h"
#include <queue>
#include "../logger/Logger.h"

class FileReader {
    static std::queue<vec4> operations;
public:
    static void read(std::string path);
    static void use();
};


#endif //RUBIK_CUBE_FILEREADER_H
