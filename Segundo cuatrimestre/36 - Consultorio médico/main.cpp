// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "fechas.h"
#include "consultorio.h"
#include <list>

//==========================>   EJERCICIO 36 <==========================//

/*COSTE:
 
 
 */



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numOperaciones;
    std::cin >> numOperaciones;
    if (! std::cin)
        return false;
    consultorio consul;
    int dia, hora, minuto;
    std::string operacion, medico, paciente;
    
    for(int i = 0; i < numOperaciones; ++i){
        std::cin >> operacion;
        if(operacion == "nuevoMedico"){
            std::cin >> medico;
            
            consul.nuevoMedico(medico);
            
            
        }else if(operacion == "pideConsulta"){
            std::cin >> paciente >> medico >> dia >> hora >> minuto;
            try {
                
                consul.pideConsulta(paciente, medico, {dia, hora, minuto});
            } catch (std::domain_error e) {
                std::cout << e.what() << std::endl;
                std::cout << "---" << std::endl;
            }
            
            
        }else if(operacion == "siguientePaciente"){
            std::cin >> medico;
            try {
                
                std::string paciente =  consul.siguientePaciente(medico);
                std::cout << "Siguiente paciente doctor " << medico << std::endl;
                std::cout << paciente << std::endl;
                
                
            } catch (std::domain_error e) {
                std::cout << e.what() << std::endl;
            }
            std::cout << "---" << std::endl;
            
            
        }else if(operacion == "atiendeConsulta"){
            std::cin >> medico;
            try {
                consul.atiendeConsulta(medico);
            } catch (std::domain_error e) {
                std::cout << e.what() << std::endl;
                std::cout << "---" << std::endl;
            }
            
            
        }else if(operacion == "listaPacientes"){
            std::cin >> medico >> dia;
            try {
                std::list<std::pair<std::string, fechas>> lista = consul.listaPacientes(medico, dia);
                std::cout << "Doctor " << medico << " dia " << dia << std::endl;
                
                for(auto it = lista.begin(); it != lista.end(); ++it){
                    std::cout << it->first << ' ';
                    std::cout << std::setfill('0') << std::setw(2) << it->second.getHora() << ":";
                    std::cout << std::setfill('0') << std::setw(2) << it->second.getMinuto() << std::endl;
                }
            } catch (std::domain_error e) {
                std::cout << e.what() << std::endl;
            }
            std::cout << "---" << std::endl;
        }
        
        
        
    }
    
    std::cout << "------" << std::endl;
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda36.txt");
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
