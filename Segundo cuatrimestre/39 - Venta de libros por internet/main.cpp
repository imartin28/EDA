// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "ventaLibros.h"

//==========================>   EJERCICIO 39 <==========================//

/*COSTE:
 
 
 */


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numCasos;
    std::cin >> numCasos;
    if (! std::cin)
        return false;
    
    std::string operacion, nombreLibro;
    int numEjemplares;
    ventaLibros libros;
    
    // leer los datos de la entrada
    for(int i = 0; i < numCasos; ++i){
        std::cin>> operacion;
        
        if(operacion == "nuevoLibro"){
            std::cin >> numEjemplares;
            std::cin.ignore();
            getline(std::cin, nombreLibro);
            libros.nuevoLibro(numEjemplares, nombreLibro);
       
        }else if(operacion == "comprar"){
           std::cin.ignore();
           getline(std::cin, nombreLibro);
            try {
                libros.comprar(nombreLibro);
            } catch (std::invalid_argument e) {
                std::cout << e.what() << std::endl;
                std::cout << "---" << std::endl;
            } catch( std::out_of_range e){
                std::cout << e.what() << std::endl;
                std::cout << "---" << std::endl;
            }
        }else if( operacion == "estaLibro"){
            std::cin.ignore();
            getline(std::cin, nombreLibro);
            bool existeLibro = libros.estaLibro(nombreLibro);
            if(existeLibro){
                std::cout << "El libro " << nombreLibro << " esta en el sistema" << std::endl;
                std::cout << "---" << std::endl;
            }else{
                std::cout << "No existe el libro " << nombreLibro << " en el sistema" << std::endl;
                 std::cout << "---" << std::endl;
            }
        }else if(operacion == "elimLibro"){
            std::cin.ignore();
            getline(std::cin, nombreLibro);
            libros.elimLibro(nombreLibro);
        
        }else if(operacion == "numEjemplares"){
            std::cin.ignore();
           getline(std::cin, nombreLibro);
            try {
              int numEjemplares =  libros.numEjemplares(nombreLibro);
                
                std::cout << "Existen " << numEjemplares << " ejemplares del libro " << nombreLibro << std::endl;
                std::cout << "---" << std::endl;
            
            } catch (std::invalid_argument e) {
                std::cout << "No existe el libro " << nombreLibro << " en el sistema" << std::endl;
                std::cout << "---" << std::endl;
            }
        }else if(operacion == "top10"){
            std::list<std::string> listaLibrosTop10 = libros.top10();
            
            for(auto it = listaLibrosTop10.begin(); it != listaLibrosTop10.end(); ++it){
                std::cout << *it << std::endl;
            }
             std::cout << "---" << std::endl;
        }
    }
    std::cout << "------" << std::endl;
 
    // escribir sol
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2 EXAMEN/txt/eda39.txt");
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
