
// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 05 <==========================//

/*COSTE:
 O(n) siendo n el numero de elementos del vector.
 
*/

// función que resuelve el problema
int resolver(std::vector<int>const& vector_numeros, int& ini, int& fin) {
    if(ini == fin){ //vector con un elemento
        return vector_numeros[ini];
    
    }else if(ini + 1 == fin){   //vector con dos elementos
        if(vector_numeros[ini] < vector_numeros[fin]){
            return vector_numeros[ini];
        }else{
            return vector_numeros[fin];
        }
    }else{
        int mitadVector = (ini + fin) / 2;
        
        if(vector_numeros[mitadVector] < vector_numeros[mitadVector - 1]){
            return resolver(vector_numeros, mitadVector, fin);
        }else{
           return resolver(vector_numeros, ini, mitadVector);
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    std::cin >> numero;
    if (! std::cin)
        return false;
    
    std::vector<int>vector_numeros(numero);
    int digito;
    
    for(int i = 0; i < numero; ++i){
        std::cin >> digito;
        vector_numeros[i] = digito;
    }
    
    int ini = 0;
    int fin = vector_numeros.size() - 1;
    
    int sol = resolver(vector_numeros, ini, fin);
    
    std::cout << sol << std::endl;
    
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda5.txt");
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
