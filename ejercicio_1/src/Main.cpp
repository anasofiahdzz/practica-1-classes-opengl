#include <iostream>
#include <fstream>
#include "Monstruo.h"
#include "Batallas.cpp"

int main() {
    std::cout << "MONSTER TOURNAMENT!!!\n";

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

        // Crear los monstruos según su especie
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
