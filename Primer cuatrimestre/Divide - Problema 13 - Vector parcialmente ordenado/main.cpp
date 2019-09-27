// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 13 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
void resolver(std::vector<int> v_numeros, int ini, int fin, int& max, int& min) {
    
    if(ini == fin){
        max = v_numeros[ini];
        min = v_numeros[fin];
        
        
    }else if(ini + 1 == fin){
        if(v_numeros[ini] <= v_numeros[fin]){
            max = v_numeros[fin];
            min = v_numeros[ini];
            
        }else{
            max = v_numeros[ini];
            min = v_numeros[fin];
        }
    }else{
        int mitadVector = (ini + fin) / 2;
        int max_der, max_izq;
        int min_der, min_izq;
        
        resolver(v_numeros, ini, mitadVector, max_izq, min_izq);
        resolver(v_numeros, mitadVector+1, fin, max_der, min_der);
        
        
        if(max_der >= max_izq && min_izq <= min_der){
            max = max_der;
            min = min_izq;
            
        }else{
            max = -1;
            min = -1;
        }
            
        
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numero;
    
    std::cin >> numero;
    if(numero == 0)
        return false;
    
    
    std::vector<int> v_numeros;
   
    while(numero != 0){
        
        v_numeros.push_back(numero);
        std::cin >> numero;
    }
   
    
    int ini = 0;
    int fin = v_numeros.size() - 1;
    int max = 0;
    int min = 0;
    
   resolver(v_numeros, ini, fin, max, min);
    
    // escribir sol
    if(min != -1 && max != -1){
        std::cout << "SI" << std::endl;
    }else{
       std::cout << "NO" << std::endl;
    }
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda13.txt");
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
