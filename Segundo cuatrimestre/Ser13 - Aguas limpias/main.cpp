// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

//==========================>   EJERCICIO __ <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
template <typename T>
void aguasLimpias(bintree<T> const& arbol, int& caudal, int & num_tramos_navegables) {
    if(arbol.empty()){
        caudal = 0;
        num_tramos_navegables = 0;
    }else if(arbol.left().empty() && arbol.right().empty()){
        caudal = 1;
        num_tramos_navegables = 0;
    }else{
        int caudalIzq, caudalDer, num_tramos_navegablesIzq, num_tramos_navegablesDer;
        
        aguasLimpias(arbol.left(), caudalIzq,  num_tramos_navegablesIzq);
        aguasLimpias(arbol.right(), caudalDer, num_tramos_navegablesDer);
        
        
        caudal = caudalIzq + caudalDer - arbol.root();
        num_tramos_navegables = num_tramos_navegablesIzq + num_tramos_navegablesDer;
        
        if(caudalIzq >= 3){
            ++num_tramos_navegables;
        }
        
        if(caudalDer >= 3){
            ++num_tramos_navegables;
        }
        
     
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree<int> arbol;
    arbol = leerArbol(-1);
    int caudal = 0,  num_tramos_navegables = 0;
    
    aguasLimpias(arbol, caudal, num_tramos_navegables);
    // escribir sol
    
    std::cout << num_tramos_navegables << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/ser13.txt");
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
