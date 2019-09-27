// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 4 <==========================//

/*COSTE:
    T(n) = c0 si n < 10
           c1 + T(n/10) si n >= 10
 
    T(n) pertenece a O(log(n)) siendo n el numero de entrada.
 
 */

// función que resuelve el problema
long long int resolver(long long int numero, long long int pot, long long int resultado ) {
    
    if(numero < 10){
        if(numero % 2 == 0){
            return resultado;
        }else return numero*pot + resultado;
     
    }else if(numero % 2 == 0){
        return resolver(numero/10, pot, resultado);
    }else{
        return resolver(numero/10, pot*10, (numero%10)*pot + resultado);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int numero;
    std::cin >> numero;
    if (! std::cin)
        return false;
    
   long long int sol = resolver(numero, 1, 0);
    
    std::cout << sol << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda4.txt");
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
