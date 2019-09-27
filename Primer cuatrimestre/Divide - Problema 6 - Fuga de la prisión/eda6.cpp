// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 06 <==========================//

/*COSTE:
    
 
 */

// función que resuelve el problema
char resolver(std::vector<char>const& v_presidiarios, int& ini, int& fin) {
    
    if(ini + 1 == fin){
        return v_presidiarios[ini] + 1;
    }else{
        int mitadVector = (ini + fin) / 2;
        
        if(v_presidiarios[mitadVector] > v_presidiarios[0] + mitadVector ){
            return resolver(v_presidiarios, ini, mitadVector);
        }else{
            return resolver(v_presidiarios, mitadVector , fin);
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    char letraPrimerPresidiario, letraUltimoPresidiario;
    std::cin >> letraPrimerPresidiario >> letraUltimoPresidiario;
    std::vector<char> v_presidiarios;
    
    char letraPresidiario;
    
    for(char i = letraPrimerPresidiario; i < letraUltimoPresidiario; ++i){
        std::cin >> letraPresidiario;
        v_presidiarios.push_back(letraPresidiario);
    }
    
    int ini = 0;
    int fin = v_presidiarios.size() - 1;
    
    if(v_presidiarios[0] != letraPrimerPresidiario){
        std::cout << letraPrimerPresidiario << std::endl;
        
    }else if(v_presidiarios[v_presidiarios.size() - 1] != letraUltimoPresidiario){
        std::cout << letraUltimoPresidiario << std::endl;
    }else{
        char sol = resolver(v_presidiarios, ini, fin);
        // escribir sol
        std::cout << sol << std::endl;
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda6.txt");
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
