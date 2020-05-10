#include "triangle.hpp"

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

void Triangle::setShaders(const char *fragmentSourcePath, const char *vertexSourcePath, std::function<void(GLuint)> callback) {
    GLuint fragmentShader = readShader(fragmentSourcePath, GL_FRAGMENT_SHADER);
    GLuint vertexShader = readShader(vertexSourcePath, GL_VERTEX_SHADER);

    this->program = glCreateProgram();
    glAttachShader(this->program, fragmentShader);
    glAttachShader(this->program, vertexShader);
    glLinkProgram(this->program);
    callback(this->program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

GLuint Triangle::getProgramShader() {
    return this->program;
}

void Triangle::free() {
    glDeleteProgram(this->program);
    glDeleteBuffers(1, &this->vbo);
}