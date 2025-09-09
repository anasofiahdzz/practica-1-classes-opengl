#include <iostream> /*ops de entrada y salida*/
#include <random> /*para las batallas aleatorias*/
#include <string>
#include <fstream>  // para usar std::ofstream
#include "Monstruo.h"


/*2. MODELADO DE BATALLAS*/
class Batalla {
    public:
    static void enfrenta(const Monstruo& monstruo1, const Monstruo& monstruo2, char tipoBatalla){
        int puntos1 = 0, puntos2 = 0;
        std::string nombreBatalla;

        if (tipoBatalla == 'f') /*fisica*/ {
            puntos1 = monstruo1.getFuerza() + monstruo1.getAgilidad();
            puntos2 = monstruo2.getFuerza() + monstruo2.getAgilidad();
            //std::cout << "Batalla Fisica \n";
            nombreBatalla = "Batalla Fisica";
        }
        else if (tipoBatalla == 'i') /*ingenio*/ {
            puntos1 = monstruo1.getAgilidad() + monstruo1.getInteligencia();
            puntos2 = monstruo2.getAgilidad() + monstruo2.getInteligencia();
            //std::cout << "Batalla de Ingenio \n";
            nombreBatalla = "Batalla de Ingenio";
        }
        else if (tipoBatalla == 'e') /*espiritual*/
        {
            puntos1 = monstruo1.getFuerza() + monstruo1.getInteligencia();
            puntos2 = monstruo2.getFuerza() + monstruo2.getInteligencia();
            //std::cout << "Batalla Espiritual \n";
            nombreBatalla = "Batalla Espiritual";
        }

        /*generar los archivos .txt*/
        std::ofstream archivoBatallas("batallas.txt", std::ios::app); /*app abre el archivo en modo append escribe al final*/
        std::ofstream archivoResultados("resultados.txt", std::ios::app);

        /*guardar los datos en Batallas.txt*/
        archivoBatallas << monstruo1.getEspecie() << " " << monstruo1.getNombre() << " "
                        << monstruo1.getFuerza() << " " << monstruo1.getAgilidad() << " " << monstruo1.getInteligencia() << " "
                        << monstruo2.getEspecie() << " " << monstruo2.getNombre() << " "
                        << monstruo2.getFuerza() << " " << monstruo2.getAgilidad() << " " << monstruo2.getInteligencia() << " "
                        << tipoBatalla << "\n";

        /*mostrar en resultados.txt*/
        std::cout << "\n" << nombreBatalla << "\n";
        archivoResultados << "\n" << nombreBatalla << "\n";

        std::cout << monstruo1.getNombre() << " (" << monstruo1.getEspecie() << ") vs "
                  << monstruo2.getNombre() << " (" << monstruo2.getEspecie() << ")\n";
        archivoResultados << monstruo1.getNombre() << " (" << monstruo1.getEspecie() << ") vs "
                          << monstruo2.getNombre() << " (" << monstruo2.getEspecie() << ")\n";

        /*Usando random para las batallas*/
        std::random_device random; //aleatorio

        /*para decidir el ganador*/
        int ganador1 = 0, ganador2 = 0;

        for (int i = 1; i <= 3; i++) /*3 encuentros*/
        {
            /**/
            double probabilidad = double(puntos1) / double(puntos1+puntos2);

            /*generando el random entre 0 y 1*/
            double rd = random() / double(random.max());

            /*se usa << el op de inserccion*/
            std::cout << "\nEncuentro " << i << ": ";
            archivoResultados << "\nEncuentro " << i << ": ";

            if (rd < probabilidad)
            {
                std::cout << monstruo1.getNombre() << " Es el ganador\n";
                archivoResultados << monstruo1.getNombre() << " Es el ganador\n";
                ganador1++;
            }
            else {
                std::cout << monstruo2.getNombre() << " Es el ganador\n";
                archivoResultados << monstruo2.getNombre() << " Es el ganador\n";
                ganador2++;
            }
        }
        
        /*para el ganador final*/
        std::string ganadorFinal;
        if (ganador1 > ganador2) {
            ganadorFinal = monstruo1.getNombre();
            std::cout << "\nEl ganador es: " << monstruo1.getNombre() << "\n";
        }
        else
        {
            ganadorFinal = monstruo2.getNombre();
            std::cout << "\nEl ganador es: " << monstruo2.getNombre() << "\n";
        }

        std::cout << "El ganador de la batalla es: " << ganadorFinal << "\n";
        archivoResultados << "El ganador de la batalla es: " << ganadorFinal << "\n";

        archivoBatallas.close();
        archivoResultados.close();
    }
};