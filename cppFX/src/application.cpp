#include "application.h"
#include <iostream>

namespace cppfx
{

    Application::Application()
    {
        stage = new Stage();
    }

    Application::~Application()
    {
        delete stage;
    }

    void Application::launch(int argc, char** argv)
    {
        run(stage);

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 

        glutInitWindowSize(stage->getWidth(), stage->getHeight());
        std::cout << "stage->getTitle(): " << stage->getTitle() << std::endl;
        glutCreateWindow(stage->getTitle());

        GLCall(glEnable(GL_DEPTH_TEST));
        glewInit();

        stage->getRoot()->render();

        glutMainLoop();
    }

} // namespace cppfx 