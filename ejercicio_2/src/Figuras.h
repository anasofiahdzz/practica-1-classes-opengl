#ifndef FIGURAS_H
#define FIGURAS_H

#include "gl.h"
#include <GLFW/glfw3.h>

// Clase base
class Figura {
protected:
    GLuint VAO, VBO;
    int numVertices;
public:
    virtual ~Figura();
    virtual void init() = 0;
    virtual void draw();
};

// Triángulo
class Triangulo : public Figura {
public:
    void init() override;
};

// Cuadrado
class Cuadrado : public Figura {
public:
    void init() override;
};

// Rombo
class Rombo : public Figura {
public:
    void init() override;
};

// Trapecio
class Trapecio : public Figura {
public:
    void init() override;
};

#endif
