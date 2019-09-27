// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 23 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
bool esBalanceado(int& peso) {
    
    int pesoIzq, distanciaIzq, pesoDer, distanciaDer;
    std::cin >> pesoIzq >> distanciaIzq >> pesoDer >> distanciaDer;
    
    bool balanceadoIzq = true;
    bool balanceadoDer = true;
    
    
    if(pesoIzq == 0)
        balanceadoIzq = esBalanceado(pesoIzq);
    
    if(pesoDer == 0)
        balanceadoDer = esBalanceado(pesoDer);
    
    if(balanceadoIzq && balanceadoDer && (pesoIzq * distanciaIzq == pesoDer * distanciaDer)){
        peso = pesoIzq + pesoDer;
        return true;
    }else return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int peso = -1;
    bool sol = esBalanceado(peso);
    // escribir sol
    if(sol)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda23.txt");
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
