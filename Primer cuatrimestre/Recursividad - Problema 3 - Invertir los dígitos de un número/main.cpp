// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 3 <==========================//

/*COSTE:
        T(n) =  c0 si n < 10
                c1 + T(n/10) si n >= 10
 
        T(n) pertenece a O(logn) siendo el n el numero de entrada.
 
 */


// función que resuelve el problema
long long int invertir(long long int numero, long long int resultado){
    if(numero < 10){
        return resultado*10 + numero;
    }else{
        return invertir(numero/10, numero%10 + resultado*10);
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
    
    long long int sol = invertir(numero, 0);
    
    // escribir sol
    std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda3.txt");
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
