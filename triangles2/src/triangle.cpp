#include "triangle.hpp"

GLuint linkShaders(std::vector<GLuint> shaders) {
    GLuint program = glCreateProgram();
    std::for_each(shaders.begin(), shaders.end(), [program](GLuint shader) {
        glAttachShader(program, shader);
    });
    glLinkProgram(program);

    // delete shaders
    std::for_each(shaders.begin(), shaders.end(), [](GLuint shader) {
        glDeleteShader(shader);
    });
    return program;
}


Triangle::Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3) {
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    // buffer data
    float vertices[] = {
        this->p1.x, this->p1.y, this->p1.z,
        this->p2.x, this->p2.y, this->p2.z,
        this->p3.x, this->p3.y, this->p3.z
    };

    glGenBuffers(1, &this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}