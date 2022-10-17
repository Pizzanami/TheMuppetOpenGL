#define STB_IMAGE_IMPLEMENTATION
#include "header.hpp"

bool doredo = false;
std::stack<std::string> undo;
std::stack<std::string> redo;

void frameBuffer_resize_callback(GLFWwindow* window, int fbW, int fbH) {
    glViewport(0, 0, fbW, fbH);
}

void updateInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

}

void undoInput(Mesh* objeto, bool undoB) {
    char inst = '0';
    if (undoB && !undo.empty()) {
        inst = undo.top()[0];
        undo.pop();
    }
    if(!undoB && !redo.empty()) {
        inst = redo.top()[0];
        redo.pop();
    }
    switch ((char)inst) {
        case 'A':
            (*objeto).move(glm::vec3(-0.001f, 0.f, 0.f));
        case 'S':
            (*objeto).move(glm::vec3(0.f, -0.001f, 0.f));
        case 'D':
            (*objeto).move(glm::vec3(0.001f, 0.f, 0.f));
        case 'W':
            (*objeto).move(glm::vec3(0.f, 0.001f, 0.f));
        case 'E':
            (*objeto).move(glm::vec3(0.f, 0.f, 0.001f));
        case 'Q':
            (*objeto).move(glm::vec3(0.f, 0.f, -0.001f));
        case 'R':
            (*objeto).rotate(glm::vec3(0.f, 0.1f, 0.f));
        case 'F':
            (*objeto).rotate(glm::vec3(0.0f, -0.1f, 0.f));
        case 'X':
            (*objeto).scaleUp(glm::vec3(0.005f));
        case 'Z':
            (*objeto).scaleUp(glm::vec3(-0.005f));
    }
}

void updateInput(GLFWwindow* window, Mesh* objeto) {
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        (*objeto).move(glm::vec3(-0.001f, 0.f, 0.f));
        undo.push("D");
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        (*objeto).move(glm::vec3(0.f, -0.001f, 0.f));
        undo.push("W");
    }
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        (*objeto).move(glm::vec3(0.001f, 0.f, 0.f));
        undo.push("A");
    }
    else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        (*objeto).move(glm::vec3(0.f, 0.001f, 0.f));
        undo.push("S");
    }
    else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        (*objeto).move(glm::vec3(0.f, 0.f, 0.001f));
        undo.push("Q");
    }
    else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        (*objeto).move(glm::vec3(0.f, 0.f, -0.001f));
        undo.push("E");
    }
    else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        (*objeto).rotate(glm::vec3(0.0f, 0.1f, 0.f));
        undo.push("F");
    }
    else if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS) {
        (*objeto).rotate(glm::vec3(0.0f, -0.1f, 0.f));
        undo.push("R");
    }
    else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        (*objeto).scaleUp(glm::vec3(0.005f));
        undo.push("Z");
    }
    else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        (*objeto).scaleUp(glm::vec3(-0.005f));
        undo.push("X");
    }
    else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS) {
        (*objeto).reset();
        while (!undo.empty()) {
            undo.pop();
        }
        while (!redo.empty()) {
            redo.pop();
        }
    }
    else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        redo.push(undo.top());
        undoInput(objeto, true);
    }
    else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        undo.push(redo.top());
        undoInput(objeto, false);
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
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Ventana rezisable

    glfwSetFramebufferSizeCallback(window, frameBuffer_resize_callback);

    // Ventana no rezisable
    glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeigth);

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
    Shader texturesShader((char*)"Resources\\Shaders\\vertex_core.glsl", (char*)"Resources\\Shaders\\fragment_core_texturas.glsl");

    // Crear buffers

    Primitive Partes[19] = {
    Cara(),       //0
    Torso(),
    Pico(),
    MonoL(),
    MonoR(),
    Cabeza(),
    Cuerpo(),
    LUpArm(),
    LLowArm(),
    LHand(),
    RUpArm(),
     RLowArm(),
     RHand(),
     LUpLeg(),
     LLowLeg(),
     LFoot(),
     RUpLeg(),
     RLowLeg(),
     RFoot() };
    Mesh Muppet[19]{
        Mesh(&Partes[0] , Partes[0].orig()),
        Mesh(&Partes[1] , Partes[1].orig()),
        Mesh(&Partes[2] , Partes[2].orig()),
        Mesh(&Partes[3] , Partes[3].orig()),
        Mesh(&Partes[4] , Partes[4].orig()),
        Mesh(&Partes[5] , Partes[5].orig()),
        Mesh(&Partes[6] , Partes[6].orig()),
        Mesh(&Partes[7] , Partes[7].orig()),
        Mesh(&Partes[8] , Partes[8].orig()),
        Mesh(&Partes[9] , Partes[9].orig()),
        Mesh(&Partes[10], Partes[10].orig()),
        Mesh(&Partes[11], Partes[11].orig()),
        Mesh(&Partes[12], Partes[12].orig()),
        Mesh(&Partes[13], Partes[13].orig()),
        Mesh(&Partes[14], Partes[14].orig()),
        Mesh(&Partes[15], Partes[15].orig()),
        Mesh(&Partes[16], Partes[16].orig()),
        Mesh(&Partes[17], Partes[17].orig()),
        Mesh(&Partes[18], Partes[18].orig())
    };
    // Texture init

    Texture texture0("Resources/Textures/Cara.png", GL_TEXTURE_2D, 0);
    Texture texture1("Resources/Textures/Cuerpo.png", GL_TEXTURE_2D, 0);
    //Texture texture1("Resources/Textures/cloud.png", GL_TEXTURE_2D);

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
    ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferWidth) / framebufferHeigth, nearPlane, farPlane);

    // Luces
    glm::vec3 lightPos0(0.f, 0.f, 1.f);
    // Inicializar uniforms

    // Matrices de transformacion

    core_program.setMat4fv(ViewMatrix, "ViewMatrix");
    core_program.setMat4fv(ProjectionMatrix, "ProjectionMatrix");
    texturesShader.setMat4fv(ViewMatrix, "ViewMatrix");
    texturesShader.setMat4fv(ProjectionMatrix, "ProjectionMatrix");

    // Mandar luz y posicion de la camara al shader

    core_program.setVec3f(lightPos0, "lightPos0");
    core_program.setVec3f(camPosition, "cameraPos");
    texturesShader.setVec3f(lightPos0, "lightPos0");
    texturesShader.setVec3f(camPosition, "cameraPos");

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Update input
        glfwPollEvents();

        // Update
        updateInput(window);

        // Actualizar posicion, rotacion, escala
        //Muppet[9].rotate(glm::vec3(0.f, 0.f, 1.f));

        for (int i = 0; i < 19; i++) {
            updateInput(window, &Muppet[i]);
        }
        // Draw

        // Draw_clear
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        // Usar programa (shader)


        // Active texture

        //glUniform1i(glGetUniformLocation(texturesShader, "texture0"), 0);

        //core_program.use();

        // Update uniforms

        // Mantener relacionde aspecto
        glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeigth);

        ProjectionMatrix = glm::mat4(1.f);
        ProjectionMatrix = glm::perspective(glm::radians(fov), static_cast<float>(framebufferWidth) / framebufferHeigth, nearPlane, farPlane);

        // Actualizar
        core_program.setMat4fv(ProjectionMatrix, "ProjectionMatrix");
        texturesShader.setMat4fv(ProjectionMatrix, "ProjectionMatrix");
        // Draw_draw

        for (int i = 2; i < 19; i++) {
            Muppet[i].render(&core_program);
        }

        texturesShader.use();
        glActiveTexture(GL_TEXTURE0);
        texture0.bind();
        texturesShader.set1i(GL_TEXTURE0, "texture0");
        Muppet[0].render(&texturesShader);
        texture0.unbind();

        texturesShader.use();
        glActiveTexture(GL_TEXTURE1);
        texture1.bind();
        texturesShader.set1i(GL_TEXTURE1, "texture0");
        Muppet[1].render(&texturesShader);
        texture1.unbind();
        // Draw_endDraw
        glfwSwapBuffers(window);
        glFlush();

        glBindVertexArray(0);

    }
    glfwDestroyWindow(window);

    glfwTerminate();
    return 0;
}

//#include "header.cpp"