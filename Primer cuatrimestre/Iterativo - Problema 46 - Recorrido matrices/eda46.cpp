// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 46 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<std::vector<int>>const& matriz) {
    
    int cont_numeros_colocados_fila = 0;
    
    
    for(int fila = 0; fila < matriz.size(); ++fila){
        for(int columna = 0; columna < matriz[0].size(); ++columna){
            if(matriz[fila][columna] == fila){
                ++cont_numeros_colocados_fila;
            }
        }
        
    }
    return cont_numeros_colocados_fila;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int filas, columnas;
    std::cin >> filas >> columnas;
    
    if (! std::cin)
        return false;
    
    std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas, 0));
    int num;
    
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            std::cin >> num;
            matriz[i][j] = num;
        }
    }
    
    int sol = resolver(matriz);
    
    // escribir sol
    std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda46.txt");
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
