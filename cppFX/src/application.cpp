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

        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutReshapeFunc(reshape);
        glutMouseFunc(mouse);
        glutPassiveMotionFunc(mousePassiveMotion);
        glutMotionFunc(mouseActiveMotion);
        glutIdleFunc(idle);

        GLCall(glEnable(GL_DEPTH_TEST));
        glewInit();

        stage->getRoot()->render();

        glutMainLoop();
    }

    void Application::display()
    {
        LOG_EVENT("Display event");
    }

    void Application::reshape(int width, int height)
    {
        LOG_EVENT("Reshape event(" << width << ", " << height);
    }

    void Application::idle()
    {
        LOG_IDLE_EVENT("Idle event");
    }

    void Application::mouse(int button, int state, int x, int y)
    {
        LOG_EVENT("Mouse event " << x << " " << y << " " << button << " " << state);
    }

    void Application::keyboard(unsigned char key, int x, int y) 
    {
        LOG_EVENT("Keyboard event " << x << " " << y << " " << key);
    }

    void Application::mouseActiveMotion(int x, int y)
    {
        LOG_EVENT("Mouse active event: " << x << " " << y);
    }

    void Application::mousePassiveMotion(int x, int y)
    {
        LOG_EVENT("Mouse passive event " << x << " " << y);
    }


} // namespace cppfx 