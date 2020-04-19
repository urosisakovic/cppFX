#include "cppFX.h"
#include <memory>
#include <iostream>


class Sandbox : public cppfx::Application
{
    void run(cppfx::Stage* stage) override
    {
        auto c = new cppfx::Cube();
        c->transform(Translate(-0.5, 0, 0));
        c->transform(RotateZ(30));

        auto d = new cppfx::Cube();
        d->transform(Translate(0.5, 0, 0));
        d->transform(RotateZ(-30));

        auto root = new cppfx::Group();
        root->add(c);
        root->add(d);
        root->transform(RotateX(40));

        stage->setSize(1024, 1024);
        stage->setTitle("Moving Cube");
        stage->setRoot(root);
    }
};

int main(int argc, char** argv) 
{
    auto sandbox = std::make_unique<Sandbox>();
    sandbox->launch(argc, argv);
}