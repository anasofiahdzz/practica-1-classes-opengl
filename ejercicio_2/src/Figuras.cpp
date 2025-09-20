#include "Figuras.h"
#include <iostream>

Figura::~Figura() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Figura::draw() {
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, numVertices);
    glBindVertexArray(0);
}
//triangulo
void Triangulo::init() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, 
        0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f
    };
    numVertices = 3;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

// cuadrado
void Cuadrado::init() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,

        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f
    };
    numVertices = 6;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

// rombo
void Rombo::init() {
    float vertices[] = {
        0.0f,  0.6f, 0.0f,   1.0f, 0.0f, 0.0f, 
        0.6f,  0.0f, 0.0f,   0.0f, 1.0f, 0.0f, 
       -0.6f,  0.0f, 0.0f,   0.0f, 0.0f, 1.0f, 
        0.0f, -0.6f, 0.0f,   1.0f, 1.0f, 0.0f  
    };
    numVertices = 4;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}

// trapecio
void Trapecio::init() {
    float vertices[] = {
        -0.3f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,  
        -0.6f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,  
         0.3f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,  
         0.6f, -0.5f, 0.0f,   1.0f, 1.0f, 0.0f   
    };
    numVertices = 4;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
}
