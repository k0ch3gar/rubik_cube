//
// Created by KOSTJA on 26.02.2024.
//

#include "FileReader.h"

using namespace glm;

std::queue<vec4> FileReader::operations;

void FileReader::read(std::string path) {

    std::ifstream in(path);

    vec3 sides1[] = {
            vec3(1.0f, 0.0f, 0.0f),
            vec3(0.0f, 1.0f, 0.0f),
            vec3(0.0f, 0.0f, 1.0f),
            vec3(-1.0f, 0.0f, 0.0f),
            vec3(0.0f, -1.0f, 0.0f),
            vec3(0.0f, 0.0f, -1.0f)
    };

    while(in) {
        char buf;
        in.read(&buf, sizeof(char));
        switch (buf) {
            case 'R': {
                operations.push(vec4(sides1[0].x, sides1[0].y, sides1[0].z, -90.0f));
                break;
            }
            case 'L': {
                operations.push(vec4(sides1[3].x, sides1[3].y, sides1[3].z, 90.0f));
                break;
            }
            case 'U': {
                operations.push(vec4(sides1[1].x, sides1[1].y, sides1[1].z, -90.0f));
                break;
            }
            case 'D': {
                operations.push(vec4(sides1[4].x, sides1[4].y, sides1[4].z, 90.0f));
                break;
            }
            case 'F': {
                operations.push(vec4(sides1[2].x, sides1[2].y, sides1[2].z, -90.0f));
                break;
            }
            case 'B': {
                operations.push(vec4(sides1[5].x, sides1[5].y, sides1[5].z, 90.0f));
                break;
            }
            case ' ': {
                break;
            }
            case '\'': {
                if (operations.empty()) {
                    Logger::print("Incorrect commands! Expected rotation command before: \' \n");
                    return;
                }
                operations.back().w *= -1;
                break;
            }
            default: {
                while (!operations.empty()) {
                    operations.pop();
                }
                Logger::print("Incorrect commands! No such command\n");
                return;
            }
        }
    }

}

void FileReader::use() {
    if (operations.empty()) {
        Logger::print("Incorrect commands!\n");
        return;
    }
    while (!operations.empty()) {
        Rotation::rotateLayer(operations.front(), operations.front().w);
        operations.pop();
    }
}
