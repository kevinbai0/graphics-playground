#include "ShaderReader.hpp"
#include <filesystem>
#include <iostream>

GLuint readShader(std::string filePath, GLenum shaderType) {
    std::fstream in;
    std::string shaderString;
    std::ifstream sourceFile(filePath);

    if (!sourceFile.good()) {
        printf("Can't find file from path %s\n", filePath.c_str());
        return 0;
    }
    shaderString.assign((std::istreambuf_iterator<char>(sourceFile)), std::istreambuf_iterator<char>());

    GLuint shader = glCreateShader(shaderType);
    const char *c_str = shaderString.c_str();
    glShaderSource(shader, 1, &c_str, nullptr);
    glCompileShader(shader);

    GLint status = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    if (status != GL_TRUE) {
        printf( "Unable to compile shader %d!\nSource:\n%s\n", shader, filePath.c_str());
        char buffer[512];
        glGetShaderInfoLog(shader, 512, NULL, buffer);
        printf("%s", buffer);

        glDeleteShader(shader);
        return 0;
    }

    return shader;
}