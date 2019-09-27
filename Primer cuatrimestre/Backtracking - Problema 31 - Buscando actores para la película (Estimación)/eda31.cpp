// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 31 (con estimacion)<==========================//



struct tSol {
    int papelAsignado;
    int actorEscogido;
};




bool esValida(std::vector<bool>const& marcas_actor_ocupado, int indiceActor, int cont_presupuesto, int presupuestoTotal, int cont_puntuacion_total, int puntuacionMin){
    
    if(marcas_actor_ocupado[indiceActor]){    //El actor esta ocupado en otro papel
        return false;
    }
    
    
    if(cont_presupuesto > presupuestoTotal){        //Se ha superado el presupuesto maximo para la pelicula
        return false;
    }
    
    
    if(cont_puntuacion_total < puntuacionMin){   //El actor no tiene la puntuacion min necesaria para interpretar el papel
        return false;
    }
    
    
    return true;
}


// función que resuelve el problema
void resolver(std::vector<std::vector<int>>const& matriz, std::vector<int>const& v_sueldo_actor,  std::vector<bool>& marcas_actor_ocupado, int const numPapeles, int k_indicePapeles, int const presupuestoTotal, int cont_puntuacion_total, int cont_presupuesto, int const puntuacionMin, int& maxPuntuacionTotal, int& presupuestoSolucion,  std::vector<tSol>& v_solucion,  std::vector<tSol>& v_papelesAsignados, std::vector<int>const& v_estimacion_mayor_puntuacion ) {
    
    for(int indiceActor = 0; indiceActor < matriz[0].size(); ++indiceActor){
       
        cont_puntuacion_total += matriz[k_indicePapeles][indiceActor];
        cont_presupuesto += v_sueldo_actor[indiceActor];
        v_papelesAsignados[k_indicePapeles] = {k_indicePapeles, indiceActor};
        
        if(esValida(marcas_actor_ocupado, indiceActor, cont_presupuesto, presupuestoTotal, cont_puntuacion_total, puntuacionMin)){
            
            if(k_indicePapeles == numPapeles - 1){      //esSolucion
                if(cont_puntuacion_total > maxPuntuacionTotal){
                    maxPuntuacionTotal = cont_puntuacion_total;
                    presupuestoSolucion = cont_presupuesto;
                    v_solucion = v_papelesAsignados;    //Copia el vector
                }
                
                
            }else{
                marcas_actor_ocupado[indiceActor] = true;
                int puntuacionEstimada = cont_puntuacion_total + v_estimacion_mayor_puntuacion[k_indicePapeles + 1];
                
                if(puntuacionEstimada > maxPuntuacionTotal){
                    resolver(matriz, v_sueldo_actor, marcas_actor_ocupado, numPapeles, k_indicePapeles + 1, presupuestoTotal, cont_puntuacion_total, cont_presupuesto, puntuacionMin, maxPuntuacionTotal, presupuestoSolucion, v_solucion, v_papelesAsignados, v_estimacion_mayor_puntuacion);
                }
                marcas_actor_ocupado[indiceActor] = false;   // a la vuelta de la llamada recursiva se desmarcará
            }
            
           
        }
        
        
        cont_puntuacion_total -= matriz[k_indicePapeles][indiceActor];
        cont_presupuesto -= v_sueldo_actor[indiceActor];
        
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numPapeles, numActores, presupuestoTotal, puntuacionMin;
    std::cin >> numPapeles >> numActores >> presupuestoTotal >> puntuacionMin;
    
    if (numPapeles == 0)
        return false;
    
    std::vector<int> v_sueldo_actor(numActores);
    int sueldoActor;
    
    for(int i = 0; i < numActores; ++i){
        std::cin >> sueldoActor;
        v_sueldo_actor[i] = sueldoActor;
    }
    
    
    std::vector<std::vector<int>> matriz(numPapeles, std::vector<int> (numActores));
 
    int puntuacion;
    
    for(int i = 0; i < numPapeles; ++i){
        for(int j = 0; j < numActores; ++j){
            std::cin >> puntuacion;
            matriz[i][j] = puntuacion;
        }
    }
    
    std::vector<bool> marcas_actor_ocupado(numPapeles, false); //False = el actor esta libre y true = el actor esta ocupado
    int indicePapeles = 0;
    int cont_puntuacion_total = 0;
    int cont_presupuesto = 0;
    int maxPuntuacionTotal = 0;
    int presupuestoSolucion = 0;
    std::vector<tSol> v_solucion(numPapeles);
    std::vector<tSol> v_papelesAsignados(numPapeles);
    
    std::vector<int> v_estimacion_mayor_puntuacion(numPapeles);
    int maximoPorFila = 0;
    
    for(int fila = 0; fila < numPapeles; ++fila){
        maximoPorFila = 0;
        for(int columna = 0; columna < numActores; ++columna){
            if(matriz[fila][columna] > maximoPorFila){
                maximoPorFila = matriz[fila][columna];
            }
        }
        v_estimacion_mayor_puntuacion[fila] = maximoPorFila;
    }
    
    
    for(int i = v_estimacion_mayor_puntuacion.size() - 2; i >= 0 ; --i){
        v_estimacion_mayor_puntuacion[i] += v_estimacion_mayor_puntuacion[i + 1];
    }
    
    resolver(matriz, v_sueldo_actor,  marcas_actor_ocupado, numPapeles,  indicePapeles, presupuestoTotal, cont_puntuacion_total, cont_presupuesto, puntuacionMin, maxPuntuacionTotal, presupuestoSolucion, v_solucion, v_papelesAsignados, v_estimacion_mayor_puntuacion);
    
    // escribir sol
    std::cout << maxPuntuacionTotal << ' ' << presupuestoSolucion << std::endl;
   
    if(maxPuntuacionTotal != 0){
        for(int i = 0; i < v_solucion.size(); ++i){
            std::cout << v_solucion[i].papelAsignado << ' ' << v_solucion[i].actorEscogido << std::endl;
        }
    }
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda31.txt");
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
