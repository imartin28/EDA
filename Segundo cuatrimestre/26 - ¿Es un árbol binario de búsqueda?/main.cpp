// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits>
#include "bintree_eda.h"



//==========================>   EJERCICIO 26 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
template <typename T>
void arbolBinarioBusqueda(bintree<T>const& arbol, bool& esArbolBinario, int& minArbol, int& maxArbol) {
    
    if(arbol.empty()){
        esArbolBinario = true;
        minArbol = INT_MAX;
        maxArbol = INT_MIN;
        
    }else if(arbol.left().empty() && arbol.right().empty()){
        esArbolBinario = true;
        minArbol = arbol.root();
        maxArbol = arbol.root();
    }else{
        bool esArbolBinarioIzq, esArbolBinarioDer;
        int minArbolIzq, minArbolDer;
        int maxArbolIzq, maxArbolDer;
        int valorMinArbol, valorMaxArbol;
        
        arbolBinarioBusqueda(arbol.left(), esArbolBinarioIzq, minArbolIzq, maxArbolIzq);
        arbolBinarioBusqueda(arbol.right(), esArbolBinarioDer, minArbolDer, maxArbolDer);
        
        maxArbol = std::max(arbol.root(), std::max(maxArbolIzq, maxArbolDer));
        minArbol = std::min(arbol.root(), std::min(minArbolIzq, minArbolDer));
        
        if(arbol.root() > maxArbolIzq && arbol.root() < minArbolDer){
            esArbolBinario = true;
        }else{
            esArbolBinario = false;
        }
     
        
        
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol;
    arbol = leerArbol(-1);
    
    bool esArbolBinario = false;
    int minArbol, maxArbol;
    arbolBinarioBusqueda(arbol, esArbolBinario, minArbol, maxArbol);
    // escribir sol
    if(esArbolBinario){
        std::cout << "SI" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda26.txt");
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
