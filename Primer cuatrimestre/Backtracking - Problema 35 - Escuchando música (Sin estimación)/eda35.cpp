// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 35 <==========================//

/*COSTE:
 
 
 */

struct tCanciones {
    int duracion;
    int puntuacion;
};



// función que resuelve el problema
void resolver(std::vector<bool>& v_sol_canciones_escuchada_ida, std::vector<bool>& v_sol_canciones_escuchada_vuelta,  std::vector<tCanciones>const& v_canciones, std::vector<bool>& v_solMejor_canciones_ida, std::vector<bool>& v_solMejor_canciones_vuelta, int tiempoViaje_ida, int tiempoViaje_vuelta, int k_cancion,  int cont_puntuacion, int cont_duracion_ida, int cont_duracion_vuelta, int& puntuacionMax, int numCanciones) {
    
    /*  Escuchamos la cancion en el viaje de ida */
    v_sol_canciones_escuchada_ida[k_cancion] = true;
    cont_puntuacion += v_canciones[k_cancion].puntuacion;
    cont_duracion_ida += v_canciones[k_cancion].duracion;
    
    if(cont_duracion_ida <= tiempoViaje_ida){
        if(k_cancion == numCanciones - 1){
            if(cont_duracion_ida == tiempoViaje_ida && cont_duracion_vuelta == tiempoViaje_vuelta){
                if(cont_puntuacion > puntuacionMax){
                    puntuacionMax = cont_puntuacion;
                    v_solMejor_canciones_ida = v_sol_canciones_escuchada_ida;
                    v_solMejor_canciones_vuelta = v_sol_canciones_escuchada_vuelta;
                }
            }
        }else{
            resolver(v_sol_canciones_escuchada_ida ,v_sol_canciones_escuchada_vuelta, v_canciones, v_solMejor_canciones_ida, v_solMejor_canciones_vuelta, tiempoViaje_ida, tiempoViaje_vuelta, k_cancion + 1, cont_puntuacion, cont_duracion_ida, cont_duracion_vuelta,  puntuacionMax, numCanciones);
        }
    }
    
    
    cont_duracion_ida -= v_canciones[k_cancion].duracion;
    cont_puntuacion -= v_canciones[k_cancion].puntuacion;
    v_sol_canciones_escuchada_ida[k_cancion] = false;
    
    
    /* Escuchamos la cancion en el viaje de vuelta */
    v_sol_canciones_escuchada_vuelta[k_cancion] = true;
    cont_puntuacion += v_canciones[k_cancion].puntuacion;
    cont_duracion_vuelta += v_canciones[k_cancion].duracion;
    
    if(cont_duracion_vuelta <= tiempoViaje_vuelta){
        if(k_cancion == numCanciones - 1){
           if(cont_duracion_ida == tiempoViaje_ida && cont_duracion_vuelta == tiempoViaje_vuelta){
                if(cont_puntuacion > puntuacionMax){
                    puntuacionMax = cont_puntuacion;
                    v_solMejor_canciones_ida = v_sol_canciones_escuchada_ida;
                    v_solMejor_canciones_vuelta = v_sol_canciones_escuchada_vuelta;
                    
                }
           }
        }else{
            resolver(v_sol_canciones_escuchada_ida ,v_sol_canciones_escuchada_vuelta, v_canciones,v_solMejor_canciones_ida, v_solMejor_canciones_vuelta, tiempoViaje_ida, tiempoViaje_vuelta, k_cancion + 1, cont_puntuacion, cont_duracion_ida, cont_duracion_vuelta, puntuacionMax, numCanciones);
        }
    }
    
    
    cont_duracion_vuelta -= v_canciones[k_cancion].duracion;
    cont_puntuacion -= v_canciones[k_cancion].puntuacion;
    v_sol_canciones_escuchada_vuelta[k_cancion] = false;
    
    
    /*  No escuchamos la cancion    */
    
    if(k_cancion == numCanciones - 1){
        if(cont_duracion_ida == tiempoViaje_ida && cont_duracion_vuelta == tiempoViaje_vuelta){
            if(cont_puntuacion > puntuacionMax){
                puntuacionMax = cont_puntuacion;
                v_solMejor_canciones_ida = v_sol_canciones_escuchada_ida;
                v_solMejor_canciones_vuelta = v_sol_canciones_escuchada_vuelta;
            }
        }
    }else{
        resolver(v_sol_canciones_escuchada_ida ,v_sol_canciones_escuchada_vuelta, v_canciones, v_solMejor_canciones_ida, v_solMejor_canciones_vuelta,  tiempoViaje_ida, tiempoViaje_vuelta, k_cancion + 1, cont_puntuacion, cont_duracion_ida, cont_duracion_vuelta,  puntuacionMax, numCanciones);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCanciones, tiempoViaje_ida, tiempoViaje_vuelta;
    std::cin >> numCanciones >> tiempoViaje_ida >> tiempoViaje_vuelta;
    
    if (numCanciones == 0 && tiempoViaje_ida == 0 && tiempoViaje_vuelta == 0)
        return false;
    
    std::vector<tCanciones> v_canciones(numCanciones);
    tCanciones canciones;
    
    for(int i = 0; i < numCanciones; ++i){
        std::cin >> canciones.duracion >> canciones.puntuacion;
        v_canciones[i] = canciones;
      
    }
    
    
    std::vector<bool> v_sol_canciones_escuchadas_ida(numCanciones);
    std::vector<bool> v_sol_canciones_escuchadas_vuelta(numCanciones);
    
    std::vector<bool> v_solMejor_canciones_ida(numCanciones);
    std::vector<bool> v_solMejor_canciones_vuelta(numCanciones);
    int k_cancion = 0;
    int cont_puntuacion = 0;
    int cont_duracion_ida = 0;
    int cont_duracion_vuelta = 0;
    int puntuacion_max = 0;
    
    
    resolver(v_sol_canciones_escuchadas_ida,v_sol_canciones_escuchadas_vuelta,  v_canciones, v_solMejor_canciones_ida, v_solMejor_canciones_vuelta,  tiempoViaje_ida, tiempoViaje_vuelta, k_cancion, cont_puntuacion, cont_duracion_ida, cont_duracion_vuelta, puntuacion_max, numCanciones);
    
    // escribir sol
    if(puntuacion_max == 0){
        std::cout << "Imposible" << std::endl;
    }else{
        std::cout << puntuacion_max << std::endl;
    
        /*std::cout << "Canciones Ida: ";
        for(int i = 0; i < v_solMejor_canciones_ida.size(); ++i){
            if(v_solMejor_canciones_ida[i] == true)
                std::cout << i << ' ';
        }
        std::cout << std::endl;
        std::cout << "Canciones Vuelta: ";
        for(int i = 0; i < v_solMejor_canciones_vuelta.size(); ++i){
            if(v_solMejor_canciones_vuelta[i] == true)
                std::cout << i << ' ';
        }
        
        std::cout << std::endl;*/
    }
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda35.txt");
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
