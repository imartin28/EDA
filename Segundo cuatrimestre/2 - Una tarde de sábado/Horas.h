//
//  horas.h
//  EDA_2
//
//  Created by Irene Martin berlanga on 31/01/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef Horas_h
#define Horas_h
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <algorithm>

class Horas{
    
private:
    int hora;
    int minutos;
    int segundos;
    
    
public:
    
    
    Horas(){}
    Horas(int h, int m, int s) : hora(h), minutos(m), segundos(s) {
        
        if(hora < 0 || hora > 23 || minutos < 0 || minutos > 59 || segundos < 0 || segundos > 59){
            throw std::invalid_argument("ERROR");
        }
        
    }
    
    
    int get_hora() const{
        return hora;
    }
    
    int get_minutos() const{
        return minutos;
    }
    
    int get_segundos() const{
        return segundos;
    }
    
    
    bool operator <(Horas const& h) const{
        if(hora < h.hora)
            return true;
        else if(hora == h.hora && minutos < h.minutos)
            return true;
        else if(hora == h.hora && minutos == h.minutos && segundos < h.segundos)
            return true;
        else
            return false;
    }
    
    bool operator== (Horas const& h) const{
        return hora == h.hora && minutos == h.minutos && segundos == h.segundos;
    }
    
    
    /*Calcula la hora de fin, en los atributos de la clase esta la hora de inicio, y lo que entra por
     parametro es la duracion */
    
    Horas operator +(Horas const& h_duracion) const{
        int hora_aux = 0, min_aux = 0, seg_aux = 0;
        
        seg_aux = h_duracion.segundos + segundos;
        
        if(seg_aux >= 60){
        min_aux = seg_aux / 60;
           seg_aux = abs(60 - seg_aux);
        }
        
        
        min_aux = min_aux + h_duracion.minutos + minutos;
        
        if(min_aux >= 60){
            hora_aux = min_aux / 60;
            min_aux = abs(60 - min_aux);
        }
        
        
        hora_aux = hora_aux + h_duracion.hora + hora;
        
        
       /* int hora_aux = 0, min_aux = 0, seg_aux = 0;
        seg_aux = h.segundos;
        //convertimos los segundos a minutos y lo sumamos a los minutos
        min_aux = h.segundos / 60 + h.minutos;
        //convertimos los minutos a horas y sumamos a las horas
        hora_aux = seg_aux / 60 + h.hora;*/
        
        if(hora_aux > 23)
            throw std::domain_error("Se ha superado las horas de un dia");
        else
           return Horas(hora_aux, min_aux, seg_aux );
        
    }
 
};




/* Forma en la que voy a leer una hora completa */

inline std::istream& operator>> (std::istream & in, Horas& h) {
    int h_aux, min_aux, seg_aux;
    char dosPuntos;
    
    std::cin >> h_aux >> dosPuntos >> min_aux >> dosPuntos >> seg_aux;
    
    h = Horas(h_aux, min_aux, seg_aux);
    
    return in;
}

/* Forma en la que voy a imprimir una hora completa */

inline std::ostream& operator<< (std::ostream & out, Horas const& h) {
   
    std::cout << std::setfill('0') << std::setw(2) << h.get_hora() << ":"
    << std::setfill('0') << std::setw(2) << h.get_minutos() << ":"
    << std::setfill('0') << std::setw(2) << h.get_segundos();
    return out;
}


#endif /* horas_h */
