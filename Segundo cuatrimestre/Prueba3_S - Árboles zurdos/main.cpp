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
bool zurdo(bintree<T>const& arbol, int& numDescendientes) {
    
    if(arbol.empty()){
        numDescendientes = 0;
        return true;
    }else if(arbol.left().empty() && arbol.right().empty()){
        numDescendientes = 1;
        return true;
    }else{
        int numDescendientesIzq, numDescendientesDer;
        
        
        bool esZurdoIzq = zurdo(arbol.left(), numDescendientesIzq);
        bool esZurdoDer = zurdo(arbol.right(), numDescendientesDer);
        numDescendientes = (numDescendientesIzq + numDescendientesDer) + 1;
        
        bool cumpleDescendiente = numDescendientesIzq > (numDescendientes - 1)/2;
        
        
        return esZurdoIzq && esZurdoDer && cumpleDescendiente;
    }
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol;
    arbol = leerArbol('.');
    
    int numDescendientes;
    bool esZurdo = zurdo(arbol, numDescendientes);
    // escribir sol
    
    if(esZurdo){
        std::cout << "SI" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/prueba3_ser.txt");
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
