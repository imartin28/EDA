// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 37 <==========================//

/*COSTE:
 O(n) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
bool resolver(std::vector<int>const& v_elementos, int p) {
    int maximo = v_elementos[0];
    int minimo = v_elementos[p + 1];
    
    for(int i = 1; i <= p; ++i){
        if(v_elementos[i] > maximo){
            maximo = v_elementos[i];
        }
    }
    
    for(int i = p + 1; i < v_elementos.size(); ++i){
        if(v_elementos[i] < minimo){
            minimo = v_elementos[i];
        }
    }
 
    if(maximo < minimo){
        return true;
    }else{
        return false;
    }
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int elementosVector, p;
    std::cin >> elementosVector >> p;
    
    std::vector<int> v_elementos(elementosVector);
    int numero;
    for(int i = 0; i < elementosVector; ++i){
        std::cin >> numero;
        v_elementos[i] = numero;
    }
    if( p == v_elementos.size() - 1){
        std::cout << "SI" << std::endl;
    }else{
        bool seCumple = resolver(v_elementos, p);
        // escribir sol
        if(seCumple){
            std::cout << "SI" << std::endl;
            
        }else{
            std::cout << "NO" << std::endl;
        }
    }
    
    
   
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda37.txt");
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
