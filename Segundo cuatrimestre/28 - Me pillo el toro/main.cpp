// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "treemap_eda.h"

//==========================>   EJERCICIO 28 <==========================//

/*COSTE:
 
 nlog(n) siendo n el numero de ejercicios
 
 */


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numEjercicios;
    std::string nombreAlumno, calificacion;
    std::cin >> numEjercicios;

    
    if (numEjercicios == 0)
        return false;
    map<std::string, int> mapa;
    
    for(int i = 0; i < numEjercicios; ++i){
        std::cin.ignore();
        getline(std::cin, nombreAlumno);
        std::cin >> calificacion;
        if(calificacion == "INCORRECTO"){
            mapa[nombreAlumno] -= 1;
        }else{
            mapa[nombreAlumno] += 1;
        }
    }
    
    for(auto it = mapa.begin(); it != mapa.end(); ++it){
        if(it->valor != 0){
              std::cout << (*it).clave << ", " << it->valor << std::endl;
        }
      
       
    }
     std::cout << "---" << std::endl;
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda28.txt");
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
