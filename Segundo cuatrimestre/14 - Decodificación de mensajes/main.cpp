// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"
#include "stack_eda.h"

//==========================>   EJERCICIO 14 <==========================//

/*COSTE:
 
 
 */
bool comprobarSiEsVocal(char letra){
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' );
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string palabra;
    std::getline(std::cin,palabra);
    
    if (! std::cin)
        return false;
    
    queue<char> cola;
    
    for(int i = 0; i < palabra.size(); ++i){
        cola.push(palabra[i]);
    }
    
    stack<char> pila;
    char letra_cima_cola;
    //Se recorre la palabra y se saca un elemento si y un elemento no, y los elementos que se sacan se meten a una pila
    for(int i = 0; i < palabra.size(); ++i){
        letra_cima_cola = cola.front();
        cola.pop();
        if(i % 2 == 0){
            cola.push(letra_cima_cola);
        }else{
            pila.push(letra_cima_cola);
            
        }
        
    }
    
    char letra_cima_pila;
    //Se recorre la pila y se vuelve a meter todas las letras al final de la cola
    while(!pila.empty()){
        letra_cima_pila = pila.top();
        pila.pop();
        cola.push(letra_cima_pila);
    }
  
    
    //Prueba para comprobar que el primer paso de invertir lo hace correctamente
    /*
    while(!cola.empty()){
        letra_cima_cola = cola.front();
        cola.pop();
        std::cout << letra_cima_cola;
    }*/
    char letra_primera;
    char letra_segunda;
    
    for(int i = 0; i < palabra.size(); ++i){
        
        letra_cima_cola = cola.front();
        cola.pop();
        if(!comprobarSiEsVocal(letra_cima_cola)){
            pila.push(letra_cima_cola);
            
        }else{
            if(!pila.empty()){
                while(!pila.empty()){
                    letra_cima_pila = pila.top();
                    std::cout << letra_cima_pila;
                    pila.pop();
                }
            }
            std::cout << letra_cima_cola;
        }
       
    }
    while(!pila.empty()){
        letra_cima_pila = pila.top();
        std::cout << letra_cima_pila;
        pila.pop();
    }
    
    std::cout << std::endl;
    
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda14.txt");
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
