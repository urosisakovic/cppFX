#pragma once
#include <GL/glew.h>
#include <vector>
#include "node.h"


namespace cppfx 
{

    class Cube : public Node
    {
    public:
        Cube();
        ~Cube();

        void render() const;

    private:
        static const int POINTS_CNT = 36;
        static point4 vertices[8];
        static int idx;
        static void square(int a, int b, int c, int d);
        static void initialize();
        static point4 points[POINTS_CNT];
        static bool initialzed;

        GLuint modelViewLoc;

        std::vector<mat4> transforms;
        Shader* shader;
        GLuint vao;
    };

} // namespace cppfx