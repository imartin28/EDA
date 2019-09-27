// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "hashmap_eda.h"
#include <set>

//==========================>   EJERCICIO 32 <==========================//

/*COSTE:
 En el primer bucle for:
    O(n*m) siendo n el numero de deportes y m el numero de alumnos.
 
 En la funcion sort:
    O(nlog(n)) siendo n el numero de deportes
 
 
 Por lo que el coste final es:
    max(n*m, nlogn) siendo n el numero de deportes y m el numero de alumnos.
 */

// función que resuelve el problema
struct deportes {
    std::string nombreDeporte;
    int numAlumnosApuntados;
};

bool operator>(deportes const& deportes1, deportes const& deportes2){
    if(deportes1.numAlumnosApuntados == deportes2.numAlumnosApuntados){
        return deportes1.nombreDeporte < deportes2.nombreDeporte;
    }else{
        return deportes1.numAlumnosApuntados > deportes2.numAlumnosApuntados;
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string palabra;
    std::cin >> palabra;
    if (!std::cin)
        return false;
    //Clave --> nombre del deporte y Valor --> Nombre del alumno
    unordered_map<std::string,std::set<std::string>> mapa_deporte;
    
    //Clave --> nombre del alumno y Valor --> Nombre del deporte
    unordered_map<std::string,std::set<std::string>> mapa_alumno;
    std::string deporte;
    
    
    std::vector<deportes> v_solucion;
    int contador_alumnos = 0;
    while(palabra[0] != '_'){
        //si es un deporte
        if(isupper(palabra[0])){
            mapa_deporte[palabra];
            deporte = palabra;
        }
        //si es un nombre de alumno
        if(islower(palabra[0])){
            mapa_deporte[deporte].insert(palabra);
            mapa_alumno[palabra].insert(deporte);
        }
        std:: cin >> palabra;
    }
    
    for(auto it_deporte = mapa_deporte.begin(); it_deporte != mapa_deporte.end(); ++it_deporte){
        for(auto it_alumnos = (it_deporte->valor).begin(); it_alumnos != (it_deporte->valor).end(); ++it_alumnos){
            if(mapa_alumno[*it_alumnos].size() <= 1){
                ++contador_alumnos;
            }
        }
        v_solucion.push_back({it_deporte->clave, contador_alumnos});
        contador_alumnos = 0;
    }
    
    std::sort(v_solucion.begin(), v_solucion.end(), std::greater<deportes>());
    
    for(int i = 0; i < v_solucion.size(); ++i){
        std::cout << v_solucion[i].nombreDeporte << ' ' << v_solucion[i].numAlumnosApuntados << std::endl;
    }
    
    std::cout << "***" << std::endl;
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda32.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    while (resuelveCaso())
        ;
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
