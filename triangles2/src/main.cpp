#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "triangle.hpp"

int main()
{
    // initialize glfw
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // make window
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    glewInit();

    // vertex arrays
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    std::vector<GLuint> shaders = { readShader("./src/shaders/fragment.glsl", GL_FRAGMENT_SHADER), readShader("./src/shaders/vertex.glsl", GL_VERTEX_SHADER) };
    GLuint programShader = linkShaders(shaders);

    Triangle triangle(glm::vec3(0.5f, 0.5f, 1.0f), glm::vec3(-0.5f, 0.5f, 1.0f), glm::vec3(0.0f,-0.5f, 1.0f));

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glUseProgram(programShader);

    // initialize event loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(programShader);
    glDeleteVertexArrays(1, &vao);

    // terminate glfw
    glfwTerminate();

    return 0;
}