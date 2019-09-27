//
//  complejo.h
//  EDA_2
//
 
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef complejo_h
#define complejo_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

template <typename T>

class complejo {
public:
    complejo() : parte_real(0), parte_imaginaria(0) {}
    complejo(T real, T imaginaria)
    {
        parte_real = real;
        parte_imaginaria = imaginaria;
    }
    
   
    
    complejo<T> & operator+(complejo<T> const& other)
    {
        parte_real = parte_real + other.parte_real;
        parte_imaginaria = parte_imaginaria + other.parte_imaginaria;
        return *this;
        
    }
    
    complejo<T> & operator*(complejo<T> const& other)
    {
        T aux = parte_real, aux2 = other.parte_real;
        parte_real = (parte_real * other.parte_real) - (parte_imaginaria * other.parte_imaginaria);
        parte_imaginaria = (aux * other.parte_imaginaria) + (parte_imaginaria * aux2);
        return *this;
    }
    
    complejo<T> & operator=(complejo<T> const& other)
    {
        parte_real = other.parte_real;
        parte_imaginaria = other.parte_imaginaria;
        return *this;
        
    }
    
    T modulo()
    {
        return sqrt((pow(parte_real, 2) + pow(parte_imaginaria, 2)));
    }
    
private:
    T parte_real;
    T parte_imaginaria;
};



#endif /* complejo_h */
