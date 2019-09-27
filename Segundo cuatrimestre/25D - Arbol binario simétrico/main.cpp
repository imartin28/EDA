// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"
#include "bintree_eda.h"

//==========================>   EJERCICIO 25D <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema

bool esArbolSimetrico(bintree<char> const& arbol_1, bintree<char> const& arbol_2 ){
   
    if(arbol_1.empty() && arbol_2.empty()){
        return true;
    }else if(arbol_1.empty() || arbol_2.empty()){
        return false;
    }else if(!arbol_1.left().empty() && !arbol_1.right().empty() && !arbol_2.left().empty() && !arbol_2.right().empty()){
        
        return esArbolSimetrico(arbol_1.left(), arbol_2.right()) && esArbolSimetrico(arbol_1.right(), arbol_2.left());
       
    }else{
        
       
    }
    
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree<char> arbol;
    arbol = leerArbol('.');
    
    bool esSimetrico = esArbolSimetrico(arbol, arbol);
    // escribir sol
    if(esSimetrico){
        std::cout << "SI" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda25D.txt");
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
