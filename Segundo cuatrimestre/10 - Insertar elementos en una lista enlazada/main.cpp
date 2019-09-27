// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "insertarLista.h"

//==========================>   EJERCICIO 10 <==========================//

/*COSTE:
 
 
 */


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem_listaPrincipal;
    std::cin >> numElem_listaPrincipal;
    
    if (! std::cin)
        return false;
    
    insertarLista<int> listaPrincipal;
    int elem_listaPrincipal;
    
    
    
    for(int i = 0; i < numElem_listaPrincipal; ++i){
        std::cin >> elem_listaPrincipal;
        listaPrincipal.push(elem_listaPrincipal);
    }
    
    insertarLista<int> listaInsertar;
    int numElem_aInsertar, posicion, elem_listaInsertar;
    
    std::cin >> numElem_aInsertar >> posicion;
    
    for(int i = 0; i < numElem_aInsertar; ++i){
        std::cin >> elem_listaInsertar;
        listaInsertar.push(elem_listaInsertar);
    }
    
    
    listaPrincipal.insertar(listaInsertar, posicion);
    // escribir sol
    std::cout << listaPrincipal << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda10.txt");
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
