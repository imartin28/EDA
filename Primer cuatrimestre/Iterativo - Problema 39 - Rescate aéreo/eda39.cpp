// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 39 <==========================//

/*COSTE:
 O(n) siendo n el numero de elementos del vector.
 
 */

// función que resuelve el problema
void resolver(std::vector<int>const v_edificios,int alturaTransporte, int& inicio, int& fin) {
    int contEdificios = 0;
    int contMaxEdificios = 0;
    
    for(int i = 0; i < v_edificios.size(); ++i){
        if(v_edificios[i] > alturaTransporte){
            ++contEdificios;            
            
            if(contEdificios > contMaxEdificios){
                contMaxEdificios = contEdificios;
                fin = i;
                inicio = fin - contMaxEdificios + 1;
            }
          
        }else{
            contEdificios = 0;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numEdificios, alturaTransporte;
    std::cin >> numEdificios >> alturaTransporte;
    
    std::vector<int> v_edificios(numEdificios);
    int alturaEdificio;
    
    for(int i = 0; i < numEdificios; ++i){
        std::cin >> alturaEdificio;
        v_edificios[i] = alturaEdificio;
    }
    
    
    int inicio = 0, fin = 0;
    
    resolver(v_edificios, alturaTransporte,  inicio, fin);
    // escribir sol
    std::cout << inicio << ' ' << fin << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda39.txt");
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
