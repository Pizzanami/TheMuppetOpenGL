#include "header.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void frameBuffer_resize_callback(GLFWwindow* window, int fbW, int fbH) {
    glViewport(0, 0, fbW, fbH);
}

Vertex vertices[] = {
    // Posicion                         // Color                        //Texcoords                 // Normal
    glm::vec3(-0.5f, 0.5f, 0.f),        glm::vec3(1.f, 0.f, 0.f),       glm::vec2(0.f, 1.f),        glm::vec3(0.f, 0.f, -1.f),
    glm::vec3(-0.5f, -0.5f, 0.f),       glm::vec3(0.f, 1.f, 0.f),       glm::vec2(0.f, 0.f),        glm::vec3(0.f, 0.f, -1.f),
    glm::vec3(0.5f, -0.5f, 0.f),        glm::vec3(0.f, 0.f, 1.f),       glm::vec2(1.f, 0.f),        glm::vec3(0.f, 0.f, -1.f),
    glm::vec3(0.5f, 0.5f, 0.f),         glm::vec3(1.f, 0.f, 1.f),       glm::vec2(1.f, 1.f),        glm::vec3(0.f, 0.f, -1.f)
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

void updateInput(GLFWwindow* window, glm::vec3& position, glm::vec3& rotation, glm::vec3& scale) {
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        position.x -= 0.001f;
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        position.y -= 0.001f;
    } 
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        position.x += 0.001f;
    }
    else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        position.y += 0.001f;
    }
    else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        position.z += 0.001f;
    }
    else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        position.z -= 0.001f;
    }
    else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        rotation.y += 0.05f;
    }
    else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        rotation.y -= 0.05f;
    }
    else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        scale += 0.005f;
    }
    else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        scale -= 0.005f;
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
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(WindowWidth, WindowHeigth, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Ventana rezisable

    glfwSetFramebufferSizeCallback(window, frameBuffer_resize_callback);

    // Ventana no rezisable
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeigth);
    //glViewport(0, 0, framebufferWidth, framebufferHeigth);

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

    //Texcoord
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(3);

    glBindVertexArray(0);

    // Texture init

    int image_width, image_height, nrChannels;
    unsigned char* image = stbi_load("Resources/Textures/Kirby.png", &image_width, &image_height, &nrChannels, 0);
    GLuint texture0;
    glGenTextures(1, &texture0);
    glBindTexture(GL_TEXTURE_2D, texture0);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    if (image) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "No se pudo cargar la imagen\n";
    }
    glActiveTexture(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(image);

    // Model Matrix
    glm::vec3 position(0.f);
    glm::vec3 rotation(0.f);
    glm::vec3 scale(1.f);
    
    glm::mat4 ModelMatrix(1.f);
    ModelMatrix = glm::translate(ModelMatrix, position);
    ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
    ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
    ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
    ModelMatrix = glm::scale(ModelMatrix, scale);
    
    // View Matrix

    // Camara
    glm::vec3 worldUp(0.f, 1.f, 0.f);
    glm::vec3 camFront(0.f, 0.f, -1.f);
    glm::vec3 camPosition(0.f, 0.f, 1.f);

    glm::mat4 ViewMatrix(1.f);
    ViewMatrix = glm::lookAt(camPosition, camPosition + camFront, worldUp);

    // Projection Matrix
    
    float fov = 90.f;
    float nearPlane = 0.1f;
    float farPlane = 1000.f;
    glm::mat4 ProjectionMatrix(1.f);
    ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferWidth)/framebufferHeigth, nearPlane, farPlane);

    // Luces
    glm::vec3 lightPos0(0.f, 0.f, 1.f);



    // Mandar las matrices al shader

    glUseProgram(core_program);
    glUniformMatrix4fv(glGetUniformLocation(core_program, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));
    glUniformMatrix4fv(glGetUniformLocation(core_program, "ViewMatrix"), 1, GL_FALSE, glm::value_ptr(ViewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(core_program, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
    
    // Mandar luz y posicion de la camara al shader
    glUniform3fv(glGetUniformLocation(core_program, "lightPos0"), 1, glm::value_ptr(lightPos0));
    glUniform3fv(glGetUniformLocation(core_program, "cameraPos"), 1, glm::value_ptr(camPosition));

    glUseProgram(0);

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Update input
        glfwPollEvents();
        
        // Update
        updateInput(window);

        // Actualizar posicion, rotacion, escala

        updateInput(window, position, rotation, scale);
        
        // Draw

        // Draw_clear
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        // Usar programa (shader)

        glUseProgram(core_program);

        // Active texture
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture0);

        glUniform1i(glGetUniformLocation(core_program, "texture0"), 0);

        // Update uniforms

        // Mover, rotar y escalar

        // Aplicar cambios
        ModelMatrix = glm::mat4(1.f);
        ModelMatrix = glm::translate(ModelMatrix, position);
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.x), glm::vec3(1.f, 0.f, 0.f));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.y), glm::vec3(0.f, 1.f, 0.f));
        ModelMatrix = glm::rotate(ModelMatrix, glm::radians(rotation.z), glm::vec3(0.f, 0.f, 1.f));
        ModelMatrix = glm::scale(ModelMatrix, scale);

        //Actualizar
        glUniformMatrix4fv(glGetUniformLocation(core_program, "ModelMatrix"), 1, GL_FALSE, glm::value_ptr(ModelMatrix));

        // Mantener relacionde aspecto
        glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeigth);

        ProjectionMatrix = glm::mat4(1.f);
        ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferWidth) / framebufferHeigth, nearPlane, farPlane);

        // Actualizar
        glUniformMatrix4fv(glGetUniformLocation(core_program, "ProjectionMatrix"), 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
        

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

//#include "header.cpp"