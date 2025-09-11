// Torneo.cpp
#include "Torneo.h"
#include "Batallas.h"
#include <fstream>
#include <random>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>  

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

void torneo(std::vector<Monstruo>& participantes) {
    // archivo resumen del torneo 
    std::ofstream outTorneo("resultados_torneo.txt", std::ios::trunc);
    if (!outTorneo) {
        std::cerr << "No se puede crear resultados_torneo.txt\n";
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distTipo(0,2); // 0->f,1->i,2->e
    const char tipos[3] = {'f','i','e'};
    std::uniform_int_distribution<int> coin(0,1); // para desempates si Batalla escribió "Empate"

    // participantes 
    std::vector<Monstruo> rondaActual = participantes;

    while (rondaActual.size() > 1) {
        size_t n = rondaActual.size();
        outTorneo << nombreRondaSegunTam(n) << "\n";

        // participantes random
        std::shuffle(rondaActual.begin(), rondaActual.end(), gen);

        std::vector<Monstruo> siguiente;
        siguiente.reserve(n / 2);

        for (size_t i = 0; i + 1 < n; i += 2) {
            Monstruo& m1 = rondaActual[i];
            Monstruo& m2 = rondaActual[i+1];

            char tipoBat = tipos[distTipo(gen)];

            // Ejecuta la batalla
            Batalla::enfrenta(m1, m2, tipoBat);

            // Lee el ganador que dejó Batalla
            std::string ganadorNombre = leerUltimoGanadorDesdeResultados("resultados.txt");

            // desempatar si hay empate
            if (ganadorNombre.empty() || ganadorNombre == "Empate") {
                ganadorNombre = (coin(gen) == 0) ? m1.getNombre() : m2.getNombre();
                outTorneo << m1.getEspecie() << " " << m1.getNombre()
                          << " vs " << m2.getEspecie() << " " << m2.getNombre()
                          << " -> Empate, desempate aleatorio: " << ganadorNombre << "\n";
            } else {
                outTorneo << m1.getEspecie() << " " << m1.getNombre()
                          << " vs " << m2.getEspecie() << " " << m2.getNombre()
                          << " -> Gana " << ganadorNombre << "\n";
            }

            // agregar al vector siguiente al objeto ganador
            if (ganadorNombre == m1.getNombre()) {
                siguiente.push_back(m1);
            } else {
                siguiente.push_back(m2);
            }
        } 

        outTorneo << "\n";
        rondaActual = std::move(siguiente);
    } 

    if (!rondaActual.empty()) {
        outTorneo << "Campeón: " << rondaActual.front().getNombre() << "\n";
        std::cout << "Campeón: " << rondaActual.front().getNombre() << "\n";
    } else {
        outTorneo << "Error: no hay participantes al final del torneo\n";
    }

    outTorneo.close();
}
