#include <GLFW/glfw3.h>
#include <vector>
#include "./utils/ShaderReader.hpp"
#include <glm/glm.hpp>

struct Point {
    float x;
    float y;
};

GLuint linkShaders(std::vector<GLuint> shaders);

class Triangle {
    public:
        GLuint getVbo();

        Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);

    private:
        GLuint vbo;
        float *getVertices();
        glm::vec3 p1;
        glm::vec3 p2;
        glm::vec3 p3;
};
