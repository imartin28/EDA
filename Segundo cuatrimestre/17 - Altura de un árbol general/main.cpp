// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>


//==========================>   EJERCICIO 17 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int altura(){
    
    int raiz;
    
    std::cin >> raiz;
    
    if (raiz == 0) {
        return 1;
    }
    else {
        int resultado_altura = 0;
        int resultado_aux;
        int resultMax = 0;
        for (int i = 0; i < raiz; i++) {
            
            resultado_aux = altura();
            
            if (resultado_aux > resultMax)
                resultMax = resultado_aux;
            
        }
        
        resultado_altura += resultMax + 1;
        return resultado_altura;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    int alturaMaxima = altura();
    std::cout << alturaMaxima << std::endl;

    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda17.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
