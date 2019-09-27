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
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <list>

struct tPuntos {
    int puntos;
    std::list<std::string>::iterator it;
};

class CarnetPuntos{
    
private:
    
    
    //Clave -> dni y Valor --> puntos
    std::unordered_map<std::string, tPuntos> mapa_carnet;
    
    //Clave --> puntos y Valor --> contador de conductores
    std::unordered_map<int, std::list<std::string>> mapa_puntos;
    
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
            
            mapa_puntos[15].push_front(dni);
        
            mapa_carnet[dni] = {15, mapa_puntos[15].begin()};
        }
    }
    
    
    /*  El cost del metodo "quitar":
     O(1)
     
     */
    void quitar(std::string dni, int puntos){
        /* si el dni no existe lanza excepcion */
        if(mapa_carnet.count(dni) == 0){
            throw std::domain_error("Conductor inexistente");
        }else if(mapa_carnet[dni].puntos > 0 && puntos > 0){
            /* Si el dni existe, se le resta los puntos que le entran por parametro */
            int valorPuntos = mapa_carnet[dni].puntos - puntos;
            //--mapa_puntos[mapa_carnet[dni]];
            
            mapa_puntos[mapa_carnet[dni].puntos].erase(mapa_carnet[dni].it);
            
            /* Si el total de puntos es menor que cero, se actualiza el valor de puntos a 0 */
            if(valorPuntos < 0){
                mapa_puntos[0].push_front(dni);
                mapa_carnet[dni] = {0, mapa_puntos[0].begin()};
                
                
                //++mapa_puntos[0];
            }else{
                /* Si el total de puntos es mayor que cero, se actualiza el valor de puntos con el correspondiente */
                mapa_puntos[valorPuntos].push_front(dni);
                mapa_carnet[dni] = {valorPuntos, mapa_puntos[valorPuntos].begin()};
                
                //++mapa_puntos[valorPuntos];
            }
            
        }
    }
    
    
    /*  El coste del metodo "recuperar":
     O(1)    */
    void recuperar(std::string dni, int puntos){
        /* Si el dni no existe se lanza una excepcion*/
        if(mapa_carnet.count(dni) == 0){
            throw std::domain_error("Conductor inexistente");
        }else if(mapa_carnet[dni].puntos < 15 && puntos > 0){
      
            /* si el dni existe se le suma los puntos que entran por parametro */
            int valorPuntos = mapa_carnet[dni].puntos + puntos;
          
            mapa_puntos[mapa_carnet[dni].puntos].erase(mapa_carnet[dni].it);
            if(valorPuntos > 15){
                /* Si el total de puntos es mayor que 15, se le asigna el 15*/
               mapa_puntos[15].push_front(dni);
               mapa_carnet[dni] = {15, mapa_puntos[15].begin()};
                
                //++mapa_puntos[15];
            }else{
                /* si el total de puntos es menor que 15 se le asigna el valor de la suma*/
                mapa_puntos[valorPuntos].push_front(dni);
                mapa_carnet[dni] = {valorPuntos, mapa_puntos[valorPuntos].begin()};
             
                
                // ++mapa_puntos[valorPuntos];
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
            return mapa_carnet[dni].puntos;
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
            return mapa_puntos[puntos].size();
            //return mapa_puntos[puntos];
        }
    }
    
    
    std::list<std::string> lista_por_puntos(int puntos){
        
        if(puntos < 0 || puntos > 15){
            throw std::domain_error("Puntos no validos");
        }else{
            
            return mapa_puntos[puntos];
        }
    }
    
};


#endif /* carnet_puntos_h */
