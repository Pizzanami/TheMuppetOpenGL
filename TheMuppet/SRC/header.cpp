#include "header.hpp"
/*
bool loadShaders(GLuint& program) {
    bool LoadSuccess = true;
    char infoLog[512];
    GLint success;
    std::ifstream in_file;
    std::string temp = "";
    std::string src = "";

    // Vertex
    in_file.open("Resources\\Shaders\\vertex_core.glsl");
    if (in_file.is_open()) {
        while (std::getline(in_file, temp)) {
            src += temp + "\n";
        }
    }
    else {
        std::cout << "ERROR: no se pudo abrir el vertex shader";
        LoadSuccess = false;
    }
    in_file.close();

    // Crear y compilar VertexShader

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vertSrc = src.c_str();
    glShaderSource(vertexShader, 1, &vertSrc, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::LOADSHADERS::COULD_NOT_COMPILE_VERTEX_SHADER" << "\n";
        std::cout << infoLog << "\n";
        LoadSuccess = false;
    }

    // Fragment Shader

    temp = "";
    src = "";

    in_file.open("Resources\\Shaders\\fragment_core.glsl");
    if (in_file.is_open()) {
        while (std::getline(in_file, temp)) {
            src += temp + "\n";
        }
    }
    else {
        std::cout << "ERROR: no se pudo abrir el fragment shader";
        LoadSuccess = false;
    }
    in_file.close();

    // Crear y compilar VertexShader

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fragSrc = src.c_str();
    glShaderSource(fragmentShader, 1, &fragSrc, NULL);
    glCompileShader(fragmentShader);

    // int success;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::LOADSHADERS::COULD_NOT_COMPILE_FRAGMENT_SHADER" << "\n";
        std::cout << infoLog << "\n";
        LoadSuccess = false;
    }

    // Agregar al programa

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);

    if (!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::LOADSHADERS::COULD_NOT_LINK_PROGRAM" << "\n";
        std::cout << infoLog << "\n";
        LoadSuccess = false;
    }


    // EliminarShader

    glUseProgram(0);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return LoadSuccess;
}
*/