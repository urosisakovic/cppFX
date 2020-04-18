#include <memory>
#include "application.h"

#include <iostream>

class Sandbox : public cppfx::Application
{
protected:
    void run() 
    {
        std::cout << "Sandbox::run()" << std::endl;
    }
};

int main(int argc, char** argv) 
{
    std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();
    sandbox->launch(argc, argv);
}