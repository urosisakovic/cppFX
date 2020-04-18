#version 150

in vec4 vPosition;

uniform mat4 modelView;

void main() {
    gl_Position = modelView * vPosition;
}