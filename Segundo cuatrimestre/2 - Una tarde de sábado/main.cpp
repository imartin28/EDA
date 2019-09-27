// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"
#include "Pelicula.h"

//==========================>   EJERCICIO 2 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
/*TipoSolucion resolver(TipoDatos datos) {
 
 
 }*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPeliculas;
    std::cin >> numPeliculas;
    
    if (numPeliculas == 0)
        return false;
    
    Horas horaInicio;
    Horas duracion;
    std::string tituloPelicula;
    
    std::vector<Pelicula> v_peliculas(numPeliculas);
    
    for(int i = 0; i < numPeliculas; ++i){
        std::cin >> horaInicio >> duracion;
        getline(std::cin, tituloPelicula);
        Pelicula peli = Pelicula(horaInicio, duracion, tituloPelicula);
        v_peliculas[i] = peli;
    }
    
    sort(v_peliculas.begin(), v_peliculas.end());
    
    
    for(size_t i = 0; i < v_peliculas.size(); ++i){
        std::cout << v_peliculas[i] << std::endl;
    }
    
    std::cout << "---" << std::endl;
    
    //TipoSolucion sol = resolver(datos);
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda2.txt");
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
