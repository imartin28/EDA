//
//  aguasLimpias.h
//  EDA
//
//  Created by Irene Martin berlanga on 25/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef aguasLimpias_h
#define aguasLimpias_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"


template <typename T>
class aguasLimpias : public bintree<T>{
    using Link = typename bintree<T>::Link;

    
public:
    
    aguasLimpias() : bintree<T>() {}
    
    aguasLimpias(aguasLimpias<T> const& arbolIzq, T const& raiz, aguasLimpias<T> const& arbolDer ) : bintree<T>(arbolIzq, raiz, arbolDer)  {}
    
    int numTramosNavegables(int& nivelCaudal){
        return numTramosnavegables_rec(this->raiz, nivelCaudal);
    }
    
private:
    int numTramosnavegables_rec(Link const& arbol, int& nivelCaudal){
        if(arbol == nullptr){
            nivelCaudal = 0;
            return 0;
        }else if(arbol->left == nullptr && arbol->right == nullptr){
            nivelCaudal = 1;
            return 0;
        }else{
            
            int nivelCaudalIzq, nivelCaudalDer;
            
            int numTramosIzq = numTramosnavegables_rec(arbol->left, nivelCaudalIzq);
            int numTramosDer = numTramosnavegables_rec(arbol->right, nivelCaudalDer);
            
            nivelCaudal = nivelCaudalIzq + nivelCaudalDer - arbol->elem;
            int numTramosNavegables = numTramosIzq + numTramosDer;
           
            if(nivelCaudalIzq >= 3){
                numTramosNavegables += 1;
            }
            
            if(nivelCaudalDer >= 3){
                numTramosNavegables += 1;
            }
            
            if(nivelCaudal < 0){
                nivelCaudal = 0;
            }
            
            return numTramosNavegables;
            
            
        }
        
    }
};



template <typename T>
inline aguasLimpias<T> leerArbol_ext(T vacio){
    T raiz;
    std::cin >> raiz;
    
    if(raiz == vacio){
        return {};
    }else{
        aguasLimpias<T> arbolIzq = leerArbol_ext(vacio);
        aguasLimpias<T> arbolDer = leerArbol_ext(vacio);
        return {arbolIzq, raiz, arbolDer};
    }
}


#endif /* aguasLimpias_h */
