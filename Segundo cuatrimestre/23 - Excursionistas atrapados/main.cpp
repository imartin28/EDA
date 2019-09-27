// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

//==========================>   EJERCICIO 23 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
template <typename T>
void excursionistas(bintree<T> const& arbol, int& numEquiposRescate, int& numExcursionistasAtrapados) {
    if(arbol.empty()){
        numEquiposRescate = 0;
        numExcursionistasAtrapados = 0;
        
    }else if(arbol.left().empty() && arbol.right().empty()){
        numExcursionistasAtrapados = arbol.root();
        
        if(arbol.root() != 0){
            numEquiposRescate = 1;
        }else{
            numEquiposRescate = 0;
        }
        
    }else{
        int numEquiposRescateIzq, numEquiposRescateDer;
        int numExcursionistasAtrapadosIzq, numExcursionistasAtrapadosDer;
        
        excursionistas(arbol.left(), numEquiposRescateIzq, numExcursionistasAtrapadosIzq);
        excursionistas(arbol.right(), numEquiposRescateDer, numExcursionistasAtrapadosDer);
        
        numEquiposRescate = numEquiposRescateIzq + numEquiposRescateDer;
        
        if(arbol.root() != 0 && numEquiposRescate == 0){
            ++numEquiposRescate;
        }
        
        numExcursionistasAtrapados = std::max(numExcursionistasAtrapadosIzq, numExcursionistasAtrapadosDer) + arbol.root();
        
    }
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol;
    arbol = leerArbol(-1);
    int numEquiposRescate, numExcursionistasAtrapados;
    excursionistas(arbol, numEquiposRescate, numExcursionistasAtrapados);
    std::cout << numEquiposRescate << ' ' << numExcursionistasAtrapados <<  std::endl;
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda23.txt");
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
