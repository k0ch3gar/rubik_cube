//
// Created by KOSTJA on 09.02.2024.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Shader {
    unsigned int id;
    GLuint VBO;

public:
    GLuint VAO;


    Shader(std::string vertexFile, std::string fragmentFile);
    ~Shader();

    void use();
    void uniformMatrix(std::string name, glm::mat4 matrix);
};

extern int load_shader(std::string vertexFile, std::string fragmentFile);

#endif //SHADER_H
