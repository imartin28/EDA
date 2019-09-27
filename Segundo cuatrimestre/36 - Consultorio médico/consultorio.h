//
//  consultorio.h
//  EDA
//
//  Created by Irene Martin berlanga on 21/05/2019.
//  Copyright © 2019 Irene Martin berlanga. All rights reserved.
//

#ifndef consultorio_h
#define consultorio_h
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "fechas.h"
#include <map>
#include <unordered_map>
#include <list>


class consultorio{
    using medico = std::string;
    using paciente = std::string;
    
private:
    
    
    std::unordered_map<medico, std::map<fechas, paciente>> mapa_medicos;
    
public:
    
    void nuevoMedico(medico const& m){
        mapa_medicos[m];
    }
    
    
    void pideConsulta(paciente const& p, medico const& m, fechas const& f){
        if(mapa_medicos.count(m) == 0){
            throw std::domain_error("Medico no existente");
        }else if(mapa_medicos[m].count(f) == 1){
            throw std::domain_error("Fecha ocupada");
        }else{
            
            mapa_medicos[m][f] = p;
        
        }
    }
    
    
    paciente siguientePaciente(medico const& m){
        if(mapa_medicos.count(m) == 0){
            throw std::domain_error("Medico no existente");
        }else if(mapa_medicos[m].empty()){ //que no tiene consultas ese medico
            throw std::domain_error("No hay pacientes");
        }else{
            return mapa_medicos[m].begin()->second;
        }
    }
    
    
    void atiendeConsulta(medico const& m){
        if(mapa_medicos.count(m) == 0){
            throw std::domain_error("Medico no existente");
        }else if(mapa_medicos[m].empty()){
            throw std::domain_error("No hay pacientes");
        }else{
            mapa_medicos[m].erase(mapa_medicos[m].begin()->first);
        }
    }
    
    
    std::list<std::pair<paciente, fechas>> listaPacientes(medico const& m, int dia){
        if(mapa_medicos.count(m) == 0){
            throw std::domain_error("Medico no existente");
        }else {
            std::list<std::pair<paciente, fechas>> lista_resultado;
            fechas fecha(dia);
            
            auto it_paciente = mapa_medicos[m].lower_bound(fecha);
            
            while(it_paciente != mapa_medicos[m].end() && dia == it_paciente->first.getDia()){
                lista_resultado.push_back({it_paciente->second, it_paciente->first});
                ++it_paciente;
            }
            
            
            return lista_resultado;
       
        }
    }
    
};

#endif /* consultorio_h */
