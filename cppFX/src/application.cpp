#include "application.h"


namespace cppfx
{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::launch(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 
        glutInitWindowSize(512, 512);
        glutCreateWindow("OO Cube");

        glewInit();

        GLCall(glClearColor(1.0, 1.0, 1.0, 1.0));
        GLCall(glEnable(GL_DEPTH_TEST));

        run();

        
    }

} // namespace cppfx 