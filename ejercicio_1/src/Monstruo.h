#ifndef MONSTRUO_H
#define MONSTRUO_H

#include <string>

class Monstruo {
private:
    std::string nombre;
    int fuerza;
    int agilidad;
    int inteligencia;
    char especie;

public:
    // Constructor
    Monstruo(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie);

    // Getters
    std::string getNombre() const;
    int getFuerza() const;
    int getAgilidad() const;
    int getInteligencia() const;
    char getEspecie() const;

    void mostrarAtributos() const;
};

// ---- Clases derivadas ----
class Orco : public Monstruo {
public:
    Orco(const std::string& nombre, int fuerza, int agilidad, int inteligencia)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'O') {}
};

class Dragon : public Monstruo {
public:
    Dragon(const std::string& nombre, int fuerza, int agilidad, int inteligencia)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'D') {}
};

class Troll : public Monstruo {
public:
    Troll(const std::string& nombre, int fuerza, int agilidad, int inteligencia)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'T') {}
};

class Vampiro : public Monstruo {
public:
    Vampiro(const std::string& nombre, int fuerza, int agilidad, int inteligencia)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'V') {}
};

class Esqueleto : public Monstruo {
public:
    Esqueleto(const std::string& nombre, int fuerza, int agilidad, int inteligencia)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'E') {}
};

class Hechicero : public Monstruo {
public:
    Hechicero(const std::string& nombre, int fuerza, int agilidad, int inteligencia)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'H') {}
};

#endif
