#pragma once

namespace cppfx
{
    class Application 
    {
    public:
        Application();
        ~Application();

        void launch(int argc, char** argv);

    protected:
        virtual void run() = 0;
    };
}