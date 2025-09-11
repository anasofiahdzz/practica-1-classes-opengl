#include "Monstruo.h"
#include "Batallas.h"
#include "Torneo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


// Cargar monstruos desde torneo.txt
std::vector<Monstruo> cargarMonstruos(const std::string& archivo) {
    std::ifstream file(archivo);
    std::vector<Monstruo> monstruos;
    std::string linea;

    while (std::getline(file, linea)) {
        std::stringstream ss(linea);
        char especie;
        std::string nombre;
        int fuerza, agilidad, inteligencia;

        ss >> especie >> nombre >> fuerza >> agilidad >> inteligencia;

        // Crear monstruo en base a especie
        switch (especie) {
            case 'O': monstruos.emplace_back(nombre, fuerza, agilidad, inteligencia, especie); break;
            case 'D': monstruos.emplace_back(nombre, fuerza, agilidad, inteligencia, especie); break;
            case 'T': monstruos.emplace_back(nombre, fuerza, agilidad, inteligencia, especie); break;
            case 'V': monstruos.emplace_back(nombre, fuerza, agilidad, inteligencia, especie); break;
            case 'E': monstruos.emplace_back(nombre, fuerza, agilidad, inteligencia, especie); break;
            case 'H': monstruos.emplace_back(nombre, fuerza, agilidad, inteligencia, especie); break;
        }
    }

    return monstruos;
}

// las batallas de batallas.txt
void cargarBatallas(const std::string& archivo, const std::vector<Monstruo>& monstruos) {
    std::ifstream in(archivo);
    std::string nombre1, nombre2;
    char tipo;

    while (in >> nombre1 >> nombre2 >> tipo) {
        const Monstruo* m1 = nullptr;
        const Monstruo* m2 = nullptr;

        // Buscar monstruos por nombre
        for (const auto& m : monstruos) {
            if (m.getNombre() == nombre1) m1 = &m;
            if (m.getNombre() == nombre2) m2 = &m;
        }

        if (m1 && m2) {
            Batalla::enfrenta(*m1, *m2, tipo);
        } else {
            std::cerr << "Error: no se encontraron los monstruos " 
                      << nombre1 << " o " << nombre2 << " en torneo.txt\n";
        }
    }
}


int main() {
    std::cout << "MONSTER TOURNAMENT!!!\n";
    std::cout << "1. Batalla individual\n";
    std::cout << "2. Torneo\n";
    std::cout << "Elige una opción: ";
    int opcion;
    std::cin >> opcion;

    // Cargar todos los monstruos
    auto monstruos = cargarMonstruos("torneo.txt");
    
    std::vector<Monstruo> participantes = cargarMonstruos("torneo.txt");
    torneo(participantes);
    return 0;

    if (opcion == 1) {
        cargarBatallas("batallas.txt", monstruos);
    }
    else if (opcion == 2) {
        torneo(monstruos); //es de torneo.cpp
    }
    else {
        std::cout << "Opción inválida.\n";
    }

    return 0;


    std::ifstream archivo("batallas.txt");
    if (!archivo) {
        std::cerr << "Error: no se pudo abrir batallas.txt\n";
        return 1;
    }

    char especie1, especie2, tipo;
    std::string nombre1, nombre2;
    int f1, a1, i1;
    int f2, a2, i2;

    // Leer cada batalla desde el archivo
    while (archivo >> especie1 >> nombre1 >> f1 >> a1 >> i1
                   >> especie2 >> nombre2 >> f2 >> a2 >> i2 >> tipo) {

        // se crean monstruos en base a su especie
        Monstruo* m1 = nullptr;
        Monstruo* m2 = nullptr;

        switch (especie1) {
            case 'O': m1 = new Orco(nombre1, f1, a1, i1); break;
            case 'D': m1 = new Dragon(nombre1, f1, a1, i1); break;
            case 'T': m1 = new Troll(nombre1, f1, a1, i1); break;
            case 'V': m1 = new Vampiro(nombre1, f1, a1, i1); break;
            case 'E': m1 = new Esqueleto(nombre1, f1, a1, i1); break;
            case 'H': m1 = new Hechicero(nombre1, f1, a1, i1); break;
        }

        switch (especie2) {
            case 'O': m2 = new Orco(nombre2, f2, a2, i2); break;
            case 'D': m2 = new Dragon(nombre2, f2, a2, i2); break;
            case 'T': m2 = new Troll(nombre2, f2, a2, i2); break;
            case 'V': m2 = new Vampiro(nombre2, f2, a2, i2); break;
            case 'E': m2 = new Esqueleto(nombre2, f2, a2, i2); break;
            case 'H': m2 = new Hechicero(nombre2, f2, a2, i2); break;
        }

        if (m1 && m2) {
            Batalla::enfrenta(*m1, *m2, tipo);
        }

        delete m1;
        delete m2;
    }

    archivo.close();
    return 0;
}
