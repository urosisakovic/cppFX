#pragma once
#include <GL/glew.h>
#include <vector>
#include "../utility/linalg.h"
#include "../utility/shader.h"
#include "node.h"


class Group : public Node
{
public:
    Group();
    ~Group();

    void render() const override;

    void add(Node*);
private:
    std::vector<Node*> children;
};