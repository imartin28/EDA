// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 21 <==========================//

/*COSTE:
 
 T(n) = c0 si n = 1
        c1 + T(n/2) en otro caso
 
 
 O(n) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_numeros, int ini, int fin) {
    
    if(ini == fin){
        return 1;
        
    }else if(ini + 1 == fin){
        
        if(v_numeros[ini] % 2 == 1 && v_numeros[fin] % 2 == 1)    return 0;
        else if(v_numeros[ini] % 2 == 1 || v_numeros[fin] % 2 == 1)    return 1;
        else  return 2;

    }else{
        
       int mitadVector = (ini + fin)/2;
     
       int numParesIzq = resolver(v_numeros, ini, mitadVector);
       int numParesDer = resolver(v_numeros, mitadVector+1, fin);
        
        
        if(abs(numParesIzq - numParesDer) <= 2){
            return numParesIzq + numParesDer;
        }else{
            return -1;
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementosVector;
    std::cin >> numElementosVector;
    
    if (numElementosVector == 0)
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
    
    // escribir sos
    if(sol > -1){
        std::cout << "SI" << std::endl;
    }else
        std::cout << "NO" << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda21.txt");
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
