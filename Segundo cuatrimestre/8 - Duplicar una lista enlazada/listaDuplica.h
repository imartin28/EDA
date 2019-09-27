//
//  lista_duplica.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 15/02/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef lista_duplica_h
#define lista_duplica_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class listaDuplica : public queue<T> {
   
    using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
    
    void print(std::ostream & o = std::cout) const {
        if(!this->empty())
        {
            Nodo *actual = this->prim;
            
            while(actual->sig != nullptr)
            {
                o << actual->elem;
                o << " ";
                actual = actual->sig;
            }
            
            o << actual->elem;
        }
    }
    
    
    // Duplicar los nodos de una lista enlazada simple
    void duplica() {
        
        if(!this->empty()){
            Nodo *nodo_actual = this->prim;
            Nodo *nodo_nuevo = nullptr;
            
            while(nodo_actual != nullptr){
                nodo_nuevo = new Nodo(nodo_actual->elem, nodo_actual->sig);
                
                nodo_actual->sig = nodo_nuevo;
               // this->prim = nodo_nuevo;
                nodo_actual = nodo_nuevo->sig;
               // nodo_nuevo->sig = nodo_actual->sig;
                ++this->nelems;
                
            }
            
            this->ult = nodo_nuevo;
        
        }
       
    }
    
};

template <class T>
inline std::ostream & operator<<(std::ostream & out, listaDuplica<T> const& lista)
{
    lista.print(out);
    return out;
}
#endif /* lista_duplica_h */
