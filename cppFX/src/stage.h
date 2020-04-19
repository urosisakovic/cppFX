#pragma once
#include <string>
#include <memory>
#include "group.h"

namespace cppfx
{

    class Stage
    {
    public:
        Stage();
        ~Stage();

        void setWidth(unsigned);
        void setHeight(unsigned);
        void setSize(unsigned, unsigned);
        int getWidth() const;
        int getHeight() const;

        void setTitle(const std::string&);
        const char* getTitle() const;

        void setRoot(Group*);
        Group* getRoot();

    private:
        int width, height;
        std::string title;
        Group* root;
    };

} // namespace cppfx