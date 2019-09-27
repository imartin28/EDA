// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 42 <==========================//

/*COSTE:
 O(n) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_numero) {
    
    int cont_ceros = 0;
    int cont_unos = 0;
    int posicionEquilibrio = -1;
    
    for(int i = 0; i < v_numero.size(); ++i){
        if(v_numero[i] == 0)
            ++cont_ceros;
        
        if(v_numero[i] == 1)
            ++cont_unos;
        
        if(cont_ceros == cont_unos){
            posicionEquilibrio = i;
        }
        
    }
    
    return posicionEquilibrio;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamVector;
    std::cin >> tamVector;
    
    std::vector<int> v_numeros(tamVector);
    
    int num;
    
    for(int i = 0; i < tamVector; ++i){
        std:: cin >> num;
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
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda42.txt");
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
