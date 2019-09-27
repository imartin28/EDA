// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "stack_eda.h"

//==========================>   EJERCICIO 6 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
bool comprobarCaracterCierre(char caracterCierre, const char caracterAperturaPila){
    
    if(caracterAperturaPila == '(' && caracterCierre == ')')
        return true;
    else if(caracterAperturaPila == '[' && caracterCierre == ']')
        return true;
    else if(caracterAperturaPila == '{' && caracterCierre == '}')
        return true;
    
    else return false;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    std::string palabra;
    std::getline(std::cin, palabra);
    
    
    if (! std::cin)
        return false;
    
    stack<char> pila;
    
   
    
    for(size_t i = 0; i < palabra.size(); ++i){
       if(palabra[i] == '(' || palabra[i] == '[' ||  palabra[i] == '{' ){
            pila.push(palabra[i]);
            
        }else if(palabra[i] == ')' || palabra[i] == ']' || palabra[i] == '}'){
            if(!pila.empty() && comprobarCaracterCierre(palabra[i], pila.top())){
                pila.pop();
            }else{
                pila.push(palabra[i]);
            }
        }
    
    }
    
    
    if(pila.empty())
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;
    
    
    // TipoSolucion sol = resolver(datos);
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda6.txt");
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
