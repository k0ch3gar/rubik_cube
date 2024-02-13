//
// Created by KOSTJA on 10.02.2024.
//

#ifndef RUBIK_CUBE_CUBE_H
#define RUBIK_CUBE_CUBE_H

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "../../graphics/Shader.h"
#include "../../camera/Camera.h"


using namespace glm;


class Cube {



    GLuint VAO;
    GLuint VBO;

    Shader* shader;
    Camera* camera;
public:

    vec3 up = vec3(0.0f, 1.0f, 0.0f);
    vec3 front = vec3(0.0f, 0.0f, 1.0f);
    vec3 right = vec3(1.0f, 0.0f, 0.0f);

    vec3 white = up;
    vec3 orange = front;
    vec3 green = right;


    mat4 model = mat4(1.0f);
    vec3 offset = vec3(0);

    int index;

    Cube(Camera* camera);
    Cube();
    ~Cube();


    void drawCube();
    void rotateCube(GLfloat angle, vec3 rotationAxis);
    void moveCube(vec3 offset);
    void updateVectors(vec3 rotationAxis, GLfloat angle);

};


#endif //RUBIK_CUBE_CUBE_H
