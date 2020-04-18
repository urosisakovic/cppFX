#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <assert.h>
#include "glutils.h"

class Shader {
public:
    Shader(const std::string&, const std::string&);
    void bind() const;
    void unbind() const;
    inline GLuint getProgram() { return program; }
private:
    void loadShader(GLenum type);
    void compileShader(GLenum type);

    // vertex shader
    std::string vFilepath;
    std::string vSource;
    GLuint vShaderId;

    // fragment shader
    std::string fFilepath;
    std::string fSource;
    GLuint fShaderId;

    GLuint program;
};