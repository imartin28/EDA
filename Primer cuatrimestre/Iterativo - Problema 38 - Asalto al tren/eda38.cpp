
// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 38 <==========================//

/*COSTE:
    O(n) siendo n el numero de elementos del vector.
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_tren, int vagonesArobar,int& indiceInicial) {
    int gananciaTotal = 0;
    int maximo = 0;
   
    for(int i = 0; i < vagonesArobar; ++i){
        gananciaTotal += v_tren[i];
        
    }
    maximo = gananciaTotal;
    
    for(int i = vagonesArobar; i < v_tren.size(); ++i ){
        gananciaTotal = gananciaTotal - v_tren[i - vagonesArobar] + v_tren[i];
        if(maximo <= gananciaTotal){
            maximo = gananciaTotal;
            indiceInicial = (i - vagonesArobar) + 1;
            
        }
    }
    
    return maximo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int numVagones, vagonesArobar;
    std::cin >> numVagones >> vagonesArobar;
    
    std::vector<int> v_tren(numVagones);
    int gananciaPorVagon;
    for(int i = 0; i < v_tren.size(); ++i){
        std::cin >> gananciaPorVagon;
        v_tren[i] = gananciaPorVagon;
    }
    
    int indiceInicial = 0;
    int sol = resolver(v_tren, vagonesArobar, indiceInicial);
    // escribir sol
    std::cout << indiceInicial << ' '  << sol << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda38.txt");
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
