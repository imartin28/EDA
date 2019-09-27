// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 19 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<std::vector<int>>& matriz, int filas, int columnas) {
    if(columnas == 0){
        return 1;
    }else if(filas == columnas){
        return 1;
    }else{
        
        if(matriz[filas-1][columnas-1] == -1){
            matriz[filas-1][columnas-1] = resolver(matriz, filas-1, columnas - 1);
        }
        
        if(matriz[filas-1][columnas] == -1){
            matriz[filas-1][columnas] = resolver(matriz, filas-1, columnas);
        }
        
        return matriz[filas-1][columnas-1] + matriz[filas-1][columnas];
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int filas, columnas;
    std::cin >> filas >> columnas;
    if (! std::cin)
        return false;
    
    
    std::vector<std::vector<int>> matriz(filas + 1, std::vector<int>(columnas + 1, -1));
    
    int sol = resolver(matriz, filas, columnas);
    
    std::cout << sol << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda19.txt");
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
