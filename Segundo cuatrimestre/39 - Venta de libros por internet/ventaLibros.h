//
//  ventaLibros.h
//  EDA
//
//  Created by Irene Martin berlanga on 26/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef ventaLibros_h
#define ventaLibros_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include "hashmap_eda.h"
#include "treemap_eda.h"

struct datosLibros{
    int numEjemplares;
    int numVentas;
    std::list<std::string>::iterator it_pos_top10;
    
    datosLibros() : numEjemplares(0), numVentas(0) {}
    datosLibros(int _numEjemplares,  int _numVentas  ) : numEjemplares(0), numVentas(0) {}
};


class ventaLibros{
    using libro = std::string;
private:
    //Clave --> nombre del libro y Valor --> struct formado por los datos del libro: numEjemplares, numVentas y
    // un iterador que apunta a la lista de top 10 ventas
    unordered_map<libro, datosLibros> mapa_libro;
    
    //Clave --> numero de ventas y Valor--> lista de ventas
    map<int, std::list<std::string>, std::greater<int>> mapa_ventas;
    
    
public:
    /*  nuevoLibro(n,x): Añade n ejemplares de un libro x al sistema. Si n toma el valor cero significa
    que el libro está en el sistema, aunque no se tienen ejemplares disponibles. Si el libro ya está en el
    sistema se añaden los ejemplares. */
    
    void nuevoLibro(int numEjemplares, libro nombreLibro){
        
        mapa_libro[nombreLibro].numEjemplares += numEjemplares;
    }
    
    
    /* comprar(x): Un usuario compra un libro x. Si no existen ejemplares disponibles del libro x se
     produce un error de tipo out of range con el mensaje No hay ejemplares. Si el libro no está
     dado de alta en el sistema se produce un error de tipo invalid argument con el mensaje Libro
     no existente*/
    
    void comprar(libro nombreLibro){
        if(mapa_libro.count(nombreLibro) == 0){
            throw std::invalid_argument("Libro no existente");
            
        }else{
            if(mapa_libro[nombreLibro].numEjemplares == 0){
                throw std::out_of_range("No hay ejemplares");
            }else{
                //resto el numero de ejemplares que estan a la venta
                mapa_libro[nombreLibro].numEjemplares -= 1;
                //std::cout << mapa_libro[nombreLibro].numEjemplares << std::endl;
                
                //elimino de la lista del top10
                if(mapa_libro[nombreLibro].numVentas > 0){
                     mapa_ventas[mapa_libro[nombreLibro].numVentas].erase(mapa_libro[nombreLibro].it_pos_top10);
                }
               
                
                //aumento el numero de ventas
                 //std::cout << mapa_libro[nombreLibro].numVentas << std::endl;
                mapa_libro[nombreLibro].numVentas +=  1;
                //std::cout << mapa_libro[nombreLibro].numVentas << std::endl;
                
                //se añade a la lista el libro vendido
                auto it_libro = mapa_ventas[mapa_libro[nombreLibro].numVentas].insert(mapa_ventas[mapa_libro[nombreLibro].numVentas].begin(), nombreLibro);
                
                //se guarda el iterador que apunta a esa lista
                mapa_libro[nombreLibro].it_pos_top10 = it_libro;
            
            }
        }
     
    }
    
    
    /*  Indica si un libro x se ha añadido al sistema. El resultado será cierto si el libro
    está en el sistema, aunque no haya ejemplares disponibles, y será falso si no está en el sistema.    */
    
    bool estaLibro(libro nombreLibro){
        //si el libro no esta en el sistema
    
        if(mapa_libro.count(nombreLibro) == 0){
            return false;
        }else{
            return true;
        }
    }
    
    
    
   /* elimLibro(x): Elimina el libro x del sistema. Si el libro no existe la operaci´on no tiene efecto.*/
    
    void elimLibro(libro nombreLibro){
        if(mapa_libro.count(nombreLibro) == 1){
            if(mapa_libro[nombreLibro].numVentas > 0){
                mapa_ventas[mapa_libro[nombreLibro].numVentas].erase(mapa_libro[nombreLibro].it_pos_top10);
            }
            mapa_libro.erase(nombreLibro);
        }
    }
    
    
    /*  numEjemplares(x): Devuelve el numero de ejemplares de un libro x que hay disponibles en el
     sistema. Si el libro no esta dado de alta se produce un error de tipo invalid argument con el
     mensaje Libro no existente. */
    
    int numEjemplares(libro nombreLibro){
        if(mapa_libro.count(nombreLibro) == 0){
            throw std::invalid_argument("Libro no existente");
        }else{
            //if(mapa_libro[nombreLibro].numEjemplares > 0){
            return mapa_libro[nombreLibro].numEjemplares;
            //}
        }
    }
    
    
    
    /*top10(): Obtiene una lista con los 10 libros que m´as se han vendido. La lista estar´a ordenada por
    n´umero de ventas, de mayor a menor, y los libros que se hayan vendido el mismo n´umero de veces
    se ordenan del que tenga la venta m´as reciente a la m´as antigua, as´ı hasta completar la lista de 10
    libros. Si no se han vendido 10 libros distintos se listar´an todos ellos.*/
    
    std::list<std::string> top10(){
        std::list<std::string> listaAdevolver;
       
        auto it_mapa_ventas = mapa_ventas.begin();
        
        while(it_mapa_ventas != mapa_ventas.end() && listaAdevolver.size() < 10){
            for(auto it_listaTop10 = it_mapa_ventas->valor.begin(); it_listaTop10 != it_mapa_ventas->valor.end() && listaAdevolver.size() < 10; ++it_listaTop10){
                listaAdevolver.push_back(*it_listaTop10);
            }
            ++it_mapa_ventas;
        }
        
        return listaAdevolver;
    }
};
#endif /* ventaLibros_h */
