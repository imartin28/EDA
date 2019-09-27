// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "mezclarLista.h"

//==========================>   EJERCICIO 11 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    
    
    mezclarLista<int> lista1;
    mezclarLista<int> lista2;
    int numero;
    std::cin >> numero;
    
    while(numero != 0){
        lista1.push(numero);
        std::cin>> numero;
    }
    
    std::cin >> numero;
    
    while(numero != 0){
        lista2.push(numero);
        std::cin >> numero;
    }
    
    lista1.mezclar(lista2);
    
    // escribir sol
    std::cout << lista1 << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda11.txt");
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
