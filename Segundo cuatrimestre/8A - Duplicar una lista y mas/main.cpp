// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "listaDuplica.h"

//==========================>   EJERCICIO 8A <==========================//

/*COSTE:
 
 
 */



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    std::cin >> numero;
    if (! std::cin)
        return false;
    
    
    listaDuplica<int> cola;
    
    while(numero != 0){
        cola.push(numero);
        std::cin >> numero;
    }
    
    cola.duplica();
    
    std::cout << cola.size() << std::endl;
    std::cout << cola << std::endl;
    
    std::cin >> numero;
    while(numero != 0){
        cola.push(numero);
        std::cin >> numero;
    }
    
    std::cin >> numero;
    for(int i = 0; i < numero; ++i){
        cola.pop();
    }
    //Dar la vuelta a la cola para saber que esta correcto. Debe dar el mismo resultado.
    /*for (int i = 0; i < cola.size() ; ++i) {
     
     int elem = cola.front(); cola.pop();
     
     cola.push(elem);
     
     }*/
    std::cout << cola.size() << std::endl;
    std::cout << cola << std::endl;
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda8A.txt");
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
