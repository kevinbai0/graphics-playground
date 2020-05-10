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
    if (this->fragmentShader) throw "Fragment shader is already set";
    if (this->vertexShader) throw "Vertex shader is already set";
    this->fragmentShader = readShader(fragmentSourcePath, GL_FRAGMENT_SHADER);
    this->vertexShader = readShader(vertexSourcePath, GL_VERTEX_SHADER);

    if (this->fragmentShader && this->vertexShader && this->program == 0) {
        this->program = glCreateProgram();
        glAttachShader(this->program, this->fragmentShader);
        glAttachShader(this->program, this->vertexShader);
        glLinkProgram(this->program);
        glUseProgram(this->program);
        callback(this->program);
    }
}

GLuint Triangle::getFragmentShader() {
    return this->fragmentShader;
}

GLuint Triangle::getVertexShader() {
    return this->vertexShader;
}

void Triangle::free() {
    if (this->program) glDeleteProgram(this->program);
    if (this->fragmentShader) glDeleteShader(this->fragmentShader);
    if (this->vertexShader) glDeleteShader(this->vertexShader);

    glDeleteBuffers(1, &this->vbo);

}