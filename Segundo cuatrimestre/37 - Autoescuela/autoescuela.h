//
//  autoescuela.h
//  EDA
//
//  Created by Irene Martin berlanga on 27/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef autoescuela_h
#define autoescuela_h
#include <set>
#include <list>
#include "hashmap_eda.h"
using alumno= std::string;
using profesor = std::string;

struct datosAlumno{
    int puntos;
    profesor nombreProfesor;
    std::set<alumno>::iterator it_setAlumnosProfesor;
    
};


class autoescuela {
    
private:
    //Clave --> nombre del alumno y Valor --> datos del alumno
    unordered_map<alumno, datosAlumno> mapa_alumnos;
    unordered_map<profesor, std::set<alumno>> mapa_profesores;
    
public:
    
    /*  alta(A, P): sirve tanto para dar de alta a un alumno como para cambiarle de profesor. Si el
     alumno no estaba matriculado en la autoescuela se le da una puntuación de cero. Si ha cambiado
     de profesor, se le da de alta con el nuevo, con la puntuación que tuviera, y se le da de baja con el
     anterior. La puntuación determinará quién se puede examinar.    */
    
    void alta(alumno nombreAlumno, profesor nombreProfesor){
        //el alumno no esta matriculado
        if(mapa_alumnos.count(nombreAlumno) == 0){
            mapa_alumnos[nombreAlumno].puntos = 0;
            mapa_alumnos[nombreAlumno].nombreProfesor = nombreProfesor;
           
            
        }else{
            if(mapa_alumnos[nombreAlumno].nombreProfesor != nombreProfesor){
                int puntosDelAlumno = mapa_alumnos[nombreAlumno].puntos;
                
                //se elimina de la lista de los alumnos del profesor
                mapa_profesores[mapa_alumnos[nombreAlumno].nombreProfesor].erase(mapa_alumnos[nombreAlumno].it_setAlumnosProfesor);
                //se elimina el alumno
                mapa_alumnos.erase(nombreAlumno);
                
                //se le asigna el nuevo profesor
                mapa_alumnos[nombreAlumno].nombreProfesor = nombreProfesor;
                //se le asignan los mismos puntos que tuviera
                mapa_alumnos[nombreAlumno].puntos = puntosDelAlumno;
            }
        }
        auto it_listaAlumnos = mapa_profesores[nombreProfesor].insert(mapa_profesores[nombreProfesor].begin() , nombreAlumno);
        mapa_alumnos[nombreAlumno].it_setAlumnosProfesor = it_listaAlumnos;
    }
    
    
   /* es alumno(A, P): comprueba si el alumno A est´a matriculado actualmente con el profesor P.*/
    
    bool es_alumno(alumno nombreAlumno, profesor nombreProfesor){
        return mapa_alumnos[nombreAlumno].nombreProfesor == nombreProfesor;
    }
    
    
    /*puntuacion(A): devuelve los puntos que tiene el alumno A. Si el alumno no esta dado de alta
    con ningun profesor, entonces se lanza una excepcion domain error con mensaje El alumno A no
    esta matriculado.*/
    
    int puntuacion(alumno nombreAlumno){
        //el alumno no esta dado de alta
        if(mapa_alumnos.count(nombreAlumno) == 0){
            throw std::domain_error("El alumno " + nombreAlumno + " no esta matriculado");
        }else{
            return mapa_alumnos[nombreAlumno].puntos;
        }
    }
    
    /*actualizar(A, N): aumenta en una cantidad N la puntuaci´on del alumno A. Si el alumno no est´a
    dado de alta, entonces se lanza una excepci´on domain error con mensaje El alumno A no esta
    matriculado.*/
    
    void actualizar(alumno nombreAlumno, int puntosNuevos){
        //el alumno no esta dado de alta
        if(mapa_alumnos.count(nombreAlumno) == 0){
            throw std::domain_error("El alumno " + nombreAlumno + " no esta matriculado");
        }else{
            mapa_alumnos[nombreAlumno].puntos += puntosNuevos;
        }
    }
    
    
    /*  examen(P, N): obtiene una lista con los alumnos del profesor P, ordenados alfab´eticamente, que se
    presentar´an a examen por tener una puntuaci´on mayor o igual a N puntos.   */
    
    std::list<alumno> examen(profesor nombreProfesor, int puntosMinimosParaExamen){
        std::list<alumno> listaAdevolver;
        
        auto it_alumnoListaProfesor = mapa_profesores[nombreProfesor].begin();
        
        while(it_alumnoListaProfesor != mapa_profesores[nombreProfesor].end()){
            
            if(mapa_alumnos[*it_alumnoListaProfesor].puntos >= puntosMinimosParaExamen){
                listaAdevolver.push_back(*it_alumnoListaProfesor);
            }
            ++it_alumnoListaProfesor;
        }
    
        
        return listaAdevolver;
    }
    
    
    
   /* aprobar(A): el alumno A aprueba el examen y es borrado de la autoescuela, junto con toda la
    informaci´on que de ´el existiera. Si el alumno no est´a dado de alta, entonces se lanza una excepci´on
    domain error con mensaje El alumno A no esta matriculado.*/
    
    void aprobar(alumno nombreAlumno){
        if(mapa_alumnos.count(nombreAlumno) == 0){
            throw std::domain_error("El alumno " + nombreAlumno + " no esta matriculado");
        }else{
        mapa_profesores[mapa_alumnos[nombreAlumno].nombreProfesor].erase(mapa_alumnos[nombreAlumno].it_setAlumnosProfesor);
            mapa_alumnos.erase(nombreAlumno);
        }
    }
};

#endif /* autoescuela_h */
