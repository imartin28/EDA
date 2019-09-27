// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 9 <==========================//

/*COSTE:
 
    T(n) = c0   si n = 1,2
           c1 + T(n/2)  en otro caso
 
 
    T(n) = c1 + T(n/2) = c1 + c1 + T(n/4) = c1 + c1 + c1 + (n/8) = k*c1 + T(n/2^k)
 
    n/2^k = 1  =>  n = 2^k     =>  k = log2n
 
    c1*log2(n) + T(n/2^log2n)
 
    T(n) = c1*log2(n) + c0 pertenece a  O(log(n)) siendo n el numero de elementos del vector
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_numeros, int ini, int fin) {
    if(ini == fin){
        return v_numeros[ini];
    }
    else if(ini + 1 == fin){
        if(v_numeros[ini] % 2 == 0)
            return v_numeros[fin];
        else
            return v_numeros[ini];
    }
    else{
        int mitadVector = (ini + fin)/2;
        
        if(v_numeros[mitadVector] % 2 == 1)
            return v_numeros[mitadVector];
        else if(v_numeros[ini] + (mitadVector - ini) * 2 != v_numeros[mitadVector]){
            return resolver(v_numeros, ini, mitadVector - 1);
        }
        else
            return resolver(v_numeros, mitadVector + 1, fin);
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
    
    // escribir sol
    std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda9.txt");
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
