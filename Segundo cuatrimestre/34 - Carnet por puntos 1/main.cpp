// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "carnet_puntos.h"
//==========================>   EJERCICIO 34 <==========================//

/*COSTE:
 
 
 */


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    std::string operacion, dni;
    int puntos;
    
    CarnetPuntos carnet;
    std::cin >> operacion;
    
    if (!std::cin)
        return false;
    
    while(operacion != "FIN"){
        if(operacion == "nuevo"){
            std::cin >> dni;
            try {
                carnet.nuevo(dni);
            } catch (std::domain_error e) {
                std::cout << "ERROR: " << e.what() << std::endl;;
            }
        }else if(operacion == "quitar"){
             std::cin >> dni >> puntos;
            try {
                carnet.quitar(dni, puntos);
                
            }  catch (std::domain_error e) {
                std::cout << "ERROR: " << e.what() << std::endl;;
            }
           
            
            
        }else if(operacion == "consultar"){
            std::cin >> dni;
            try {
                std::cout << "Puntos de " << dni << ": " << carnet.consultar(dni) << std::endl;
            } catch (std::domain_error e) {
                std::cout << "ERROR: " << e.what() << std::endl;
            }
           
        }else if(operacion == "cuantos_con_puntos"){
            std::cin >> puntos;
            
            try {
                int numConductores = carnet.cuantos_con_puntos(puntos);
                std::cout << "Con " << puntos << " puntos hay " << numConductores << std::endl;
            } catch (std::domain_error e) {
               std::cout << "ERROR: " << e.what() << std::endl;
            }
            
        }
        
        std::cin >> operacion;
        
    }
    
    std::cout << "---" << std::endl;
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda34.txt");
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
