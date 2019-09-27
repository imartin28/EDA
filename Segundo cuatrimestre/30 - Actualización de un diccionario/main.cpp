// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream> //isstringstream
#include "hashmap_eda.h"
#include "set_eda.h"

//==========================>   EJERCICIO 30 <==========================//

/*COSTE:
 
    O(n+m) siendo n el numero de elementos del mapa antiguo y m el numero de elementos del mapa nuevo
 
 */

// función que resuelve el problema
void resolver(unordered_map<std::string, int>& mapaAntiguo, unordered_map<std::string, int>& mapaNuevo, set<std::string>& clavesNuevas, set<std::string>& clavesBorradas, set<std::string>& clavesModificadas) {
    
    for(auto it_mapaAntiguo = mapaAntiguo.begin(); it_mapaAntiguo != mapaAntiguo.end(); ++it_mapaAntiguo){
       //Si la clave no se encuentra en el nuevo mapa
        if(mapaNuevo.count(it_mapaAntiguo->clave) == 0){
            clavesBorradas.insert(it_mapaAntiguo->clave);
            
        }else{ //Si la clave si se encuentra en el nuevo mapa
            
            if(mapaAntiguo[it_mapaAntiguo->clave] != mapaNuevo[it_mapaAntiguo->clave]){
                //Si el valor de la clave es distinto en el nuevo mapa
                clavesModificadas.insert(it_mapaAntiguo->clave);
            }
        }
    }
    
    
    for(auto it_mapaNuevo = mapaNuevo.begin(); it_mapaNuevo != mapaNuevo.end(); ++it_mapaNuevo){
        //Si la clave del mapa nuevo no esta en el mapa antiguo
        if(mapaAntiguo.count(it_mapaNuevo->clave) == 0){
            clavesNuevas.insert(it_mapaNuevo->clave);
        }
    }
}


void mostrarResultado(set<std::string> const& claves){
    for(auto it = claves.begin(); it != claves.end(); ++it){
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso(int numCaso) {
    // leer los datos de la entrada
    std::string clave, principio;
    int valor;
    std::string antiguo, nuevo;
    set<std::string> clavesNuevas, clavesBorradas, clavesModificadas;
    
    //Clave -> palabra ; Value -> numero de apariciones de la clave
    unordered_map<std::string, int> mapaAntiguo, mapaNuevo;
    
    //Leer mapa antiguo
    if(numCaso == 0){
        std::cin.ignore();
    }
    
    getline(std::cin, antiguo);
    std::stringstream ss(antiguo);
    
    
    while(ss >> clave)
    {
        ss >> valor;
        mapaAntiguo.insert({clave, valor});
    }
    
    //Leer mapa nuevo
    getline(std::cin, nuevo);
    
    std::stringstream ssNuevo(nuevo);
    
    while(ssNuevo >> clave)
    {
        ssNuevo >> valor;
        mapaNuevo.insert({clave, valor});
    }

    
    
    resolver(mapaAntiguo, mapaNuevo, clavesNuevas, clavesBorradas, clavesModificadas);
    // escribir sol
    
    if(clavesNuevas.empty() && clavesModificadas.empty() && clavesBorradas.empty()){
        std::cout << "Sin cambios" << std::endl;
    }else {
        if(!clavesNuevas.empty()){
            std::cout << "+ ";
            mostrarResultado(clavesNuevas);
        }
        
        if(!clavesBorradas.empty()){
            std::cout << "- ";
            mostrarResultado(clavesBorradas);
        }
        
        
        if(!clavesModificadas.empty()){
            std::cout << "* ";
            mostrarResultado(clavesModificadas);
        }
        
       
    }
    std::cout << "----" << std::endl;
    
}



int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda30.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso(i);
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
