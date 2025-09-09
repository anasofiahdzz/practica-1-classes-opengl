#include <iostream>
#include "Monstruo.h"

// Declaramos la función enfrenta del namespace Batalla
namespace Batalla {
    void enfrenta(const Monstruo& m1, const Monstruo& m2, char atributo);
}

int main() {
    std::cout << "MONSTER TOURNAMENT!!!\n";

    Orco grommash("Grommash", 80, 60, 30);
    Dragon alduin("Alduin", 50, 40, 90);

    grommash.mostrarAtributos();
    alduin.mostrarAtributos();

    Batalla::enfrenta(grommash, alduin, 'f');

    return 0;
}
