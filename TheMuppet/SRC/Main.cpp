#define STB_IMAGE_IMPLEMENTATION
#include "header.hpp"

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
    
    Shader core_program((char*)"Resources\\Shaders\\vertex_core.glsl", (char*)"Resources\\Shaders\\fragment_core.glsl");

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

    Texture texture0("Resources/Textures/Kirby.png", GL_TEXTURE_2D, 0);
    //Texture texture1("Resources/Textures/cloud.png", GL_TEXTURE_2D);

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
    // Inicializar uniforms

    // Matrices de transformacion

    core_program.setMat4fv(ModelMatrix, "ModelMatrix");
    core_program.setMat4fv(ViewMatrix, "ViewMatrix");
    core_program.setMat4fv(ProjectionMatrix, "ProjectionMatrix");
    
    // Mandar luz y posicion de la camara al shader

    core_program.setVec3f(lightPos0, "lightPos0");
    core_program.setVec3f(camPosition, "cameraPos");


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


        // Active texture
        
        glActiveTexture(GL_TEXTURE0);
        texture0.bind();

        core_program.set1i(0, "texture0");
        //glUniform1i(glGetUniformLocation(core_program, "texture0"), 0);

        core_program.use();

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
        core_program.setMat4fv(ModelMatrix, "ModelMatrix");
        

        // Mantener relacionde aspecto
        glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeigth);

        ProjectionMatrix = glm::mat4(1.f);
        ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferWidth) / framebufferHeigth, nearPlane, farPlane);

        // Actualizar
        core_program.setMat4fv(ProjectionMatrix, "ProjectionMatrix");
        

        // Bind vertex array object

        glBindVertexArray(VAO);

        // Draw_draw
        core_program.use();
        glDrawElements(GL_TRIANGLES, nrOfIndices, GL_UNSIGNED_INT, 0);

        // Draw_endDraw
        glfwSwapBuffers(window);
        glFlush();

        glBindVertexArray(0);
        texture0.unbind();

    }
    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}

//#include "header.cpp"