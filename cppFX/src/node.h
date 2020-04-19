#pragma once
#include <GL/glew.h>
#include <vector>
#include "utility/linalg.h"
#include "utility/shader.h"

namespace cppfx 
{

    class Node
    {
    public:
        Node();
        virtual ~Node();

        Node& translate(const vec3&);
        Node& rotate(const vec3&);
        Node& scale(const vec3&);
        Node& transform(const mat4&);

        virtual void render() = 0;
        virtual void render(const mat4&);

        mat4 transformationMatrix() const;

    private:
        std::vector<mat4> transforms;
    };

}