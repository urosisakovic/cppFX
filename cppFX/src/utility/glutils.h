#pragma once
#include <GL/glew.h>
#include <assert.h>
#include <iostream>

#define BUFFER_OFFSET(x) ((GLvoid*) (x))
#define GLCall(x)   GLClearError();\
                    x;\
                    assert(GLLogCall(#x, __FILE__, __LINE__))
                    
void GLClearError();
bool GLLogCall(const char *function, const char *file, unsigned line);