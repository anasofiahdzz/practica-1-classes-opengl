#include "Torneo.h"
#include "Batallas.h"
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>  
#include <vector>

// ronda (helper)
static std::string nombreRondaSegunTam(size_t n) {
    if (n == 16) return "--- Octavos de final ---";
    if (n == 8 ) return "--- Cuartos de final ---";
    if (n == 4 ) return "--- Semifinales ---";
    if (n == 2 ) return "--- Final ---";
    std::ostringstream ss;
    ss << "--- Ronda (" << n << " participantes) ---";
    return ss.str();
}

// (helper) lee el ultimo ganador en resultados.txt
static std::string leerUltimoGanadorDesdeResultados(const std::string& ruta = "resultados.txt") {
    std::ifstream in(ruta);
    if (!in) return std::string();
    std::string line;
    std::string lastWinner;
    const std::string prefix = "El ganador de la batalla es: ";
    while (std::getline(in, line)) {
        auto pos = line.find(prefix);
        if (pos != std::string::npos) {
            lastWinner = line.substr(pos + prefix.size());
        }
    }
    return lastWinner;
}

void torneo(std::vector<Monstruo>& participantes){
    std::vector<Monstruo> ronda = participantes;
    std::vector<Monstruo> ganadores;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> tipoBatallaDist(0, 2); 

    while (ronda.size() > 1) {
        std::cout << nombreRondaSegunTam(ronda.size()) << std::endl;
        ganadores.clear();

        std::shuffle(ronda.begin(), ronda.end(), gen);

        for (size_t i = 0; i < ronda.size(); i += 2) {
            Monstruo& m1 = ronda[i];
            Monstruo& m2 = ronda[i + 1];

/*se elige tipo*/
        char tipoBatalla;
        switch(tipoBatallaDist(gen)) {
            case 0: tipoBatalla = 'f'; break;
            case 1: tipoBatalla = 'i'; break;
            case 2: tipoBatalla = 'e'; break;
        }

        Monstruo ganador = Batalla::enfrenta(m1, m2, tipoBatalla);

            std::cout << m1.getEspecie() << " " << m1.getNombre()
                 << " vs " << m2.getEspecie() << " " << m2.getNombre()
                 << " → Gana " << ganador.getNombre() << std::endl;

            ganadores.push_back(ganador);
        }

        ronda = ganadores;
    }

    if (!ronda.empty())
    {
        std::cout << "Campeón: " << ronda[0].getNombre() << std::endl;
    }
}
