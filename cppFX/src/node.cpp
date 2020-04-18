#include "node.h"

namespace cppfx
{

    Node::Node()
    {
    }

    Node::~Node()
    {
    }


    Node& Node::translate(const vec3& t)
    {
        transforms.push_back(Translate(t));
    }

    Node& Node::rotate(const vec3& r)
    {
        transforms.push_back(RotateX(r[0]));
        transforms.push_back(RotateY(r[1]));
        transforms.push_back(RotateZ(r[2]));
    }

    Node& Node::scale(const vec3& s)
    {
        transforms.push_back(Scale(s));
    }

    Node& Node::transform(const mat4& m)
    {
        transforms.push_back(m);
    }

    mat4 Node::transformationMatrix() const 
    {
        mat4 trans = identity();
        for (auto& transform : transforms)
            trans = transform * trans;
        return trans;
    }

    void Node::render(const mat4& trans)
    {
        transforms.push_back(trans);
        this->render();
        transforms.pop_back();
    }

}