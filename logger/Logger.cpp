//
// Created by KOSTJA on 26.02.2024.
//

#include "Logger.h"

bool Logger::isFirst = true;

void Logger::print(vec3 rotationAxis, GLfloat angle) {
    bool sign = false;
    std::ofstream out;
    if (!isFirst) {
        out.open("LastLog.txt", std::ios_base::app);
    }
    else {
        isFirst = false;
        out.open("LastLog.txt");
    }

    if (rotationAxis == Rubik::R) {
        out << 'R';
    }
    else if (rotationAxis == Rubik::L) {
        sign = true;
        out << 'L';
    }
    else if (rotationAxis == Rubik::U) {
        out << 'U';
    }
    else if (rotationAxis == Rubik::D) {
        sign = true;
        out << 'D';
    }
    else if (rotationAxis == Rubik::F) {
        out << 'F';
    }
    else if (rotationAxis == Rubik::B) {
        sign = true;
        out << 'B';
    }
    else {
        out << '\n';
        return;
    }
    bool aSign = angle < 0;
    if (sign == aSign) {
        out << '\'';
    }
    out << ' ';
    out.close();
}

void Logger::print(std::string problem) {
    std::ofstream out;
    if (!isFirst) {
        out.open("LastLog.txt", std::ios_base::app);
    }
    else {
        isFirst = false;
        out.open("LastLog.txt");
    }
    out << "ERROR: " << problem << '\n';
}
