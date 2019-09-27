// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//==========================>   EJERCICIO 16 <==========================

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(std::vector<int>& v_naves, int ini, int fin) {
    
    if (ini == fin)
        return 0;
    if (ini + 1 == fin) {
        if (v_naves[ini] > v_naves[ini + 1]) {
            std::swap(v_naves[ini], v_naves[ini + 1]);
            return 1;
        }
        else
            return 0;
        
    }
    else {
        int mitadVector = (ini + fin) / 2;
        int resIzq = resolver(v_naves, ini, mitadVector);
        int resDer = resolver(v_naves, mitadVector, fin);
        
        int inv = 0, i = ini, j = mitadVector;
        
        while (i < mitadVector && j < fin){ //comparar ambas mitades
            if (v_naves[i] < v_naves[j]) i++; //si estan ordenados avanzamos
            else{ //si no estan ordenados sumanos las inversiones
                inv += (mitadVector - i);
                j++;
            }
            
        }
        //vamos a ordenar.
        std::vector<int> aux(fin - ini);
        
        //Ordenar con la funcion merge de la libreria algorithm
        merge((v_naves.begin() + ini), (v_naves.begin() + mitadVector), (v_naves.begin() + mitadVector), (v_naves.begin() + fin), aux.begin());
        
        for (int i = 0; i < aux.size(); ++i)
            v_naves[ini + i] = aux[i];
        
        return resIzq + resDer + inv;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numNaves;
    std::cin >> numNaves;
    
    if (! std::cin)
        return false;
    
    int posicionNavesDespuesAtaque;
    std::vector<int> v_naves(numNaves);
    for(int i = 0; i < v_naves.size(); ++i){
        std::cin >> posicionNavesDespuesAtaque;
        v_naves[i] = posicionNavesDespuesAtaque;
    }
    
    int ini = 0;
    int fin = v_naves.size() - 1;
  
    int sol = resolver(v_naves, ini, fin);
    
    // escribir sol
    
    std::cout << sol << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda16.txt");
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
