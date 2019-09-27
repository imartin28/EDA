// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 33 <==========================//



// función que resuelve el problema
void resolver(std::vector<int>const& v_costePorObjeto, std::vector<int>const& v_superficie, std::vector<bool>& v_solucion, int k_objeto, int numObjQuePuedeComprar, int presupuesto, int& cont_presupuesto, int& superficie_max, int& cont_superficie_actual) {
    
   
    
    /*  Si cogemos el objeto */
    
    v_solucion[k_objeto] = true;
    cont_presupuesto += v_costePorObjeto[k_objeto];
    cont_superficie_actual += v_superficie[k_objeto];
    
    if(cont_presupuesto <= presupuesto){
        if(k_objeto == v_solucion.size() - 1){
            
            if(cont_superficie_actual > superficie_max){
                superficie_max = cont_superficie_actual;
            }
            
        }else{
            resolver(v_costePorObjeto, v_superficie, v_solucion, k_objeto + 1, numObjQuePuedeComprar, presupuesto, cont_presupuesto, superficie_max, cont_superficie_actual);
        }
    }
    
    cont_superficie_actual -= v_superficie[k_objeto];
    cont_presupuesto -= v_costePorObjeto[k_objeto];
    v_solucion[k_objeto] = false;
   
    
    /* Si no cogemos el objeto */
    
    
    if(k_objeto ==  v_solucion.size() - 1){
        
        if(cont_superficie_actual > superficie_max){
            superficie_max = cont_superficie_actual;
        }
        
    }else{
        resolver(v_costePorObjeto, v_superficie, v_solucion, k_objeto + 1, numObjQuePuedeComprar, presupuesto, cont_presupuesto, superficie_max, cont_superficie_actual);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numObjQuePuedeComprar, presupuesto;
    std::cin >> numObjQuePuedeComprar >> presupuesto;
    
    if (! std::cin)
        return false;
    
    
    std::vector<int> v_costePorObjeto(numObjQuePuedeComprar);
    int coste = 0;
    
    for(int i = 0; i < numObjQuePuedeComprar; ++i){
        std::cin >> coste;
        v_costePorObjeto[i] = coste;
    }
    
    std::vector<int> v_superficie(numObjQuePuedeComprar);
    int superficie = 0;
    
    for(int i = 0; i < numObjQuePuedeComprar; ++i){
        std::cin >> superficie;
        v_superficie[i] = superficie;
    }
    
    std::vector<bool> v_solucion(numObjQuePuedeComprar, false);
    
    int k_objeto = 0;
    int cont_presupuesto = 0, superficie_max = 0, cont_superficie_actual = 0;
    
    resolver(v_costePorObjeto, v_superficie, v_solucion, k_objeto, numObjQuePuedeComprar, presupuesto, cont_presupuesto, superficie_max, cont_superficie_actual );
    
    std::cout << superficie_max << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda33.txt");
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
