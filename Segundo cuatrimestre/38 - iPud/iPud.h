//
//  iPud.h
//  EDA
//
//  Created by Irene Martin berlanga on 25/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef iPud_h
#define iPud_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "hashmap_eda.h"
//using iterador = std::list<std::string>::iterator;

struct datosCancion {
    std::string nombreArtista;
    int duracion;
    std::list<std::string>::iterator iteradorEnListaDeReproduccion;
    std::list<std::string>::iterator iteradorEnListaDeReproducidas;
    bool estaEnListaDeReproduccion;
    bool estaEnListaDeReproducidas;
    
    datosCancion(){}
    
    datosCancion(std::string _nombreArtista, int _duracion, bool _estaEnListaDeReproduccion) : nombreArtista(_nombreArtista), duracion(_duracion), estaEnListaDeReproduccion(_estaEnListaDeReproduccion){
        this->estaEnListaDeReproducidas = false;
    }
};


class iPud{
    
    
    
private:
    
    unordered_map<std::string, datosCancion> mapa_ipud;
    std::list<std::string> listaReproduccion;
    std::list<std::string> listaReproducida;
    int cont_reproduccionTotal;
    
public:
    
    iPud(int _duracionLista = 0) : cont_reproduccionTotal(_duracionLista) {}
    
    void addSong(std::string nombreCancion, std::string nombre, int duracion){
        if(mapa_ipud.count(nombreCancion) == 1){
            throw std::domain_error("addSong");
        }else{
            mapa_ipud[nombreCancion] = {nombre, duracion, false};
            //mapa_ipud[nombreCancion].nombreArtista = nombre;
        }
    }
    
    ////// *************************************** //////
    /* Añade la canciñon S al final de la lista de reproducción. Si la canción ya se
     encontraba en la lista entonces no se añade (es decir, la lista no tiene canciones repetidas). Si la
     canción no está en el iPud se devuelve error. */
    
    void addToPlayList(std::string nombreCancion){
        if(mapa_ipud.count(nombreCancion) == 0){
            throw std::domain_error("addToPlaylist");
       
        }else{
            //Si la cancion no esta en la lista de reproduccion, se añade
            if(!mapa_ipud[nombreCancion].estaEnListaDeReproduccion){
                //se inserta la cancion al final de la lista de reproduccion
                auto iteradorEnListaReproduccion = listaReproduccion.insert(listaReproduccion.end(), nombreCancion);
               //se añade el iterador que apunta a la cancion guardada en la lista de reproduccion
                mapa_ipud[nombreCancion].iteradorEnListaDeReproduccion = iteradorEnListaReproduccion;
                
                //se acumula la duracion total de las canciones guardadas en la lista de reproduccion
                cont_reproduccionTotal += mapa_ipud[nombreCancion].duracion;
               
                //se pone a true el booleano
                mapa_ipud[nombreCancion].estaEnListaDeReproduccion = true;
            }
           
        }
    }
    
    
    ////// *************************************** //////
    
    /* Devuelve la primera canción de la lista de reproducción. Si la lista de reproducción es
     vacía se devuelve error. */
    std::string current(){
        if(listaReproduccion.empty()){
            throw std::domain_error("current");
        }else{
            return listaReproduccion.front();
        }
    }
    
    
    ////// *************************************** //////
    /* La primera canción de la lista de reproducción abandona la lista de reproducción y se
     registra como reproducida. Si la lista es vacía la acción no tiene efecto.*/
    std::string play(){
        std::string cancion = "";
        if(!listaReproduccion.empty()){
            //se saca de la primera posicion de la lista de reproduccion la cancion
            
            cancion = listaReproduccion.front();
            listaReproduccion.pop_front();
            
            //se resta la duracion total de la lista de reproduccion
            cont_reproduccionTotal -= mapa_ipud[cancion].duracion;
            //se pone a false el booleano de si esta en la lista de reproduccion
            mapa_ipud[cancion].estaEnListaDeReproduccion = false;
            //Si la cancion esta en la lista de reproducidas, se borra y se vuelve a insertar de nuevo
            if(mapa_ipud[cancion].estaEnListaDeReproducidas){
                listaReproducida.erase(mapa_ipud[cancion].iteradorEnListaDeReproducidas);
            }
            mapa_ipud[cancion].estaEnListaDeReproducidas = true;
            auto iterador_listaReproducidas = listaReproducida.insert(listaReproducida.end(), cancion);
            mapa_ipud[cancion].iteradorEnListaDeReproducidas = iterador_listaReproducidas;
        }
        
        return cancion;
    }
    
    
    ////// *************************************** //////
    /* Devuelve la suma de las duraciones de las canciones que integran la lista de reproducción actual. Si es vacıa se devuelve 0.*/
    
    int totalTime(){
       return cont_reproduccionTotal;
    
    }
    
     ////// *************************************** //////
    /* Obtiene la lista con las N (mayor que 0) últimas canciones que se han reproducido
     (mediante la operación play), de la más reciente a la más antigua. Si el número de canciones
     reproducidas es menor que N se devolverán todas. La lista no tiene repeticiones, de manera que si
     una canción se ha reproducido mas de una vez solo figurara la reproduccion mas reciente */
    
    std::list<std::string> recent(int numCanciones){
         std::list<std::string> listaAdevolver;
        
        auto it_listReproducidas = listaReproducida.rbegin();
        while(it_listReproducidas != listaReproducida.rend() && listaAdevolver.size() < numCanciones){
            listaAdevolver.push_back(*it_listReproducidas);
            ++it_listReproducidas;
        }
        
        return listaAdevolver;
    }
    
    
    ////// *************************************** //////
    /*Elimina todo rastro de la canci´on S del iPud. Si la canci´on no existe la operaci´on
    no tiene efecto.*/
    void deleteSong(std::string nombreCancion){
        if(mapa_ipud.count(nombreCancion) == 1){
            if(mapa_ipud[nombreCancion].estaEnListaDeReproduccion){
                listaReproduccion.erase(mapa_ipud[nombreCancion].iteradorEnListaDeReproduccion);
                cont_reproduccionTotal -= mapa_ipud[nombreCancion].duracion;
            }
            
            if(mapa_ipud[nombreCancion].estaEnListaDeReproducidas){
                listaReproducida.erase(mapa_ipud[nombreCancion].iteradorEnListaDeReproducidas);
            }
            mapa_ipud.erase(nombreCancion);
        }
        
    }
    
};
#endif /* iPud_h */
