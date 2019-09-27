// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "iPud.h"

//==========================>   EJERCICIO 38 <==========================//

/*COSTE:
 
 
 */



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string operacion;
    std::string nombreCancion, nombreArtista;
    int duracion, numCanciones;
    iPud ipud;
    
    std::cin >> operacion;
    if (! std::cin)
        return false;
    
    while(operacion != "FIN"){
        
        if(operacion == "addSong"){
            std::cin >> nombreCancion >> nombreArtista >> duracion;
            try{
                ipud.addSong(nombreCancion, nombreArtista, duracion);
                
            }catch(std::domain_error e){
                std::cout << "ERROR " << e.what() << std::endl;
            }
            
        }else if(operacion == "addToPlaylist"){
            std::cin >> nombreCancion;
            try {
                ipud.addToPlayList(nombreCancion);
                
            } catch (std::domain_error e) {
                std::cout << "ERROR " << e.what() << std::endl;
            }
        }else if(operacion == "current"){
            try {
                ipud.current();
            } catch (std::domain_error e) {
                std::cout << "ERROR " << e.what() << std::endl;
            }
            
        }else if(operacion == "play"){
            std::string cancion  = ipud.play();
            if(cancion == ""){
                std::cout << "No hay canciones en la lista" << std::endl;
            }else{
                std::cout << "Sonando " << cancion << std::endl;
            }
        }else if(operacion == "totalTime"){
            int duracionTotal = ipud.totalTime();
            std::cout << "Tiempo total " << duracionTotal << std::endl;
            
        }else if(operacion == "recent"){
            std::cin >> numCanciones;
            std::list<std::string> lista;
            lista = ipud.recent(numCanciones);
            if(lista.empty()){
                std::cout << "No hay canciones recientes" << std::endl;
            }else{
                std::cout << "Las " << lista.size() << " mas recientes" << std::endl;
                for(auto it = lista.begin(); it != lista.end(); ++it){
                    std::cout << "    " << *it << std::endl;
                }
            }
            
            
        }else if(operacion == "deleteSong"){
            std::cin >> nombreCancion;
            ipud.deleteSong(nombreCancion);
        }
        
        
        std::cin >> operacion;
    }
    
    std::cout << "----" << std::endl;
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda38.txt");
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
