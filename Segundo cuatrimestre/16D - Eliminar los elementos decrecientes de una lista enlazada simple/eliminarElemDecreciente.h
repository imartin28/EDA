//
//  eliminarElemDecreciente.h
//  EDA
//
//  Created by Irene Martin berlanga on 21/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef eliminarElemDecreciente_h
#define eliminarElemDecreciente_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"
template<typename T>
class eliminarElemCreciente : public queue<T>{
    using Nodo = typename queue<T>::Nodo;
    
    
public:
    
    void eliminar(){
        
        Nodo* nodo_actual = this->prim;
        Nodo* nodo_siguiente = nodo_actual->sig;
        
       while(nodo_siguiente != nullptr){
            if(nodo_siguiente->elem < nodo_actual->elem){
                nodo_actual->sig = nodo_siguiente->sig;
                nodo_siguiente = nodo_actual->sig;
                //delete nodo_siguiente;
                --this->nelems;
                
            }else{
                nodo_actual = nodo_siguiente;
                nodo_siguiente = nodo_actual->sig;
            }
          
            
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
inline std::ostream & operator<<(std::ostream & out, eliminarElemCreciente<T> const& cola)
{
    cola.print(out);
    return out;
}
#endif /* eliminarElemDecreciente_h */
