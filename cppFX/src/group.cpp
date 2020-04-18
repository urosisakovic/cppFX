#include "group.h"


namespace cppfx
{

    Group::Group()
    {
    }

    Group::~Group()
    {
        for (auto node : children)
            delete node;
    }


    void Group::render() const
    {
        GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

        mat4 groupTransformationMatrix = transformationMatrix();
        for (auto node : children)
            node->render(groupTransformationMatrix);

        glutSwapBuffers();
    }

    void Group::add(Node* node) 
    {
        children.push_back(node);
    }

} // namespace cppfx