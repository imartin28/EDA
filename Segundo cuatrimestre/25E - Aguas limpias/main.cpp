// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "aguasLimpias.h"

//==========================>   EJERCICIO 25E <==========================//

/*COSTE:
    T(n) = c0 si n = 0,1
           2* T(n/2) + c1
 
 
 Pertenciendo al orden de O(n) siendo n el numero de elementos del arbol
 
 */



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    aguasLimpias<int> arbol;
    int vacio = -1;
    int nivelCaudal = 0;
    arbol = leerArbol_ext(vacio);
    
    std::cout << arbol.numTramosNavegables(nivelCaudal) << std::endl;
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda25E.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
