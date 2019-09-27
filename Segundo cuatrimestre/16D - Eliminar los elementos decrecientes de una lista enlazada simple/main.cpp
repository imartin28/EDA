// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "eliminarElemDecreciente.h"
#include "Horas.h"

//==========================>   EJERCICIO 16D <==========================//

/*COSTE:
 
 
 */



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    std::cin>> numero;
    Horas horas;
    if (numero == 0)
        return false;
    
    eliminarElemCreciente<Horas> cola;
    for(int i = 0; i < numero; ++i){
        std::cin >> horas;
        cola.push(horas);
    }
    
    cola.eliminar();
    
    std::cout << cola << std::endl;
   
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda16D.txt");
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
