//
//  mezclarLista.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 25/02/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef mezclarLista_h
#define mezclarLista_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template<class T>
class mezclarLista : public queue<T>{
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
    
    
    void mezclar(mezclarLista<T>& lista2){
        if(!this->empty()) {            
            if(!lista2.empty()) {
                
                Nodo* nodo_aux;
                Nodo* nodo_actual_lista1 = this->prim;
                Nodo* nodo_actual_lista2 = lista2.prim;
                
                if(nodo_actual_lista1->elem > nodo_actual_lista2->elem){
                    std::swap(nodo_actual_lista1->elem, nodo_actual_lista2->elem);
                }
                
                while(nodo_actual_lista2 != nullptr) {
                    while(nodo_actual_lista1->sig != nullptr && nodo_actual_lista2->elem > nodo_actual_lista1->sig->elem){
                        nodo_actual_lista1 = nodo_actual_lista1->sig;
                    }
                    
                    nodo_aux = nodo_actual_lista2->sig;
                    nodo_actual_lista2->sig = nodo_actual_lista1->sig;
                    nodo_actual_lista1->sig = nodo_actual_lista2;
                    
                    if(nodo_actual_lista2->sig == nullptr){
                        this->ult = nodo_actual_lista2;
                    }
                    nodo_actual_lista2 = nodo_aux;
                }
            }
            
        } else {
            this->prim = lista2.prim;
            this->ult = lista2.ult;
            
            
        }
        
        this->nelems += lista2.nelems;
        
        lista2.prim = nullptr;
        lista2.ult = nullptr;
        lista2.nelems = 0;

    }
    
};



template <class T>
inline std::ostream & operator<<(std::ostream & out, mezclarLista<T> const& lista)
{
    lista.print(out);
    return out;
}
#endif /* mezclarLista_h */
