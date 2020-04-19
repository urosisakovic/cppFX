#include "stage.h"

namespace cppfx
{
    Stage::Stage()
    {   
    }
    
    Stage::~Stage()
    {   
    }
    
    void Stage::setWidth(unsigned width)
    {
        this->width = width;
    }

    void Stage::setHeight(unsigned height)
    {
        this->height = height;
    }

    void Stage::setSize(unsigned width, unsigned height)
    {
        this->width = width;
        this->height = height;
    }

    int Stage::getWidth() const
    {
        return width;
    }

    int Stage::getHeight() const
    {
        return height;
    }

    void Stage::setTitle(const std::string& title)
    {
        this->title = title;
    }

    // TODO: Fix this(pointer might be invalid).
    const char* Stage::getTitle() const
    {
        return title.c_str();
    }

    void Stage::setRoot(Group* root)
    {
        this->root = root;
    }

    Group* Stage::getRoot()
    {
        return root;
    }
}