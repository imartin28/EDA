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
template<typename T>
void genealogico(bintree<T> const& arbol, bool& esGenealogico, int& numGeneraciones, int& edad) {
    
    if(arbol.empty()){
        esGenealogico = true;
        numGeneraciones = 0;
        edad = 0;
    }else if(arbol.left().empty() && arbol.right().empty()){
        esGenealogico = true;
        numGeneraciones = 1;
        edad = arbol.root();
        
    }else{
        bool esGenealogicoIzq, esGenealogicoDer;
        int numGeneracionesIzq, numGeneracionesDer;
        int edadHijoIzq, edadHijoDer;
        bool condicionPadre;
        bool condicionHijos;
        
        genealogico(arbol.left(), esGenealogicoIzq, numGeneracionesIzq, edadHijoIzq);
        genealogico(arbol.right(), esGenealogicoDer, numGeneracionesDer, edadHijoDer);
        
        
        condicionPadre = arbol.root() - edadHijoIzq >= 18 && arbol.root() - edadHijoDer >= 18;
        condicionHijos = abs(edadHijoDer - edadHijoIzq) >= 2;
        
        
        esGenealogico = condicionPadre && condicionHijos && esGenealogicoIzq && esGenealogicoDer;
        
        edad = arbol.root();
        numGeneraciones = std::max(numGeneracionesIzq, numGeneracionesDer) + 1;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    bintree<int> arbol;
    arbol = leerArbol(-1);
    
    bool esGenealogico;
    int numGeneraciones, edadHijo;
    
    genealogico(arbol, esGenealogico, numGeneraciones, edadHijo);
    // escribir sol
    if(esGenealogico){
        std::cout << "SI" << ' ' << numGeneraciones << std::endl;
    }else{
        std::cout << "NO" << std::endl;
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/prueba2_ser.txt");
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
