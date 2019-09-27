// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 22 <==========================//

/*COSTE:
    T(n) = c0 si n = 1
           c1 + 2*(T(n/2))  en otro caso
 
 
    O(n) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
int numPartidosJugados(std::vector<std::string>const& v_jugadores, int numRondaInfo, int ini, int fin, bool& hayJugador, int& rondaActual) {
    
    if(ini + 1 == fin){
        if(v_jugadores[ini] == "NP" && v_jugadores[fin] == "NP"){ //no se ha presentado ningun jugador
            hayJugador = false;
            rondaActual = 1;
            return 0;   //num partidos jugados
            
        }else if(v_jugadores[ini] == "NP" || v_jugadores[fin] == "NP"){ //se ha presentado al menos uno de los dos
            hayJugador = true;
            rondaActual = 1;
            return 0;          //num partidos jugados
        }else{
            hayJugador = true;      //se ha presentado los dos jugadores
            rondaActual = 1;
            return 1;       //num partidos jugados
        }
    }else{
        
        int mitadVector = (ini + fin)/2;
        int numPartidosJugadosActuales;
        int rondaActualIzq, rondaActualDer;
        bool hayJugadorIzq, hayJugadorDer;
        
        
            int numPartidasJugadasIzq = numPartidosJugados(v_jugadores, numRondaInfo, ini, mitadVector, hayJugadorIzq, rondaActualIzq);
            int numPartidasJugadasDer = numPartidosJugados(v_jugadores, numRondaInfo, mitadVector+1, fin, hayJugadorDer, rondaActualDer);
            
        
        numPartidosJugadosActuales = numPartidasJugadasIzq + numPartidasJugadasDer;
        rondaActual = rondaActualIzq + 1;
        hayJugador = hayJugadorDer;   //da igual que valor poner, si izquierda o derecha
        
        
        if(rondaActual <= numRondaInfo){
            if(!hayJugadorIzq && !hayJugadorDer){ //En caso de que no haya ningun jugador
                
                hayJugador = false;
                numPartidosJugadosActuales = 0;
                
            }else if(!hayJugadorIzq || !hayJugadorDer){       //Al menos hay un jugador
               
                hayJugador = true;
                numPartidosJugadosActuales = (numPartidasJugadasIzq + numPartidasJugadasDer);
            
            }else{      //hay dos jugadores
                hayJugador = true;
                numPartidosJugadosActuales = (numPartidasJugadasIzq + numPartidasJugadasDer) + 1;
            }
        }
        
        return numPartidosJugadosActuales;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementosVector, numRondaInfo;
    std::cin >> numElementosVector >> numRondaInfo;
    if (! std::cin)
        return false;
    
    
    std::vector<std::string> v_jugadores(numElementosVector);
    std::string jugador;
    
    for(int i = 0; i < numElementosVector; ++i){
        std::cin >> jugador;
        v_jugadores[i] = jugador;
    }
    int ini = 0;
    int fin = v_jugadores.size() - 1;
    int rondaActual = 0;
    bool hayJugador = true;
    
    int sol = numPartidosJugados(v_jugadores, numRondaInfo, ini, fin, hayJugador, rondaActual);
    
    // escribir sol
    std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda22.txt");
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
