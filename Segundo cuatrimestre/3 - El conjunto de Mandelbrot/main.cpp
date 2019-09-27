// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "complejo.h"

//==========================>   EJERCICIO 3 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    float real, imaginario;
    int iterador;
    bool esDivergente = false;
    
    std::cin >> real >> imaginario >> iterador;
    
    complejo<float> num_complejo(real, imaginario);
 
    
    complejo<float> zeta_n;
    complejo<float> z_anterior;
   
    zeta_n = num_complejo;
    
    for(int i = 0; i < iterador && !esDivergente; ++i){
        
        z_anterior = zeta_n;
        zeta_n = (z_anterior * z_anterior) + num_complejo;
        //z = z * z + num_complejo;
        
        if(num_complejo.modulo() > 2){
            esDivergente = true;
        }
    
    }
  
    // escribir sol
    if(esDivergente){
        std::cout << "NO" << std::endl;
    }else{
        std::cout << "SI" << std::endl;
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda3.txt");
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
