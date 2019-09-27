// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "hashmap_eda.h"

//==========================>   EJERCICIO 29 <==========================//

/*COSTE:
 
 
 */


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int numCapitulos;
    std::cin >> numCapitulos;
    /* Clave -> Numero de capitulo ;    Valor -> Ultimo dia en el que se ha emitido*/
    unordered_map<int, int> dict;
    int capitulo;
    int contadorDiasActualesSinRepetirCapitulo = 0;
    int contadorMaxDiasSinRepetir = 0;
    for(int diaEmitido = 0; diaEmitido < numCapitulos; ++diaEmitido){
        std::cin >> capitulo;
        // Si es la primera vez que se emite el capitulo
        if (dict.count(capitulo) == 0){
            dict.insert({capitulo, diaEmitido});
            ++contadorDiasActualesSinRepetirCapitulo;
        }else{
            
            if(diaEmitido - dict[capitulo] <= contadorDiasActualesSinRepetirCapitulo) {
                contadorDiasActualesSinRepetirCapitulo = diaEmitido - dict[capitulo];
            }else{
                ++contadorDiasActualesSinRepetirCapitulo;
            }
            
            dict[capitulo] = diaEmitido;
        }
        
         contadorMaxDiasSinRepetir = std::max(contadorMaxDiasSinRepetir, contadorDiasActualesSinRepetirCapitulo);
    }
    
    
    std::cout << contadorMaxDiasSinRepetir << std::endl;
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda29.txt");
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
