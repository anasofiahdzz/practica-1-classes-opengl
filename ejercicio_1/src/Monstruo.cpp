#include <iostream>
#include <string>

/* 1. MODELADO DE MONSTRUOS*/
/*Clase base*/
class Monstruo
{
private: /*atributos*/
    std::string nombre;
    int fuerza;
    int agilidad;
    int inteligencia;
    char especie; /*O, D, T, V, E, H*/
public:
    Monstruo(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
        : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), especie(especie) {};
    ~Monstruo() = default; /*Constructor*/

    /*getters*/
    std::string getNombre() const { return nombre; }
    int getFuerza() const { return fuerza; }
    int getAgilidad() const { return agilidad; }
    int getInteligencia() const { return inteligencia; }
    char getEspecie() const { return especie;}

    void mostrarAtributos() const;

};

/*constructor*/
Monstruo::Monstruo(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), especie(especie) {}

    /*metodo*/
    void Monstruo::mostrarAtributos() const {
        std::cout << "Nombre: " << nombre << "\n"; /*<< operador de inserccion*/
        std::cout << "Fuerza: " << fuerza << "\n";
        std::cout << "Agilidad: " << agilidad << "\n";
        std::cout << "Inteligencia: " << inteligencia << "\n";
        std::cout << "Especie: " << especie << "\n";
    }

/*Clases derivadas (especies)*/
/*1. O Orco*/ 
class Orco : public Monstruo {
    public:
    Orco(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'O') {}
};

/*2. D Dragon*/
class Dragon : public Monstruo {
    public:
    Dragon(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'D') {}
};

/*3. T Troll*/
class Troll : public Monstruo {
    public:
    Troll(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'T') {}
};

/*4. V Vampiro*/
class Vampiro : public Monstruo {
    public:
    Vampiro(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'V') {}
};

/*5. E Esqueleto*/
class Esqueleto : public Monstruo {
    public:
    Esqueleto(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'E') {}
};

/*6. H Hechicero*/
class Hechicero : public Monstruo {
    public:
    Hechicero(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
        : Monstruo(nombre, fuerza, agilidad, inteligencia, 'H') {}
};








    
