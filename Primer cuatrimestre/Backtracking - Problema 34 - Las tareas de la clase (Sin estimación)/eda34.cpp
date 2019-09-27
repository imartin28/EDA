// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 34 (Sin estimacion) <==========================//

/*COSTE:
 
 
 */
bool esValida(std::vector<int>const& v_sol_tareas_asignada, std::vector<int>const& v_cont_alumnos_con_tarea, int nunMaxTareaPorAlumno, int indice_alumno, std::vector<int>const& v_hueco_libre_tarea, int k_tarea){
    
    if(v_cont_alumnos_con_tarea[indice_alumno] > nunMaxTareaPorAlumno){
        return false;
    }
    
    if(v_hueco_libre_tarea[k_tarea/2] < 0){
        return false;
    }
    
    if(k_tarea > 0){
        if(v_sol_tareas_asignada[k_tarea] == v_sol_tareas_asignada[k_tarea - 1] )
            return false;
            
    }
    return true;
    
}



bool esSolucion(int k_tareas, std::vector<int>const& v_sol_tareas_asignada ){
    if(k_tareas == v_sol_tareas_asignada.size() - 1){
        return true;
    }else
        return false;
}


// función que resuelve el problema
void resolver(std::vector<std::vector<int>>const& matriz, std::vector<int>& v_sol_tareas_asignada, std::vector<int>& v_cont_alumnos_con_tarea,  std::vector<int>& v_hueco_libre_tarea,  int numTareas, int numAlumnos, int numMaxTareaPorAlumno, int k_tareas, int& cont_puntuacion, int& cont_puntuacion_max) {
    
    for(int indice_alumno = 0; indice_alumno < numAlumnos; ++indice_alumno){
        
        v_sol_tareas_asignada[k_tareas] = indice_alumno;
        ++v_cont_alumnos_con_tarea[indice_alumno];
        --v_hueco_libre_tarea[k_tareas/2];
        cont_puntuacion += matriz[indice_alumno][k_tareas/2];
        
        if(esValida(v_sol_tareas_asignada, v_cont_alumnos_con_tarea, numMaxTareaPorAlumno, indice_alumno, v_hueco_libre_tarea, k_tareas)){
            if(esSolucion(k_tareas, v_sol_tareas_asignada)){
                if(cont_puntuacion > cont_puntuacion_max){
                    cont_puntuacion_max = cont_puntuacion;
                }
               
                
            }else{
                resolver(matriz, v_sol_tareas_asignada, v_cont_alumnos_con_tarea, v_hueco_libre_tarea, numTareas, numAlumnos, numMaxTareaPorAlumno, k_tareas+1, cont_puntuacion, cont_puntuacion_max);
            }
        }
        
        --v_cont_alumnos_con_tarea[indice_alumno];
        ++v_hueco_libre_tarea[k_tareas/2];
        cont_puntuacion -= matriz[indice_alumno][k_tareas/2];
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numTareas, numAlumnos, numMaxTareaPorAlumno;
    std::cin >> numTareas >> numAlumnos >> numMaxTareaPorAlumno;
    
    if (numTareas == 0 && numAlumnos == 0 && numMaxTareaPorAlumno == 0)
        return false;
    
    
    
    std::vector<std::vector<int>> matriz(numAlumnos, std::vector<int> (numTareas));
    int puntuacionPreferencia;
    
    for(int alumno = 0; alumno < numAlumnos; ++alumno){
        for(int tarea = 0; tarea < numTareas; ++tarea){
            std::cin >> puntuacionPreferencia;
            matriz[alumno][tarea] = puntuacionPreferencia;
        }
    }
    
    std::vector<int> v_sol_tareas_asignada(numTareas*2);
    std::vector<int> v_cont_alumnos_con_tarea(numAlumnos);
    std::vector<int> v_hueco_libre_tarea(numTareas, 2);
    int k_tareas = 0;
    int cont_puntuacion = 0;
    int cont_puntuacion_max = 0;
   
    resolver(matriz, v_sol_tareas_asignada, v_cont_alumnos_con_tarea, v_hueco_libre_tarea, numTareas, numAlumnos, numMaxTareaPorAlumno, k_tareas, cont_puntuacion, cont_puntuacion_max );
    
    // escribir sol
     std::cout << cont_puntuacion_max << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda34.txt");
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
