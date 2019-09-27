// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

//==========================>   EJERCICIO 22 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
template <typename T>
void calcularDiametro(bintree<T> const& arbol, int& altura, int& diametro) {
    
    if(arbol.empty()){
        altura = 0;
        diametro = 0;
    }else if(arbol.left().empty() && arbol.right().empty()){
        altura = 1;
        diametro = 1;
    }else{
        
        int alturaIzq, alturaDer, diametroIzq, diametroDer;
        
        calcularDiametro(arbol.left(), alturaIzq, diametroIzq);
        calcularDiametro(arbol.right(), alturaDer, diametroDer);
        
        altura = std::max(alturaIzq, alturaDer) + 1;
        diametro = alturaIzq + alturaDer + 1;
       
        diametro = std::max(diametro ,(std::max(diametroIzq, diametroDer)));
        
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree<char> arbol;
    arbol = leerArbol('.');
    int altura, diametro;
    calcularDiametro(arbol, altura, diametro);
    // escribir sol
    std::cout << diametro << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda22.txt");
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
