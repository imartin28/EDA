// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

//==========================>   EJERCICIO 21 <==========================//

/*COSTE:
 
 
 */

template <typename T>
T minimo(bintree<T>const& arbol) {
    
    T minimo = arbol.root();
    
    for(auto it = arbol.begin(); it != arbol.end(); ++it){
        if(*it < minimo){
            minimo = *it;
        }
    }
    return minimo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    char tipoDeArbol;
    std::cin >> tipoDeArbol;
    
    
    if (! std::cin)
        return false;
    std::string caracterArbolVacioPalabras = "#";
    if(tipoDeArbol == 'N'){
        bintree<int> arbolNumeros;
        arbolNumeros = leerArbol(-1);
        std::cout << minimo(arbolNumeros);
        
    }else{
        bintree<std::string> arbolLetras;
        arbolLetras = leerArbol(caracterArbolVacioPalabras);
        std::cout << minimo(arbolLetras);
    }
    
    std::cout << std::endl;
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda21.txt");
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
