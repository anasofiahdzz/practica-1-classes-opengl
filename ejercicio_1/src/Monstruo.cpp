#include <iostream>
#include "Monstruo.h"

/* 1. MODELADO DE MONSTRUOS*/
/*Clase base*/

/*constructor*/
Monstruo::Monstruo(const std::string& nombre, int fuerza, int agilidad, int inteligencia, char especie)
    : nombre(nombre), fuerza(fuerza), agilidad(agilidad), inteligencia(inteligencia), especie(especie){};

/*getters*/
std::string Monstruo::getNombre() const { return nombre; }
int Monstruo::getFuerza() const { return fuerza; }
int Monstruo::getAgilidad() const { return agilidad; }
int Monstruo::getInteligencia() const { return inteligencia; }
char Monstruo::getEspecie() const {return especie;}

// atributos
void Monstruo::mostrarAtributos() const {
    std::cout << "Nombre: " << nombre
              << ", Fuerza: " << fuerza
              << ", Agilidad: " << agilidad
              << ", Inteligencia: " << inteligencia
              << ", Especie: " << especie
              << std::endl;
}

