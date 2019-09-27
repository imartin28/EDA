// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 8 <==========================//

/*COSTE:
 O(log(n)) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_numeros, int ini, int fin) {
    
    if(ini == fin){
        return v_numeros[ini];
    }else if(ini + 1 == fin){
        if(v_numeros[ini] < v_numeros[fin]) return v_numeros[ini];
        else return v_numeros[fin];
    }else{
        
        int mitadVector = (ini + fin) / 2;
        
        if(v_numeros[mitadVector] > v_numeros[ini]){
            return resolver(v_numeros, ini, mitadVector);
        }else return resolver(v_numeros, mitadVector, fin);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementosVector;
    std::cin >> numElementosVector;
    if (! std::cin)
        return false;
    
    std::vector<int> v_numeros(numElementosVector);
    int num;
    
    for(int i = 0; i < numElementosVector; ++i){
        std::cin >> num;
        v_numeros[i] = num;
    }
    
    int ini = 0;
    int fin = v_numeros.size() - 1;
    
    int sol = resolver(v_numeros, ini, fin);
    
    // escribir sol
    std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda8.txt");
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
