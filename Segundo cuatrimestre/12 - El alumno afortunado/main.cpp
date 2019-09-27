// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"

//==========================>   EJERCICIO 12 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(queue<int>& cola_alumnos, int saltos) {
    
    
    int i = 1;
    while(cola_alumnos.size() > 1){
        if(i <= saltos){
            int valor_cima = cola_alumnos.front();
            cola_alumnos.pop();
            cola_alumnos.push(valor_cima);
            ++i;
        }else{
            i = 1;
            cola_alumnos.pop();
        }
        
    }
    
    return cola_alumnos.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numAlumnos, saltos;
    std::cin >> numAlumnos >> saltos;
    
    if (numAlumnos == 0 && saltos == 0)
        return false;
    
    
    
    queue<int> cola_alumnos;
    
    for(int i = 1; i <= numAlumnos; ++i){
        cola_alumnos.push(i);
    }
    
    
    int sol = resolver(cola_alumnos, saltos);
    
    // escribir sol
    std::cout << sol << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda12.txt");
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
