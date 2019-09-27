//
//  insertaLista.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 23/02/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef insertaLista_h
#define insertaLista_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template<class T>
class insertarLista : public queue<T>{
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
    
    
    void insertar(insertarLista<T>& listaInsertar, T& posicion){
        
        int i = 0;
        Nodo *nodo_actual = this->prim;
        while(i < posicion - 1){
            nodo_actual = nodo_actual->sig;
            ++i;
        }
        
        if(posicion == 0){
            listaInsertar.ult->sig = nodo_actual;
            this->prim = listaInsertar.prim;
           
            
        }else{
           
            listaInsertar.ult->sig = nodo_actual->sig;
            nodo_actual->sig = listaInsertar.prim;
            
        }
        
        listaInsertar.prim = nullptr;
        listaInsertar.ult = nullptr;
        listaInsertar.nelems = 0;
   
    }
    
};



template <class T>
inline std::ostream & operator<<(std::ostream & out, insertarLista<T> const& lista)
{
    lista.print(out);
    return out;
}

#endif /* insertaLista_h */
