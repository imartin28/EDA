//
//  invertirLista.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 19/02/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef invertirLista_h
#define invertirLista_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"
template<class T>
class invertirLista : public queue<T>{
    using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
 
    
    
public:
    
    
    void print(std::ostream & o = std::cout) const{
       
        if(!this->empty())
        {
            Nodo *actual = this->prim;
            
            while(actual->sig != nullptr)
            {
                o << actual->elem << " ";
                actual = actual->sig;
            }
            
            o << actual->elem;
        }
    }
    
    
    void invertir(){
       
        Nodo *nodo_actual = this->prim;
        this->ult = this->prim;
        Nodo *nodo_anterior = nullptr;
        
        if(this->nelems > 1 && !this->empty()){
            Nodo *nodo_siguiente = nodo_actual->sig;
            
            for(int i = 0; i < this->nelems; ++i){
                //Modificamos el puntero del nodo actual al anterior
                nodo_actual->sig = nodo_anterior;
                
                //Y ahora adelantamos todos los punteros una posicion
                nodo_anterior = nodo_actual;
                nodo_actual = nodo_siguiente;
                this->prim = nodo_actual;
                
                if(nodo_actual->sig != nullptr)
                    nodo_siguiente = nodo_actual->sig;
            }
        }
        
       
    }
    
};



template <class T>
inline std::ostream & operator<<(std::ostream & out, invertirLista<T> const& lista)
{
    lista.print(out);
    return out;
}

#endif /* invertirLista_h */
