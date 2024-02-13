//
// Created by KOSTJA on 09.02.2024.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/glm.hpp>

class Shader {
public:
    unsigned int id;

    Shader(unsigned int id);
    ~Shader();

    void use();
    void uniformMatrix(std::string name, glm::mat4 matrix);
};

extern Shader* load_shader(std::string vertexFile, std::string fragmentFile);

#endif //SHADER_H
