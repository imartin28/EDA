//
//  complejo.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 15/02/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef complejo_h
#define complejo_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

template <typename T>

class complejo{
    
private:
    T _real;
    T _imaginario;
    
    
public:
    complejo() : _real(0), _imaginario(0) {}
    complejo(T real, T imaginario) : _real(real), _imaginario(imaginario){}
    
    
    complejo<T> & operator +(complejo<T> const& num_complejo){
        complejo resultadoSuma;
        
        resultadoSuma._real= _real + num_complejo._real;
        resultadoSuma._imaginario = _imaginario + num_complejo._imaginario;
        
        return resultadoSuma;
    }
    
    complejo<T> operator *(complejo<T> const& num_complejo){
        complejo resultadoMultiplicacion;
        
        resultadoMultiplicacion._real = (_real * num_complejo._real) - (_imaginario * num_complejo._imaginario);
        resultadoMultiplicacion._imaginario = (_real * num_complejo._imaginario) - (num_complejo._real * _imaginario);
        
        return resultadoMultiplicacion;
    }
    
    T modulo(){
        T resultado;
        
        resultado = sqrt(pow(_real, 2) + pow(_imaginario, 2));
        return resultado;
    }
};

#endif /* complejo_h */
