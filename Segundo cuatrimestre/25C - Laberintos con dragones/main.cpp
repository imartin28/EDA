// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintreeDragones.h"


//==========================>   EJERCICIO 25C <==========================//

/*COSTE:
 Funcion recursiva:
 T(n) = c0 si n = 0, 1
        2*T(n/2) + c1 en otro caso
 
 
 Perteneciendo al orden de O(n) siendo n el numero de elementos del arbol
 
 */

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string vacio = "...";
    Dragones<std::string> arbol = leerArbol_ext(vacio);
    int contDragones = 0;
    
   
    
    std::cout <<  arbol.hojaConMenorNumDragones(contDragones) << ' ';
    std::cout << contDragones  << std::endl;
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda25C.txt");
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
