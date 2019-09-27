
// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"
#include "queue_eda.h"

//==========================>   EJERCICIO __ <==========================//
template<class T>
class borrarCola : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    
    void eliminar(){
        
        Nodo *nodo_actual = this->prim;
        Nodo *nodo_anterior = nullptr;
        
        int i = 1;
        while(i < this->size() && nodo_actual->sig != nullptr){
            
            if(i % 2 == 0){
                delete nodo_anterior->sig;
                
                nodo_anterior->sig = nodo_actual->sig;
                nodo_actual = nodo_actual->sig;
                
                
            }else{
                nodo_anterior = nodo_actual;
                nodo_actual = nodo_actual->sig;
                
            }
            ++i;
        }
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin >> num;
    
    if (num == 0)
        return false;
    
    Horas hora;
    borrarCola<Horas> cola;
    
    for(auto i = 0; i < num; ++i){
        std::cin >> hora;
        cola.push(hora);

    }
    
    cola.eliminar();
    
    // escribir sol
    for(auto i = 0; i < cola.size(); ++i){
        std::cout << cola.front() << ' ';
        cola.pop();
    }

    std::cout << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/prueba1_ser.txt");
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
