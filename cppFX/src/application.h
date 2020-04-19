#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>
#include "utility/glutils.h"
#include "stage.h"
#include "debug.h"

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
        static void display();
        static void reshape(int, int);
        static void idle();
        static void mouse(int, int, int, int);
        static void keyboard(unsigned char, int, int);
        static void mouseActiveMotion(int, int);
        static void mousePassiveMotion(int, int);

        Stage* stage;
    };

} // namespace cppfx