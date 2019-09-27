// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
long long int resolver(long long int primerDigito, long long int segundoDigito, long long int& resultado) {
    if(segundoDigito == 0){
        return resultado = 0;
        
    }else if(segundoDigito == 1){
       return resultado = primerDigito;
        
    }else if(segundoDigito > 1 && segundoDigito % 2 == 0){
       return resultado = resolver(2*primerDigito, segundoDigito/2, resultado);
    
    }else if(segundoDigito > 1 && segundoDigito % 2 == 1){
       return resultado = resolver(2*primerDigito, segundoDigito/2, resultado) + primerDigito;
    }
    return 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    
    long long int primerDigito, segundoDigito, resultado;
    
   
    std::cin >> primerDigito >> segundoDigito;
    long long int sol = resolver(primerDigito, segundoDigito, resultado);
    std::cout << sol << std::endl;
    
    
    // escribir sol
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda1.txt");
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
