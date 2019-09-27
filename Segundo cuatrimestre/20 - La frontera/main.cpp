// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

//==========================>   EJERCICIO 20 <==========================//

/*COSTE:
 
 
 */
template <typename T>
// función que resuelve el problema
void resolver(bintree<T> const& arbol, std::vector<T>& v_hojas) {
    
    if(arbol.empty()){
        v_hojas.push_back(-1);
    }else if(arbol.left().empty() && arbol.right().empty()){
        v_hojas.push_back(arbol.root());
    }else{
        resolver(arbol.left(), v_hojas);
        resolver(arbol.right(), v_hojas);
        
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree<int> arbol;
    arbol = leerArbol(-1);
    std::vector<int> v_hojas;
    
    resolver(arbol, v_hojas);
    // escribir sol
    for(int i = 0; i < v_hojas.size(); ++i){
        if(v_hojas[i] != -1){            
             std::cout << v_hojas[i] << ' ';
        }
       
    }
    std::cout << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda20.txt");
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
