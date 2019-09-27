// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 43 <==========================//

/*COSTE:
 
 O(n) siendo n el numero de elementos del vector
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_numeros) {
    
    int sumaTotal = 0;
    int posicionNumMax = 0;
    int sumaNumMax = v_numeros[0];
    
    for(int i = 1; i < v_numeros.size(); ++i){
        
        if(v_numeros[i] < v_numeros[posicionNumMax]){
            sumaTotal += v_numeros[i];
        }
        
        else if(v_numeros[i] > v_numeros[posicionNumMax]){
            sumaTotal += sumaNumMax;
            sumaNumMax = v_numeros[i];
            posicionNumMax = i;
            
        }
        
        else{
            sumaNumMax += v_numeros[i];
        }
        
        
        
    }
    
    return sumaTotal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam_vector;
    std::cin >> tam_vector;
    
    std::vector<int> v_numeros(tam_vector);
    int num;
    
    for(int i = 0; i < v_numeros.size(); ++i){
        std::cin >> num;
        v_numeros[i] = num;
    }
    
    
    
    int sol = resolver(v_numeros);
    // escribir sol
    std::cout << sol << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda43.txt");
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
