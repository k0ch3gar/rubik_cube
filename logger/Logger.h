//
// Created by KOSTJA on 26.02.2024.
//

#ifndef RUBIK_CUBE_LOGGER_H
#define RUBIK_CUBE_LOGGER_H

#include "../algorithm/basicAlgorithm/BasicAlgorithm.h"
#include <iostream>
#include <fstream>



class Logger {
    static bool isFirst;
public:
    static void print(vec3 rotationAxis, GLfloat angle);
    static void print(std::string problem);
};


#endif //RUBIK_CUBE_LOGGER_H
