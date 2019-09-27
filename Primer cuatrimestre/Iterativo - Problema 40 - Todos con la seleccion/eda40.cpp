// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 40 <==========================//

/*COSTE:
 
 
 */

// función que resuelve el problema
void resolver(std::vector<int>const& v_partidos, int& numPartidosSeguidosGanados, std::vector<int>& v_numVecesGanadoNumPartidos, int& cont_maxRepetidoPartidosGanados, std::vector<int>& v_posicionFinalRacha, int& numPartidosJugadosDesdeQueGano ) {
    
    int cont_partidosGanados = 0;
    int indice_NumVecesGanaPartido = 0;
    
    
    for(int i = 0; i < v_partidos.size(); ++i){
        if(v_partidos[i] > 0){
            if(i == 0){
                ++cont_partidosGanados;
            }else{
                if(v_partidos[i - 1] <= 0){
                    cont_partidosGanados = 1;
                    if(v_numVecesGanadoNumPartidos[indice_NumVecesGanaPartido] != 0)
                        ++indice_NumVecesGanaPartido;
                    
                }else{
                    ++cont_partidosGanados;
                }
            }
            ++v_numVecesGanadoNumPartidos[indice_NumVecesGanaPartido];
            v_posicionFinalRacha[indice_NumVecesGanaPartido] = i;
            
            if(cont_partidosGanados > numPartidosSeguidosGanados){
                numPartidosSeguidosGanados = cont_partidosGanados;
            }
        }
    }
    
    v_numVecesGanadoNumPartidos.resize(indice_NumVecesGanaPartido + 1);
    v_posicionFinalRacha.resize(indice_NumVecesGanaPartido + 1);
    
    if(numPartidosSeguidosGanados > 0){
        for(int i = 0; i < v_numVecesGanadoNumPartidos.size(); ++i){
            if(v_numVecesGanadoNumPartidos[i] == numPartidosSeguidosGanados){
                ++cont_maxRepetidoPartidosGanados;
                numPartidosJugadosDesdeQueGano = v_posicionFinalRacha[i];
            }
        }
        numPartidosJugadosDesdeQueGano = v_partidos.size() - 1  - numPartidosJugadosDesdeQueGano;
    }
    
    if(numPartidosSeguidosGanados == 0){
        numPartidosJugadosDesdeQueGano = v_partidos.size();
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPartidosJugados;
    std::cin >> numPartidosJugados;
    if (! std::cin)
        return false;
    
    int resultadoPartido;
    
    std::vector<int> v_partidos(numPartidosJugados);
    for(int i = 0; i <numPartidosJugados; ++i){
        std::cin >> resultadoPartido;
        v_partidos[i] = resultadoPartido;
    }
    
   
    int numPartidosSeguidosGanados = 0;
    std::vector<int> v_numVecesGanadoNumPartidos(numPartidosJugados);
    int cont_maxRepetidoPartidosGanados = 0;
    std::vector<int> v_posicionFinalRacha(numPartidosJugados);
    int numPartidosJugadosDesdeQueGano = 0;
    
    resolver(v_partidos, numPartidosSeguidosGanados, v_numVecesGanadoNumPartidos, cont_maxRepetidoPartidosGanados, v_posicionFinalRacha, numPartidosJugadosDesdeQueGano);
    
    // escribir sol
    std::cout << numPartidosSeguidosGanados << ' ' << cont_maxRepetidoPartidosGanados << ' ' << numPartidosJugadosDesdeQueGano << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda40.txt");
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
