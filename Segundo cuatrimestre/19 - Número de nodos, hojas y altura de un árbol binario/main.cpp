// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
//==========================>   EJERCICIO 19 <==========================//

/*COSTE:
 
 
 */
template<typename T>
int numNodos(bintree<T> const& arbol){
    
    if(arbol.empty()){
        return 0;
    }else if(arbol.left().empty() && arbol.right().empty() ){
        return 1;
    }else{
        
        
        int nodosArbolIzq, nodosArbolDer;
        
        nodosArbolIzq = numNodos(arbol.left());
        nodosArbolDer = numNodos(arbol.right());
        
        return (nodosArbolIzq + nodosArbolDer) + 1;
    }
    
}

template<typename T>
int numHojas(bintree<T>const& arbol){
    if(arbol.empty()){
        return 0;
        
    }else if(arbol.left().empty() && arbol.right().empty()){
        return 1;
        
    }else{
        int numHojasIzq, numHojasDer;
        
        numHojasIzq = numHojas(arbol.left());
        numHojasDer = numHojas(arbol.right());
        
        return numHojasIzq + numHojasDer;
    }
}


// función que resuelve el problema
template<typename T>
int altura(bintree<T> const& arbol) {
    if(arbol.empty()){
        return 0;
    }else{
        return std::max(altura(arbol.left()), altura(arbol.right())) + 1;
    }
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree<char> arbol;
    
    arbol = leerArbol('.');
    
    std::cout << numNodos(arbol) << ' ' << numHojas(arbol) << ' ' <<  altura(arbol) << std::endl;
    
    
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda19.txt");
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
