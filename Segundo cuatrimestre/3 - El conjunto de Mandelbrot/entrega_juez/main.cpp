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

bool resolver(complejo<float> const& c, int numero_iteraciones)
{
    int i = 1;
    bool pertenece = true;
    complejo<float> zeta_anterior;
    complejo<float> zeta_n;
    zeta_n = c;
    
    while(i < numero_iteraciones && pertenece)
    {
        pertenece = zeta_n.modulo() <= 2.0;
        zeta_anterior = zeta_n;
        zeta_n = (zeta_anterior * zeta_anterior) + c;
        ++i;
    }
    
    return i == numero_iteraciones;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracioón, y escribiendo la respuesta
void resuelveCaso()
{
    float parte_real, parte_imaginaria;
    int numero_iteraciones;
    bool pertenece;
    
    std::cin >> parte_real >> parte_imaginaria >> numero_iteraciones;
    
    complejo<float> c(parte_real, parte_imaginaria);
    
    pertenece = resolver(c, numero_iteraciones);
    
    if(pertenece){
        std::cout << "SI" << std::endl;
    }else{
        std::cout << "NO" << std::endl;
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
