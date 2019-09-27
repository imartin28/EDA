// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 48 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<std::vector<int>>const& matriz, int numCuadrantesPescaBarco) {
    
    int num_peces_total = 0;
   
    
    /*  Ventana */
    for(int i = 0; i < numCuadrantesPescaBarco; ++i){
        for(int j = 0; j < numCuadrantesPescaBarco; ++j){
            num_peces_total += matriz[i][j];
            
        }
    }
    
    int num_peces_max = num_peces_total;
    
    for(int i = num_peces_total - 1; i < matriz.size(); ++i){
        if(i >= num_peces_total){
            
        }
        
        
        for(int j = num_peces_total; j < matriz[0].size(); ++j){
            
            for(int x = 0; x < numCuadrantesPescaBarco; ++x){
                num_peces_total -= matriz[x][j - numCuadrantesPescaBarco];
                
            }
            
            for(int z = 0; z < numCuadrantesPescaBarco; ++z){
                num_peces_total += matriz[z][j];
            }
    
            
            if(num_peces_total > num_peces_max){
                num_peces_max = num_peces_total;
            }
        }
    }
    return num_peces_max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numCuadrantesParaPescar, numCuadrantesPescaBarco;
    std::cin >> numCuadrantesParaPescar >> numCuadrantesPescaBarco;
    
    if (! std::cin)
        return false;
    
    std::vector<std::vector<int>> matriz(numCuadrantesParaPescar, std::vector<int> (numCuadrantesParaPescar));
    
    int numero;
    
    for(int i = 0; i < numCuadrantesParaPescar; ++i){
        for(int j = 0; j < numCuadrantesParaPescar; ++j){
            std::cin >> numero;
            matriz[i][j] = numero;
        }
    }
    
    
    int peces = resolver(matriz, numCuadrantesPescaBarco);
    
    std::cout << peces << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda48.txt");
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
