#include "shader.h"

Shader::Shader(const std::string& vFilepath, const std::string& fFilepath) {
    this->vFilepath = vFilepath;
    this->fFilepath = fFilepath;

    loadShader(GL_VERTEX_SHADER);
    compileShader(GL_VERTEX_SHADER);

    loadShader(GL_FRAGMENT_SHADER);
    compileShader(GL_FRAGMENT_SHADER);
    
    // link shaders into a program
    GLCall(program = glCreateProgram());
    GLCall(glAttachShader(program, vShaderId));
    GLCall(glAttachShader(program, fShaderId));
    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    // check for linking errors
    GLint linked;
    GLCall(glGetProgramiv(program, GL_LINK_STATUS, &linked));
    if (!linked) {
        std::cerr << "Shader program failed to link: " << std::endl;

        // print log message
        GLint logSize;
        GLCall(glGetShaderiv(program, GL_INFO_LOG_LENGTH, &logSize));
        char logMsg[logSize];
        GLCall(glGetShaderInfoLog(program, logSize, nullptr, logMsg));
        std::cerr << logMsg << std::endl;

        exit(EXIT_FAILURE);
    }
}

void Shader::bind() const {
    GLCall(glUseProgram(program));
}

void Shader::unbind() const {
    GLCall(glUseProgram(0));
}

void Shader::loadShader(GLenum type) {
    // pick a shader type
    assert(type == GL_VERTEX_SHADER || type == GL_FRAGMENT_SHADER);
    std::string& filepath = (type == GL_VERTEX_SHADER) ? vFilepath : fFilepath;
    std::string& source = (type == GL_VERTEX_SHADER) ? vSource : fSource;
    
    // read shader from file
    std::ifstream stream(filepath);
    assert(stream.is_open());

    std::string line;
    std::stringstream ss;
    while (getline(stream, line))
        ss << line << '\n';

    source = ss.str();
}

void Shader::compileShader(GLenum type) {
    // pick a shader type
    assert(type == GL_VERTEX_SHADER || type == GL_FRAGMENT_SHADER);
    std::string& source = (type == GL_VERTEX_SHADER) ? vSource : fSource;
    GLuint& shaderId = (type == GL_VERTEX_SHADER) ? vShaderId : fShaderId;

    // OpenGL cannot work with std::string. It requires GLchar* 
    GLchar* src = (GLchar*) source.c_str();

    // set shader source and compile it
    GLCall(shaderId = glCreateShader(type));
    GLCall(glShaderSource(shaderId, 1, &src, nullptr));
    GLCall(glCompileShader(shaderId));

    // check for compilation errors
    GLint compiled;
    GLCall(glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compiled));
    if (!compiled) {
        std::cerr << (type == GL_VERTEX_SHADER ? vFilepath : fFilepath)
            << " failed to compile"<< std::endl;

        // print log message
        GLint logSize;
        GLCall(glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logSize));
        char logMsg[logSize];
        GLCall(glGetShaderInfoLog(shaderId, logSize, nullptr, logMsg));
        std::cerr << logMsg << std::endl;

        exit(EXIT_FAILURE);
    }
}