// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "autoescuela.h"
//==========================>   EJERCICIO 37 <==========================//

/*COSTE:
 
 
 */

bool resuelveCaso() {
    std::string orden, alum, prof;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;
    
    autoescuela AE;
    
    // se lee cada operación y sus argumentos, se ejecuta sobre la autoescuela,
    // y se muestra el resultado (en caso de haberlo)
    while (orden != "FIN") {
        try {
            if (orden == "alta") {
                std::cin >> alum >> prof;
                AE.alta(alum, prof);
            } else if (orden == "es_alumno") {
                std::cin >> alum >> prof;
                if (AE.es_alumno(alum, prof))
                    std::cout << alum << " es alumno de " << prof << '\n';
                else
                    std::cout << alum << " no es alumno de " << prof << '\n';
            } else if (orden == "puntuacion") {
                std::cin >> alum;
                int puntos = AE.puntuacion(alum);
                std::cout << "Puntuacion de " << alum << ": " << puntos << '\n';
            } else if (orden == "actualizar") {
                std::cin >> alum >> punt;
                AE.actualizar(alum, punt);
            } else if (orden == "examen") {
                std::cin >> prof >> punt;
                std::cout << "Alumnos de " << prof << " a examen:\n";
                for (auto const& a : AE.examen(prof, punt)) {
                    std::cout << a << '\n';
                }
            } else if (orden == "aprobar") {
                std::cin >> alum;
                AE.aprobar(alum);
            }
        } catch (std::domain_error e) {
            std::cout << "ERROR" << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "------\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda37.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    while (resuelveCaso())
        ;
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
