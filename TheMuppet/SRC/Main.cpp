#include "header.hpp"

Vertex vertices[] = {
    // Posicion                         // Color                        //Texcoords
    glm::vec3(-0.5f, 0.5f, 0.f),        glm::vec3(1.f, 0.f, 0.f),       glm::vec2(0.f, 1.f),
    glm::vec3(-0.5f, -0.5f, 0.f),       glm::vec3(0.f, 1.f, 0.f),       glm::vec2(0.f, 0.f),
    glm::vec3(0.5f, -0.5f, 0.f),        glm::vec3(0.f, 0.f, 1.f),       glm::vec2(1.f, 0.f),
    glm::vec3(0.5f, 0.5f, 0.f),         glm::vec3(1.f, 0.f, 1.f),       glm::vec2(1.f, 1.f)
};

unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

GLuint indices[] = {
    0, 1, 2,
    0, 2, 3
};

unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

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

void updateInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

}

int main(void) {

    // Inicalizar GLFW
    if (!glfwInit())
        return -1;

    // Creamos una ventana
    GLFWwindow* window;
    const int WindowWidth = 640;
    const int WindowHeigth = 640;
    int framebufferWidth = 0;
    int framebufferHeigth = 0;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(WindowWidth, WindowHeigth, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeigth);
    glViewport(0, 0, framebufferWidth, framebufferHeigth);

    // Crear un contexto de ventana
    glfwMakeContextCurrent(window);

    // Inicializar GLEW
    if (glewInit() != GLEW_OK)
        std::cout << "Error!\n";

    // Configuraciones OpenGL

    // Habilitar eje coordenado z
    glEnable(GL_DEPTH_TEST);

    // Evita dibujar la parte trasera de una figura
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    // Combinar o difuminar colores
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Inicializar shaders
    GLuint core_program;
    if (!loadShaders(core_program)) {
        glfwTerminate();
    }

    // Crear buffers

    // Generar buffer de objeto
    GLuint VAO;
    glCreateVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generar buffer de vertices

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Element buffer

    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Asignar atributos de vertices y habilitar

    // Posicion
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);

    //Color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    //Texcoord
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texcoord));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

    // Texture init

    int image_width = 0;
    int image_height = 0;
   
    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Update input
        glfwPollEvents();
        // Update
        updateInput(window);
        // Draw

        // Draw_clear
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        // Usar programa (shader)

        glUseProgram(core_program);

        // Active texture
        

        // Bind vertex array object

        glBindVertexArray(VAO);

        // Draw_draw

        glDrawElements(GL_TRIANGLES, nrOfIndices, GL_UNSIGNED_INT, 0);

        // Draw_endDraw
        glfwSwapBuffers(window);
        glFlush();

        glBindVertexArray(0);
        glUseProgram(0);
        glActiveTexture(0);

    }
    glfwDestroyWindow(window);
    glDeleteProgram(core_program);

    glfwTerminate();
    return 0;
}

#include "header.cpp"