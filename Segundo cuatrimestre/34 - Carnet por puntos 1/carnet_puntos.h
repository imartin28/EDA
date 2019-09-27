//
//  carnet_puntos.h
//  EDA
//
//  Created by Irene Martin berlanga on 18/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef carnet_puntos_h
#define carnet_puntos_h
#include <unordered_map>
#include <stdexcept>



class CarnetPuntos{
private:
    //Clave -> dni y Valor --> puntos
    std::unordered_map<std::string, int> mapa_carnet;
    
    //Clave --> puntos y Valor --> contador de conductores
    std::unordered_map<int, int> mapa_puntos;
    
public:
    /* El coste del metodo "nuevo":
        O(1)
     */
    void nuevo(std::string dni){
        /* Si el dni ya existe lanza excepción */
        if(mapa_carnet.count(dni) == 1){
            throw std::domain_error("Conductor duplicado");
        }else{ /* Si el dni no existe, lo añade con el valor de 15 puntos
                y aumento en el mapa de puntos el contador de conductores con esos puntos */
            mapa_carnet[dni] = 15;
            ++mapa_puntos[15];
        }
    }
    
    
    /*  El cost del metodo "quitar":
        O(1)
     
     */
    void quitar(std::string dni, int puntos){
        /* si el dni no existe lanza excepcion */
        if(mapa_carnet.count(dni) == 0){
            throw std::domain_error("Conductor inexistente");
        }else{
            /* Si el dni existe, se le resta los puntos que le entran por parametro */
            int valorPuntos = mapa_carnet[dni] - puntos;
            --mapa_puntos[mapa_carnet[dni]];
            /* Si el total de puntos es menor que cero, se actualiza el valor de puntos a 0 */
            if(valorPuntos < 0){
                mapa_carnet[dni] = 0;
                ++mapa_puntos[0];
            }else{
                /* Si el total de puntos es mayor que cero, se actualiza el valor de puntos con el correspondiente */
                mapa_carnet[dni] = valorPuntos;
                ++mapa_puntos[valorPuntos];
            }
          
            
            
            
        }
    }
    
    /* El coste del metodo "consultar":
        O(1)
     */
    int consultar(std::string dni){
        /*  Si el dni no existe lanza excepcion */
        if(mapa_carnet.count(dni) == 0){
            throw std::domain_error("Conductor inexistente");
        }else{
            /* si el dni existe devuelve los puntos actuales del conductor */
            return mapa_carnet[dni];
        }
    }
    
    /* El coste del metodo "cuantos_con_puntos":
        O(1)
     */
    int cuantos_con_puntos(int puntos){
        /* Si el numero de puntos no esta entre 0 y 15 lanza excepcion */
        if(puntos < 0 || puntos > 15 ){
            throw std::domain_error("Puntos no validos");
        }else{
            /* Devuelve el numero de conductores que tienen esos puntos */
            return mapa_puntos[puntos];
        }
    }
};


#endif /* carnet_puntos_h */
