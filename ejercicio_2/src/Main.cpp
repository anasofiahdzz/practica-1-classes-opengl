#include "gl.h"              
#include <GLFW/glfw3.h>
#include <iostream>

// Vertex Shader source code (GLSL 4.10)
const char* vertexShaderSource = R"(
    #version 410 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;
    out vec3 vertexColor;

    void main()
    {
        gl_Position = vec4(aPos, 1.0);
        vertexColor = aColor ;
    }
)";

// Fragment Shader source code (GLSL 4.10)
const char* fragmentShaderSource = R"(
    #version 410 core
    out vec4 FragColor;
    in vec3 vertexColor;

    void main()
    {
        //FragColor = vec4(vec3(1.0,0.0,0.0), 1.0);
        FragColor = vec4(vertexColor, 1.0);
    }
)";

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set OpenGL version to 4.1
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triangle", NULL, NULL);

    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Build and compile the vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Check for shader compile errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Build and compile the fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Link shaders to a shader program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // Delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Set up vertex data and buffers and configure vertex attributes
    /*2 triangulos 4 vertices original comentado*/
    /*    float vertices[] = {
        -1.0f, -1.0f, 0.0f, 1.0f,  0.0f, 0.0f,
         1.0f, -1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
         0.0f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f
    };*/

    /*cuadrado, se debe descomentar la linea de glDrawArrays en el render loop para que pueda ejecutarse*/
    /*    float vertices[] = {
        // primer triángulo
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 
        0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f, 
        0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 

        // triángulo se debe descomentar la linea de glDrawArrays en el render loop para que pueda ejecutarse
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 
        0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f  
    };*/

    /*rombo, se debe descomentar la linea de glDrawArrays en el render loop para que pueda ejecutarse*/
    /*    float vertices[] = {
        // vertices del rombo
        0.0f,  0.6f, 0.0f,   1.0f, 0.0f, 0.0f, // arriba
        0.6f,  0.0f, 0.0f,   0.0f, 1.0f, 0.0f, // derecha
        -0.6f,  0.0f, 0.0f,   0.0f, 0.0f, 1.0f, // izquierda
        0.0f, -0.6f, 0.0f,   1.0f, 1.0f, 0.0f  // abajo
    };*/

    /*trapecio, se debe descomentar la linea de glDrawArrays en el render loop para que pueda ejecutarse*/
    float vertices[] = {
        // vertice arriba izquierda
        -0.3f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  
        // vertice abajo izquierda
        -0.6f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  
        // vertice arriba derecha
        0.3f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  
        // vertice abajo derecha
        0.6f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f   
    };

/* original muchos triangulos
   float vertices[] = {
        -1.0f,  1.0f, 0.0f,
        -1.0f, 0.0f, 0.0f,
         0.0f,  1.0f, 0.0f,
         
         1.0f, -1.0f, 0.0f,
         1.0f, 0.0f, 0.0f,
         0.0f, -1.0f, 0.0f
    };*/

    float colors[] = {
         1.0f,  0.0f, 0.0f,
         0.0f,  1.0f, 0.0f,
         0.0f,  0.0f, 1.0f,
         
         1.0f, 1.0f, 0.0f,
         1.0f, 0.0f, 1.0f,
         0.0f, 1.0f, 1.0f
    };

    /*original*/
    GLuint VBO, VAO;
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    /*para vertices*/
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    /*(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);*/

    // Unbind the VAO
    glBindVertexArray(0);

    GLuint VBOcolor;
    
    glGenBuffers(1, &VBOcolor);

    // Bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBOcolor);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    // Unbind the VAO
    glBindVertexArray(0);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        // Render
        glClearColor(0.0f, 0.3f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw the triangle
        glUseProgram(shaderProgram);
        /*original*/
        glBindVertexArray(VAO);
        
        //triangulo y cuadrado
        /*glDrawArrays(GL_TRIANGLE_STRIP, 0, 6);*/

        /*rombo y trapecio*/
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Deallocate resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Terminate GLFW
    glfwTerminate();
    return 0;
}
