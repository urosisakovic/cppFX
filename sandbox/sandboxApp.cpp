#include "cppFX.h"
#include <memory>
#include <iostream>


class Sandbox : public cppfx::Application
{
    void run() 
    {
        // init(argc, argv);

        cppfx::Group* root = new cppfx::Group();

        cppfx::Cube* c = new cppfx::Cube();
        c->transform(Translate(-0.5, 0, 0));
        c->transform(RotateZ(30));

        cppfx::Cube *d = new cppfx::Cube();
        d->transform(Translate(0.5, 0, 0));
        d->transform(RotateZ(-30));

        root->add(c);
        root->add(d);

        root->transform(RotateX(40));
        root->render();

        glutMainLoop();

        delete root;
    }
};

int main(int argc, char** argv) 
{
    std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();
    sandbox->launch(argc, argv);
}