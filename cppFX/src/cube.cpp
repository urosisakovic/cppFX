#include "cube.h"


namespace cppfx
{

    point4 Cube::vertices[8] = {
            point4(-0.3, -0.3, -0.3,  1), // 0
            point4( 0.3, -0.3, -0.3,  1), // 1
            point4( 0.3,  0.3, -0.3,  1), // 2
            point4(-0.3,  0.3, -0.3,  1), // 3
            point4(-0.3, -0.3,  0.3,  1), // 4
            point4( 0.3, -0.3,  0.3,  1), // 5
            point4( 0.3,  0.3,  0.3,  1), // 6
            point4(-0.3,  0.3,  0.3,  1)  // 7
        };
    point4 Cube::points[POINTS_CNT];
    int Cube::idx = 0;
    bool Cube::initialzed = false;


    Cube::Cube()
    {
        if (!initialzed) 
        {
            initialize();
            initialzed = true;
        }

        // prepare shader program
        shader = new Shader("/home/uros/src/cppFX/cppFX/src/shaders/vertex.glsl", "/home/uros/src/cppFX/cppFX/src/shaders/fragment.glsl");
        shader->bind();

        // create a vertex array object
        GLCall(glGenVertexArrays(1, &vao));
        GLCall(glBindVertexArray(vao));

        // create and initialize a buffer object
        GLuint buffer;
        GLCall(glGenBuffers(1, &buffer));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
        GLCall(glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW));

        // initialize the vertex position attribute form the vertex shader
        GLCall(GLuint loc = glGetAttribLocation(shader->getProgram(), "vPosition"));
        GLCall(glEnableVertexAttribArray(loc));
        GLCall(glVertexAttribPointer(loc, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0)));

        GLCall(modelViewLoc = glGetUniformLocation(shader->getProgram(), "modelView"));
    }

    Cube::~Cube()
    {
        delete shader;
    }

    void Cube::render() const
    {
        GLCall(glBindVertexArray(vao));
        shader->bind();

        GLCall(glUniformMatrix4fv(modelViewLoc, 1, GL_TRUE, transformationMatrix()));
        GLCall(glDrawArrays(GL_TRIANGLES, 0, POINTS_CNT));
    }

    void Cube::square(int a, int b, int c, int d)
    {
        points[idx++] = vertices[a];
        points[idx++] = vertices[b];
        points[idx++] = vertices[c];

        points[idx++] = vertices[a];
        points[idx++] = vertices[c];
        points[idx++] = vertices[d];
    }

    void Cube::initialize()
    {
        square(0, 1, 2, 3);
        square(1, 5, 6, 2);
        square(5, 4, 7, 6);
        square(4, 0, 3, 7);
        square(4, 5, 1, 0);
        square(3, 2, 6, 7);
    }

} //namespace cppfx