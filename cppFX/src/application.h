#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "utility/glutils.h"
#include "stage.h"

namespace cppfx
{

    class Application 
    {
    public:
        Application();
        ~Application();

        void launch(int argc, char** argv);

    protected:
        virtual void run(Stage*) = 0;

    private:
        Stage* stage;
    };

} // namespace cppfx