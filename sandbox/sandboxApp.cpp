#include "cppFX.h"
#include <memory>
#include <iostream>


class Sandbox : public cppfx::Application
{
    void run() 
    {
        auto root = new cppfx::Group();

        auto c = new cppfx::Cube();
        c->transform(Translate(-0.5, 0, 0));
        c->transform(RotateZ(30));

        auto d = new cppfx::Cube();
        d->transform(Translate(0.5, 0, 0));
        d->transform(RotateZ(-30));

        root->add(c);
        root->add(d);

        root->transform(RotateX(40));
        root->render();
    }
};

int main(int argc, char** argv) 
{
    auto sandbox = std::make_unique<Sandbox>();
    sandbox->launch(argc, argv);
}