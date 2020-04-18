#include "cppFX.h"
#include <memory>
#include <iostream>

class Sandbox : public cppfx::Application
{
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