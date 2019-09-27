// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 7 <==========================//

/*COSTE:
 O(log(n)) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_carton, int ini, int fin, int numCantado) {
    
    if(ini == fin){
        if(numCantado + ini == v_carton[ini]){
            return v_carton[ini];
        }else{
            return -1;
        }
        
    }else if(ini + 1 == fin){
        if(numCantado + ini == v_carton[ini]){
            return v_carton[ini];
        }else if (numCantado + fin == v_carton[fin]){
            return v_carton[fin];
        }else{
            return -1;
        }
        
    }else{
        int mitadVector = (ini + fin) / 2;
        
        
        if(v_carton[mitadVector] <= numCantado){
            return resolver(v_carton, mitadVector + 1, fin, numCantado);
        }else{
            return resolver(v_carton, ini, mitadVector, numCantado);
        }
    }
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int numerosTotal, numCantado;
    std::cin >> numerosTotal >> numCantado;
    
    std::vector<int> v_carton(numerosTotal);
    int numeroCarton;
    
    for(int i = 0; i < numerosTotal; ++i){
        std::cin >> numeroCarton;
        v_carton[i] = numeroCarton;
    }
    int ini = 0;
    int fin = v_carton.size() - 1;
    
    int sol = resolver(v_carton,ini, fin, numCantado);
    // escribir sol
    if(sol == -1){
        std::cout << "NO" << std::endl;
    }else{
        std::cout << sol << std::endl;
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda7.txt");
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
