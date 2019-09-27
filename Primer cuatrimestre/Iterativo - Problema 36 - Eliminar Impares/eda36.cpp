// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 36 <==========================//

/*COSTE:
 O(n) siendo n el numero de elementos del vector.
 
 */

// función que resuelve el problema
int resolver(std::vector<int>& v_numeros ) {
    
    int valornuevo = 0;
    for(int i = 0; i < v_numeros.size(); ++i){
        if(v_numeros[i] % 2 == 0){
            v_numeros[valornuevo] = v_numeros[i];
            ++valornuevo;
        }
    }
    v_numeros.resize(valornuevo);
    return v_numeros.size();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int sizeVector;
    std::cin >> sizeVector;
    
    std::vector<int> v_numeros(sizeVector);
   
    int elemVector;
    
    for(int i = 0; i < v_numeros.size(); ++i){
        std::cin >> elemVector;
        v_numeros[i] = elemVector;
    }
    
    int sol = resolver(v_numeros);
    // escribir sol
    for(int i = 0; i < v_numeros.size(); ++i){
        std::cout << v_numeros[i] << ' ';
    }
    std::cout << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda36.txt");
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
