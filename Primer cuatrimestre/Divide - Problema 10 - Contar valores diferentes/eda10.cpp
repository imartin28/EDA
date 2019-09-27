// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 10 <==========================//

/*COSTE:
 
 T(n) = c0 si n = 1
        c1 + 2*T(n/2) en cualquier otro caso
 
 
 
 O(n) siendo n el numero de elementos del vector
 */

// función que resuelve el problema
void resolver(std::vector<int> v_numeros, int ini, int fin, int& cont_num_distintos) {
    
    if (ini == fin){
        cont_num_distintos = 1;
    }else if(ini + 1 == fin){
        
        if(v_numeros[ini] == v_numeros[fin])
          cont_num_distintos = 1;
        else
           cont_num_distintos = 2;
    }else{
        
        int mitadVector = (ini + fin) / 2;
        
        int cont_num_distintos_izq;
        int cont_num_distintos_der;
        
        resolver(v_numeros, ini, mitadVector, cont_num_distintos_izq);
        resolver(v_numeros, mitadVector + 1, fin, cont_num_distintos_der);
        
        if(v_numeros[mitadVector] == v_numeros[mitadVector + 1]){
            --cont_num_distintos_der;
        }
        
        cont_num_distintos = cont_num_distintos_izq + cont_num_distintos_der;
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
    
    for(int i = 0; i < v_numeros.size(); ++i){
        std::cin >> num;
        v_numeros[i] = num;
    }
    
    int ini = 0;
    int fin = v_numeros.size() - 1;
    int cont_num_distintos = 0;
    
   resolver(v_numeros, ini, fin, cont_num_distintos);
    
    // escribir sol
    
    std::cout << cont_num_distintos << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda10.txt");
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
