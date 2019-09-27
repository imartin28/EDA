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
bool isSumTree(bintree<T> const& arbol, int& suma) {
    if(arbol.empty()){
        suma = 0;
        return true;
    }else if(arbol.left().empty() && arbol.right().empty()){
        suma = arbol.root();
        return true;
    }else{
        int sumaIzq, sumaDer;
        
        
        bool esSumTreeIzq = isSumTree(arbol.left(), sumaIzq);
        bool esSumTreeDer = isSumTree(arbol.right(), sumaDer);
        
        suma = (sumaIzq + sumaDer) + arbol.root();
        
        bool cumpleCondicionSuma  = sumaIzq + sumaDer == arbol.root();
        
        return cumpleCondicionSuma && esSumTreeIzq && esSumTreeDer;
        
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol;
    arbol = leerArbol(-1);
    int suma;
    bool esSumTree = isSumTree(arbol, suma);
   
    if(esSumTree){
        std::cout << "SI" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/datos.txt");
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
