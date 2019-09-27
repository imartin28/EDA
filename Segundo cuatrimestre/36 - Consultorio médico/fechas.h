//
//  fechas.h
//  EDA
//
//  Created by Irene Martin berlanga on 21/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef fechas_h
#define fechas_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

class fechas{
  
private:
    int dia, hora, minuto;
    
public:
    
  
    fechas(int d): dia(d), hora(0), minuto(0){}
    
    fechas(int d, int h, int m): dia(d), hora(h), minuto(m){}
    
    int getDia() const{
        return this->dia;
    }
    
    int getHora() const{
        return this->hora;
    }
    
    int getMinuto() const{
        return this->minuto;
    }
    
   //this seria la primera fecha y fecha seria la segunda
    bool operator<(fechas const& fecha)const{
        if(this->dia < fecha.dia ){
            return true;
        }else if(this->dia > fecha.dia){
            return false;
        }else{
            
            if(this->hora < fecha.hora){
                return true;
            }else if(this->hora > fecha.hora){
                return false;
            }else{
                return this->minuto < fecha.minuto;
            }
        }
    }
    
    
    bool operator==(fechas const& fecha)const{
        if(this->dia != fecha.dia){
            return false;
        }else{
            if(this->hora != fecha.hora){
                return false;
            }else{
                return this->minuto == fecha.minuto;
            }
        }
    }
    
    bool operator!=(fechas const& fecha)const{
        return !(this->operator==(fecha));
    }
    
};


/*bool operator<(fechas const& fecha1, fechas const fecha2){
    if(fecha1.getDia() < fecha2.getDia()){
        return true;
    }else if(fecha1.getDia() > fecha2.getDia()){
        return false;
    }else{
       
        if(fecha1.getHora() < fecha2.getHora()){
            return true;
        }else if(fecha1.getHora() > fecha2.getHora()){
            return false;
        }else{
            return fecha1.getMinuto() < fecha2.getMinuto();
        }
    }
    
    
 
}



bool operator==(fechas const& fecha1, fechas const& fecha2){
    if(fecha1.getDia() != fecha2.getDia()){
        return false;
    }else{
        if(fecha1.getHora() != fecha2.getHora()){
            return false;
        }else{
            return fecha1.getMinuto() == fecha2.getMinuto();
        }
    }
}

bool operator!=(fechas const& fecha1, fechas const& fecha2){
    return !(fecha1 == fecha2);
}*/

#endif /* fechas_h */
