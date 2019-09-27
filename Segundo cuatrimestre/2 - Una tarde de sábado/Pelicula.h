//
//  Pelicula.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 12/02/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h

#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "Horas.h"

class Pelicula{
    
private:
    Horas _horaIni;
    Horas _duracionPeli;
    std::string _tituloPeli;
    Horas _finPelicula;
public:
    Pelicula(){}
    Pelicula(Horas horaInicio, Horas duracion, std::string tituloPeli) : _horaIni(horaInicio), _duracionPeli(duracion), _tituloPeli(tituloPeli), _finPelicula(horaInicio + duracion) {}
    
    Horas get_horaInicio() const{
        return _horaIni;
    }
    
    Horas get_duracionPeli() const{
        return _duracionPeli;
    }
    
    Horas get_horaFin() const{
        return _finPelicula;
    }
    
    
    std::string get_tituloPeli() const{
        return _tituloPeli;
    }
    
    
   
    bool operator <(Pelicula const& peli) const{
        if(peli._finPelicula == _finPelicula)
            return _tituloPeli < peli._tituloPeli;
        else
            return _finPelicula < peli._finPelicula;
    }
  
    

};

inline std::ostream& operator<< (std::ostream & out, Pelicula const& peli) {
    
    std::cout << peli.get_horaFin() << " " << peli.get_tituloPeli();
    
    return out;
}



#endif /* Pelicula_h */
