// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"
#include "borrarUnoDeCadaDos.h"

//==========================>   EJERCICIO 16C <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numeroDeHoras;
    std::cin >> numeroDeHoras;
    
    if (numeroDeHoras == 0)
        return false;
    Horas hora;
    borrarUnoDeCadaDos<Horas> lista;
    
    for(int i = 0; i < numeroDeHoras; ++i){
        std::cin >> hora;
        lista.push(hora);
        
    }
    
    lista.borrar();
    
    std::cout << lista << std::endl;
    
    
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda16C.txt");
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
