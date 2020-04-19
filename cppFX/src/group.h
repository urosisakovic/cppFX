#pragma once
#include <GL/glew.h>
#include <vector>
#include "node.h"


namespace cppfx
{

    class Group : public Node
    {
    public:
        Group();
        ~Group();

        void render() override;

        void add(Node*);
    private:
        std::vector<Node*> children;
    };

} // namespace cppfx