#include "cppFX.h"
#include <memory>
#include <iostream>

namespace cppfx 
{

    class Sandbox : public Application
    {
        void run(Stage* stage) override
        {
            WindowResizeEvent e(1280, 720);
            if (e.isInCategory(EventCategoryApplication))
            {
                std::cout << e << std::endl;
            }
            if (e.isInCategory(EventCategoryInput))
            {
                std::cout << e << std::endl;
            }

            auto c = new Cube();
            c->transform(Translate(-0.5, 0, 0));
            c->transform(RotateZ(30));

            auto d = new Cube();
            d->transform(Translate(0.5, 0, 0));
            d->transform(RotateZ(-30));

            auto root = new Group();
            root->add(c);
            root->add(d);
            root->transform(RotateX(40));

            stage->setSize(1024, 1024);
            stage->setTitle("Moving Cube");
            stage->setRoot(root);
        }
    };

} // namespace cppfx

int main(int argc, char** argv) 
{
    auto sandbox = std::make_unique<cppfx::Sandbox>();
    sandbox->launch(argc, argv);
}