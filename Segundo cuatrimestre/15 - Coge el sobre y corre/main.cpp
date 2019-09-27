// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "deque_eda.h"

//==========================>   EJERCICIO 15 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numSobres, numComensales;
    std::cin >> numSobres >> numComensales;
    
    if (numSobres == 0 && numComensales == 0)
        return false;
    
    
    std::vector<int> v_dinero(numSobres);
    int dinero;
    
    /* Inicializamos el vector con el dinero de cada sobre*/
    for(int i = 0; i < numSobres; ++i){
        std::cin >> dinero;
        v_dinero[i] = dinero;
    }
    
    deque<int> cola;
    
    /* Cogemos los numeros que forman la ventana*/
    for(int i = 0; i < numComensales; ++i){
        if(cola.empty()){
            cola.push_back(v_dinero[i]);
        }else{
            if(v_dinero[i] > cola.front() && i != numComensales - 1){
                cola.pop_front();
                cola.push_back(v_dinero[i]);
            }else if(v_dinero[i] > cola.front() && i == numComensales - 1){
                
                //std::cout << cola.front();
                cola.pop_front();
            }else{
               // std::cout << cola.front() << ' ';
                cola.push_back(v_dinero[i]);
            }
            
        }
    }
    
    if(numComensales == 1){
        for(int i = 0; i < v_dinero.size(); ++i){
            std::cout << v_dinero[i] << ' ';
        }
        
    }else{
        for(int i = numComensales; i < v_dinero.size(); ++i){
            //std::cout << v_dinero[i - numComensales] << ' ';
            
            if(v_dinero[i] >= cola.front() && v_dinero[i - numComensales] != cola.front()){
                cola.pop_back();
                cola.push_back(v_dinero[i]);
                
            }else if(v_dinero[i] < cola.front()){
                
                std::cout << cola.front() << ' ';
                cola.pop_front();
                cola.push_back(cola.front());
                
            }else{
                
                std::cout << cola.front() << ' ';
                cola.pop_front();
                cola.push_back(v_dinero[i]);
                
            }
            
        }
        
        int i = 0;
        
        while(!cola.empty()){
            std::cout << cola.front() << ' ';
            cola.pop_front();
            ++i;
        }
        
    }
    
    
    std::cout << std::endl;
    
    
    
    
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda15.txt");
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
