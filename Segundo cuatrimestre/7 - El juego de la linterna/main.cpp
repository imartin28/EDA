// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "stack_eda.h"

//==========================>   EJERCICIO 7 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
bool resolver(std::vector<int>const& v_alturas){
    
    int mediano = -1;
    bool encontradoValorMayor = true;
    stack<int> pila;
    bool seTermina = false;
    int valorCimaPila;
    
    for(int i = v_alturas.size() - 1; i >= 0 && !seTermina ; --i){
        
        if(v_alturas[i] < mediano){
            seTermina = true;
        }else{
            while(!pila.empty() && v_alturas[i] > pila.top()){
                mediano = pila.top();
                pila.pop();
            }
            
            pila.push(v_alturas[i]);
        }
    }
    
    return seTermina;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numSobrinos;
    std::cin >> numSobrinos;
    
    if (! std::cin)
        return false;
    std::vector<int> v_alturas(numSobrinos);
    
    int altura;
    
    for(int i = 0; i < numSobrinos; ++i){
        std::cin >> altura;
        v_alturas[i] = altura;
    }
    
    
    
    bool sol = resolver(v_alturas);
    
    
    if(sol){
        std::cout << "ELEGIR OTRA" << std::endl;
    }else{
        std::cout << "SIEMPRE PREMIO"  << std::endl;
    }
    
    
    
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda7.txt");
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
