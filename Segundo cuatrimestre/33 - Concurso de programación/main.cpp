// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "hashmap_eda.h"
#include "treemap_eda.h"
#include <set>

using nombre_equipo = std::string;
using nombre_problema = std::string;
using num_problemas_resueltos = int;

struct datosIntentos{
    //int numIntentos;
    int tiempoTotalHastaAC;
    bool esCorrecto;
};

struct datosSolucion {
    nombre_equipo nombreEquipo;
    int tiempoTotal;
};


struct datosProblemas{
    unordered_map<nombre_problema, datosIntentos> mapa_problemas;
    num_problemas_resueltos numProblemasCorrectos;
    //std::set<datosSolucion>::iterator it_set_equipos;
    int tiempoTotalDeTodosLosAciertos;
    
    //iterador
};


bool operator<(datosSolucion const& datos1, datosSolucion const& datos2){
    if(datos1.tiempoTotal == datos2.tiempoTotal){
        return datos1.nombreEquipo < datos2.nombreEquipo;
    }else{
        return datos1.tiempoTotal < datos2.tiempoTotal;
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    map<num_problemas_resueltos, std::set<datosSolucion>, std::greater<num_problemas_resueltos>> mapa_solucion;
    unordered_map<nombre_equipo, datosProblemas> mapa_equipos;
    
    std::string nombreEquipo, nombreProblema, veredictoJuez;
    int minDesdeInicio;
    
    
    std::cin>> nombreEquipo;
    
    while(nombreEquipo != "FIN"){
        std::cin >> nombreProblema >> minDesdeInicio >> veredictoJuez;
        if(veredictoJuez !=  "AC"){
            //si no esta el equipo
            if(mapa_equipos.count(nombreEquipo) == 0){
                //se aumenta el numero de intentos
                //++mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].numIntentos;
                
                mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].tiempoTotalHastaAC = 20;
                
                mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].esCorrecto = false;
                
                
                mapa_equipos[nombreEquipo].numProblemasCorrectos = 0;
               
                //auto pair = mapa_solucion[0].insert({nombreEquipo, 0});
                //mapa_equipos[nombreEquipo].it_set_equipos = pair.first;
                
            }else{
                if(!mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].esCorrecto){
                    mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].tiempoTotalHastaAC += 20;
                   // ++mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].numIntentos;
                }
                
            }
            
        }else{ //la valoracion del juez es ac
            if(mapa_equipos.count(nombreEquipo) == 0){
                
                
                mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].tiempoTotalHastaAC = minDesdeInicio;
                
                mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].esCorrecto = true;
                ++mapa_equipos[nombreEquipo].numProblemasCorrectos;
                mapa_equipos[nombreEquipo].tiempoTotalDeTodosLosAciertos = minDesdeInicio;
                
                
                //auto pair = mapa_solucion[1].insert({nombreEquipo, minDesdeInicio});
                //mapa_equipos[nombreEquipo].it_set_equipos = pair.first;
                
            }else{//el equipo ya esta en el mapa
                
                //int numIntentosTotal = mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].numIntentos;
                
                
                
                if(!mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].esCorrecto){
                   // mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].tiempoTotalHastaAC = numIntentosTotal * 20 + minDesdeInicio;
                    mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].tiempoTotalHastaAC += minDesdeInicio;
                    mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].esCorrecto = true;
                    ++mapa_equipos[nombreEquipo].numProblemasCorrectos;
                    
                    //mapa_equipos[nombreEquipo].tiempoTotalDeTodosLosAciertos += numIntentosTotal * 20 + minDesdeInicio;
                    mapa_equipos[nombreEquipo].tiempoTotalDeTodosLosAciertos += mapa_equipos[nombreEquipo].mapa_problemas[nombreProblema].tiempoTotalHastaAC;
                   // int numProblemasResueltos = mapa_equipos[nombreEquipo].numProblemasCorrectos;
                    //auto it_set = mapa_equipos[nombreEquipo].it_set_equipos;
                    
                    //mapa_solucion[numProblemasResueltos].erase(it_set);
                    
                   // int tiempoTotal = mapa_equipos[nombreEquipo].tiempoTotalDeTodosLosAciertos;
                    //auto pair = mapa_solucion[numProblemasResueltos].insert({nombreEquipo,tiempoTotal});
                   // mapa_equipos[nombreEquipo].it_set_equipos = pair.first;
                }
                
            }
        }
        
        std::cin>> nombreEquipo;
        
    }
    
    
    
    
    auto it_mapa_equipos = mapa_equipos.begin();
    
    while(it_mapa_equipos != mapa_equipos.end()){
        int numProblemasCorrectos = it_mapa_equipos->valor.numProblemasCorrectos;
        int tiempoTotal = it_mapa_equipos->valor.tiempoTotalDeTodosLosAciertos;
        mapa_solucion[numProblemasCorrectos].insert({it_mapa_equipos->clave, tiempoTotal});
        
        
        ++it_mapa_equipos;
    }
    
    
    auto it_mapa_solucion = mapa_solucion.begin();
    
    while(it_mapa_solucion != mapa_solucion.end()){
        
        for(auto it_set_equipos = it_mapa_solucion->valor.begin(); it_set_equipos != it_mapa_solucion->valor.end(); ++it_set_equipos){
            std::cout << it_set_equipos->nombreEquipo << ' ' << it_mapa_solucion->clave << ' ' << it_set_equipos->tiempoTotal << std::endl;
        }
        
        ++it_mapa_solucion;
    }
    std::cout << "----" << std::endl;
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/ex_junio18_sesion2_ej3.txt");
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
