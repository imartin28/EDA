// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 47 <==========================//

/*COSTE:
 
 O(n) siendo n el numero de elementos de cada fila y columna
 
 */

void contarCerosPorCadaColumna(std::vector<std::vector<int>>const& matriz, int& columna, std::vector<int>& v_cont_columnas, int& numColumnasCorrectas, int numCerosMin){
         //Contamos los ceros que hay por cada columna dentro de la franja
    for(int fila = 0; fila < matriz.size(); ++fila){
        if(matriz[fila][columna] == 0){
            ++v_cont_columnas[columna];
        }
    }
    
    //Comprobamos que el numero de ceros sea mayor o igual que el minimo que nos piden
    // y aumentamos entonces el numero de columnas correctas
    
    if(v_cont_columnas[columna] >= numCerosMin){
        ++numColumnasCorrectas;
    }
    
}



// función que resuelve el problema
int resolver(std::vector<std::vector<int>>const& matriz, int anchoFranja, int numColumnas, int numCerosMin) {
   
    std::vector<int> v_cont_columnas(matriz[0].size());
    int numColumnasCorrectas = 0;
    int cont_franjas_correctas = 0;
    
    for(int columna = 0; columna < anchoFranja; ++columna){
        
        contarCerosPorCadaColumna(matriz, columna, v_cont_columnas, numColumnasCorrectas, numCerosMin);
    }
    
    
    /* Comprobamos que el numero de columnas correctas sea mayor o igual que minimo de columnas que nos piden */
    if(numColumnasCorrectas >= numColumnas){
        ++cont_franjas_correctas;
    }
    
    
    for(int columna = anchoFranja; columna < matriz[0].size(); ++columna){
       /*Quitamos la primera columna para poder añadir una nueva*/
        if(v_cont_columnas[columna - anchoFranja] >= numCerosMin){
            --numColumnasCorrectas;
        }
        
        contarCerosPorCadaColumna(matriz, columna, v_cont_columnas, numColumnasCorrectas, numCerosMin);
        
        /* Comprobamos que el numero de columnas correctas sea mayor o igual que minimo de columnas que nos piden */
        
        if(numColumnasCorrectas >= numColumnas){
            ++cont_franjas_correctas;
        }
        
    }
    
    return cont_franjas_correctas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int filas, columnas, anchoFranja, numColumnas, numCerosMin;
    std::cin >> filas >> columnas >> anchoFranja >> numColumnas >> numCerosMin;
    
    if (! std::cin)
        return false;
    
    
    std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));
    int num;
    
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            std::cin >> num;
            matriz[i][j] = num;
        }
    }
    
    
    int sol = resolver(matriz, anchoFranja, numColumnas, numCerosMin);
    
    // escribir sol
    std:: cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda47.txt");
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
