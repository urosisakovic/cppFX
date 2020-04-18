#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "utility/glutils.h"


namespace cppfx
{

    class Application 
    {
    public:
        Application();
        ~Application();

        void launch(int argc, char** argv);

    protected:
        virtual void run() = 0;
    };

} // namespace cppfx