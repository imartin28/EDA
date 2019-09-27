// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 18 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
int resolver(int& cont_becarios, int cont_jefes, int numMinJefes) {
    int raiz;
    std::cin >> raiz;
    
    if(raiz == 0){
        if(cont_jefes >= numMinJefes){
            ++cont_becarios;
        }
    }else{
        
        for(int i = 0; i < raiz; ++i){
            ++cont_jefes;
            resolver(cont_becarios, cont_jefes, numMinJefes);
            --cont_jefes;
        }
    }
    
    return cont_becarios;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numMinJefes;
    std::cin >> numMinJefes;
    
    if (! std::cin)
        return false;
    
    int cont_jefes = 0;
    int cont_becarios = 0;
    int sol = resolver(cont_becarios, cont_jefes, numMinJefes);
    
    // escribir sol
    std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda18.txt");
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
