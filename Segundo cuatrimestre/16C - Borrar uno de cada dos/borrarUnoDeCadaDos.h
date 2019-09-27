//
//  borrarUnoDeCadaDos.h
//  EDA
//
//  Created by Irene Martin berlanga on 20/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef borrarUnoDeCadaDos_h
#define borrarUnoDeCadaDos_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"
template<typename T>
class borrarUnoDeCadaDos : public queue<T>{
    using Nodo = typename queue<T>::Nodo;
    
public:
    
    void borrar(){
        Nodo* nodo_actual = this->prim;
        Nodo* nodo_anterior = nullptr;
        
        for(int i = 0; i < this->nelems; ++i){
            if(i % 2 == 1){
                nodo_anterior->sig = nodo_actual->sig;
            }
            nodo_anterior = nodo_actual;
            nodo_actual = nodo_actual->sig;
        }
        
    }
    
    
    void print(std::ostream & o = std::cout)const{
        if(!this->empty()){
            Nodo *nodo_actual = this->prim;
            while(nodo_actual != nullptr){
                o << nodo_actual->elem << ' ';
                nodo_actual = nodo_actual->sig;
            }
            
        }
    }
    
    
    
};
template <class T>
inline std::ostream & operator<<(std::ostream & out, borrarUnoDeCadaDos<T> const& cola)
{
    cola.print(out);
    return out;
}

#endif /* borrarUnoDeCadaDos_h */
