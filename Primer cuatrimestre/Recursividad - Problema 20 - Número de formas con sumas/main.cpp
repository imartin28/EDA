// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 20 <==========================//

/*COSTE:
 
 
 */



/*int sumas(matrix& m, const row& v, const int& number, const int& total, const int& i) {
    
    if(i == v.size() || total > number)
        
        return 0;
    
    else if(m[i][total] != -1)
        
        return m[i][total];
    
    else {
        
        m[i][total] = (total + v[i] == number) + sumas(m,v,number,total+v[i],i+1) + sumas(m,v,number,total,i+1);
        
        return m[i][total];
        
    }
    
}*/

// función que resuelve el problema
int resolver( std::vector<int>const& v_numero, std::vector<std::vector<int>>& matriz_resultado, int const& resultadoEsperado, int i, int sumaTotal) {
    
    if(i == v_numero.size() - 1 || sumaTotal > resultadoEsperado){
        return 0;
    
    }else if(matriz_resultado[i][sumaTotal] != -1){
        return ++matriz_resultado[i][sumaTotal];
    }else{
        
        matriz_resultado[i][sumaTotal] = (sumaTotal + v_numero[i] == resultadoEsperado) + resolver(v_numero, matriz_resultado, resultadoEsperado, i + 1, sumaTotal + v_numero[i]) + resolver(v_numero, matriz_resultado, resultadoEsperado, i + 1, sumaTotal);
        
        return matriz_resultado[i][sumaTotal];
    }
    
 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementosVector, resultadoEsperado;
    std::cin >> numElementosVector >> resultadoEsperado;
    
    if (! std::cin)
        return false;
    
    std::vector<int> v_numeros(numElementosVector);
    int num;
    
    for(int i = 0; i < numElementosVector; ++i){
        std::cin >> num;
        v_numeros[i] = num;
    }
    
    std::vector<std::vector<int>> matriz_resultado(numElementosVector, std::vector<int> (numElementosVector, -1));
    int sumaTotal = 0;
    int i = 0;

       
    int sol = resolver(v_numeros, matriz_resultado, resultadoEsperado, i, sumaTotal);
    
    
    std::cout << sol << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda20.txt");
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
