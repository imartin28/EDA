// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 14 <==========================//

/*COSTE:
    T(n) = c0 si n = 1
           c1 + 2(T(n/2))   en otro caso
 
 
 O(n) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
void resolver(std::vector<int>const& v_datosFila, int ini, int fin , bool& esDegradado, int& resultado) {
    
    if(ini == fin){
        esDegradado = true;
        resultado = v_datosFila[ini];
    
    }else if(ini + 1 == fin){
        if(v_datosFila[ini] < v_datosFila[fin]){
            esDegradado = true;
            
        }else{
            esDegradado = false;
        }
        
        resultado = v_datosFila[ini] + v_datosFila[fin];
    }else{
        
        int mitadVector = (ini + fin)/2;
        int resultadoIzq, resultadoDer;
        bool esDegradadoIzq, esDegradadoDer;
        
        resolver(v_datosFila, ini, mitadVector, esDegradadoIzq, resultadoIzq);
        resolver(v_datosFila, mitadVector + 1, fin,  esDegradadoDer, resultadoDer);
        
        if(resultadoIzq < resultadoDer && esDegradadoIzq && esDegradadoDer){
            esDegradado = true;
        }else
            esDegradado = false;
        
        resultado = resultadoIzq + resultadoDer;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int filas, columnas;
    std::cin >> filas >> columnas;
    
    if (! std::cin)
        return false;
    
    std::vector<std::vector<int>> matriz(filas, std::vector<int>(columnas));
   
    int valoresFilas;
    for(int i = 0; i < filas; ++i){
        for(int j = 0; j < columnas; ++j){
            std::cin >> valoresFilas;
            matriz[i][j] = valoresFilas;
            
        }
    }
    
    bool esDegradado = true;
    int ini = 0;
    int fin = matriz[0].size() - 1;
    int resultado = 0;
    
    for(int i = 0; i < matriz.size(); ++i){
        if(esDegradado)
            resolver(matriz[i], ini, fin, esDegradado, resultado);
    }

    
    // escribir sol
    if(!esDegradado)
        std::cout << "NO" << std::endl;
    else
        std::cout << "SI" << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda14.txt");
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
