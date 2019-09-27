//
//  polinomio.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 12/02/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef polinomio_h
#define polinomio_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>


struct monomio{
    int coeficiente;
    int exponente;
};


class polinomio{
    
private:
    
   
    std::vector<monomio> v_polinomio;
    
public:
    
    polinomio(){}
    
    //polinomio(int coeficiente, int exponente) {}
    
    
    void aniadirMonomio(int coeficiente, int exponente){
        monomio m;
        
        m.coeficiente = coeficiente;
        m.exponente = exponente;
        v_polinomio.push_back(m);
    }
    
    int evaluarPolinomio(int valor){
        int resultado = 0;
       
        
        for(int i = 0; i < v_polinomio.size(); ++i){
            resultado += v_polinomio[i].coeficiente * pow(valor, v_polinomio[i].exponente);
        }
        return resultado;
        
    }
};

#endif /* polinomio_h */
