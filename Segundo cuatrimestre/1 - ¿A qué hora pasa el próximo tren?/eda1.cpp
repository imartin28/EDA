// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Horas.h"

//==========================>   EJERCICIO 1 <==========================//

/*COSTE:*/
 
 


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    
    int numTrenes, numHorasAconsultar;
    std::cin >> numTrenes >> numHorasAconsultar;
    
    if (numTrenes == 0 && numHorasAconsultar == 0)
        return false;
    
    std::vector<Horas> v_horas(numTrenes);
    
    Horas hora;
    
    for(int i = 0; i < numTrenes; ++i){
        std::cin >> hora;
        v_horas[i] = hora;
    }
    
    for(int i = 0; i < numHorasAconsultar; ++i){
        try{
            std::cin >> hora;
            auto it = std::lower_bound(v_horas.begin(), v_horas.end(), hora);
            if(it == v_horas.end())
                std::cout << "NO" << std::endl;
            else
                std::cout << *it << std::endl;
            
        }catch(std::invalid_argument e){
            std::cout << "ERROR" << std::endl;
        }
       
    }
     std::cout << "---" << std::endl;
    
    //TipoSolucion sol = resolver(datos);
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda1.txt");
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
