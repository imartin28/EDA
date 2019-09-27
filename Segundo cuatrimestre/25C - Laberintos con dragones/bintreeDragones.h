//
//  bintreeDragones.h
//  EDA
//
//  Created by Irene Martin berlanga on 25/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef bintreeDragones_h
#define bintreeDragones_h

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"
template <typename T>
class Dragones : public bintree<T>{
    using Link = typename bintree<T>::Link;
public:
    
    Dragones() : bintree<T>(){}
    
    Dragones(Dragones<T>const& arbolIzq, T const& raiz, Dragones<T> const& arbolDer) : bintree<T>(arbolIzq, raiz, arbolDer){}
    
    std::string hojaConMenorNumDragones(int& contDragones) const{
        return hojaConMenorNumDragones_rec(this->raiz, contDragones);
    }
    
private:
    std::string hojaConMenorNumDragones_rec(Link const& raiz, int& contDragones) const{
        if(raiz == nullptr){
            contDragones = 0;
            return "";
        }else if(raiz->left == nullptr && raiz->right == nullptr){
            contDragones = 0;
            return raiz->elem;
        }else{
            
            int contDragonesIzq, contDragonesDer;
           
            std::string nombreHojaIzq = hojaConMenorNumDragones_rec(raiz->left, contDragonesIzq);
            std::string nombreHojaDer = hojaConMenorNumDragones_rec(raiz->right, contDragonesDer);
            
            if(contDragonesIzq <= contDragonesDer && raiz->left != nullptr && raiz->right != nullptr || raiz->right ==  nullptr){
                if(raiz->elem == "Dragon"){
                    contDragones = contDragonesIzq + 1;
                }else{
                    contDragones = contDragonesIzq;
                }
            
                return nombreHojaIzq;
                
            }else{
                if(raiz->elem == "Dragon"){
                    contDragones = contDragonesDer + 1;
                }else{
                    contDragones = contDragonesDer;
                }
                
                return nombreHojaDer;
                
            }
            
           
            
        }
    }
};



template <typename T>
inline Dragones<T> leerArbol_ext(T vacio){
    T raiz;
    std::cin >> raiz;
    
    if(raiz == vacio){
        return {};
        
    }else{
        Dragones<T> arbolIzq = leerArbol_ext(vacio);
        Dragones<T> arbolDer = leerArbol_ext(vacio);
        return {arbolIzq, raiz, arbolDer};
    }
}

#endif /* bintreeDragones_h */
