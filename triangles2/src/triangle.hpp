#include <GLFW/glfw3.h>
#include "./utils/ShaderReader.hpp"
#include <glm/glm.hpp>


struct Point {
    float x;
    float y;
};
class Triangle {
    public:
        void setShaders(const char *fragmentSourcePath, const char *vertexSourcePath, std::function<void(GLuint)> fun);
        GLuint getVertexShader();
        GLuint getFragmentShader();
        GLuint getVbo();

        void free();
        Triangle(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3);

    private:
        GLuint vbo;
        GLuint ebo;
        GLuint program = 0;
        GLuint vertexShader = 0;
        GLuint fragmentShader = 0;
        float *getVertices();
        glm::vec3 p1;
        glm::vec3 p2;
        glm::vec3 p3;
};
