// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "polinomio.h"
//==========================>   EJERCICIO 4 <==========================//

/*COSTE:
 
 
 */



// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int coeficiente, exponente;
    std::cin >> coeficiente >> exponente;
    
    if (! std::cin)
        return false;
    
    polinomio poli;
    
    while(coeficiente != 0 || exponente != 0){
        //llamar al metodo añadir de la clase polinomio
        poli.aniadirMonomio(coeficiente, exponente);
        std::cin >> coeficiente >> exponente;
    }
    
    int numValoresParaEvaluar, valor;
    std::cin >> numValoresParaEvaluar;
    
    for(int i = 0; i < numValoresParaEvaluar; ++i){
        std::cin >> valor;
        //llamar al metodo evaluar de la clase polinomio
         std::cout << poli.evaluarPolinomio(valor) << " ";
        
    }
    
    std::cout << std::endl;
    
   
    
 
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda4.txt");
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
