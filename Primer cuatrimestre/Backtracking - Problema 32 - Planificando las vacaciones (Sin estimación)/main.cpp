// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#define INF 1000000000
//==========================>   EJERCICIO 32 <==========================//



bool esValida(std::vector<int>const& v_sol_recorrido_trayecto, std::vector<bool>& v_ciudades_visitadas, int k_dias, int cont_presupuesto, int presupuestoMin){
    
   
    
    if (k_dias > 0){
        if(v_ciudades_visitadas[v_sol_recorrido_trayecto[k_dias]])
            return false;
    }
    
    if(cont_presupuesto > presupuestoMin){
        return false;
    }
    
    return true;
    
}

// función que resuelve el problema
void resolver(std::vector<std::vector<int>>const& matriz, std::vector<int>const& v_precio_hotel_temp_alta, std::vector<int>const& v_precio_hotel_temp_baja, std::vector<int> v_sol_recorrido_trayecto,  std::vector<bool>& v_ciudades_visitadas, int diaComienzoTemp_baja, int presupuestoTotal, int k_dias, int numCiudades, int cont_presupuesto, int& presupuestoMin , std::vector<int>const& v_estimacion_dias) {
    
    
    
    for(int indice_ciudad = 1; indice_ciudad <= numCiudades; ++indice_ciudad){
        v_sol_recorrido_trayecto[k_dias] = indice_ciudad;
        
        if(k_dias >= diaComienzoTemp_baja){
           
                cont_presupuesto += matriz[v_sol_recorrido_trayecto[k_dias - 1]][indice_ciudad]  + v_precio_hotel_temp_baja[indice_ciudad];
            
        }else{
                cont_presupuesto += matriz[v_sol_recorrido_trayecto[k_dias - 1]][indice_ciudad]  + v_precio_hotel_temp_alta[indice_ciudad];
            
        }
        
        
        if(esValida(v_sol_recorrido_trayecto, v_ciudades_visitadas, k_dias, cont_presupuesto, presupuestoMin)){
            
            v_ciudades_visitadas[indice_ciudad] = true;
            
            if(k_dias == v_sol_recorrido_trayecto.size() - 1){   /*  LLegamos a la ultima ciudad, el ultimo dia  */
                
                cont_presupuesto += matriz[indice_ciudad][0];  /*  Sumamos al presupuesto que llevamos gastado, el billete de vuelta a casa    */
                
                
                if(cont_presupuesto <= presupuestoTotal){   /*  Si con el viaje de vuelta a casa superamos el presupuesto total que tenemos */
                    
                    if(cont_presupuesto < presupuestoMin){
                        presupuestoMin = cont_presupuesto;
                        
                        /* std::cout << presupuestoMin << std::endl;
                         for(int i = 0; i < v_sol_recorrido_trayecto.size(); ++i){
                         std::cout << v_sol_recorrido_trayecto[i] << ' ';
                         }
                         std::cout << std::endl;*/
                    }
                    
                }
                
              
                cont_presupuesto -= matriz[indice_ciudad][0];
                
            }else{
                int presupuesto_estimado = cont_presupuesto + v_estimacion_dias[k_dias];
                
                if(presupuesto_estimado < presupuestoMin){
                    resolver(matriz, v_precio_hotel_temp_alta, v_precio_hotel_temp_baja, v_sol_recorrido_trayecto,  v_ciudades_visitadas, diaComienzoTemp_baja, presupuestoTotal, k_dias + 1, numCiudades, cont_presupuesto, presupuestoMin, v_estimacion_dias);
                }
            }
            
            v_ciudades_visitadas[indice_ciudad] = false;
        
            
        }
        

        if(k_dias >= diaComienzoTemp_baja){
                cont_presupuesto -= matriz[v_sol_recorrido_trayecto[k_dias - 1]][indice_ciudad]  + v_precio_hotel_temp_baja[indice_ciudad];
            
            
        }else{
                cont_presupuesto -= matriz[v_sol_recorrido_trayecto[k_dias - 1]][indice_ciudad]  + v_precio_hotel_temp_alta[indice_ciudad];
            
    }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCiudades, diaComienzoTemp_baja, presupuestoTotal;
    std::cin >> numCiudades >> diaComienzoTemp_baja >> presupuestoTotal;
    
    if (numCiudades == 0 && diaComienzoTemp_baja == 0 && presupuestoTotal == 0)
        return false;
    
    std::vector<int> v_precio_hotel_temp_alta(numCiudades + 1);
    std::vector<int> v_precio_hotel_temp_baja(numCiudades + 1);
    int precioHotel;
    
    for(int i = 1; i < numCiudades + 1; ++i){
        std::cin >> precioHotel;
        v_precio_hotel_temp_alta[i] = precioHotel;
    }
    
    for(int i = 1; i < numCiudades + 1; ++i){
        std::cin >> precioHotel;
        v_precio_hotel_temp_baja[i] = precioHotel;
    }
    
    
    std::vector<std::vector<int>> matriz(numCiudades + 1, std::vector<int>(numCiudades + 1));
    int precioBillete;
    
    for(int fila = 0; fila < numCiudades + 1; ++fila){
        for(int columna = 0; columna < numCiudades + 1; ++columna){
            std::cin >> precioBillete;
            matriz[fila][columna] = precioBillete;
        }
    }
    
    std::vector<int> v_sol_recorrido_trayecto(numCiudades + 1);
    std::vector<bool> v_ciudades_visitadas(numCiudades + 1);
    int k_dias = 1;
    int cont_presupuesto = 0;
    int presupuesto_min = presupuestoTotal + 1;
    bool hayTrayecto = false;
    
    std::vector<int> v_estimacion_dias(numCiudades + 1);
    std::vector<int> v_aux (numCiudades + 1);
    
    for(int i = 1; i < numCiudades + 1; ++i){
        int valorMin = INF;
        for(int j = 0; j < numCiudades + 1; ++j){
            if(matriz[i][j] < valorMin && matriz[i][j] != 0){
                valorMin = matriz[i][j];
            }
        }
        v_estimacion_dias[i] = valorMin;
        
    }
    
    for(int i = 1; i < v_estimacion_dias.size(); ++i){
        
        v_estimacion_dias[i] += v_estimacion_dias[i - 1];
    }
    
    
    for(int i = v_estimacion_dias.size() - 1; i >= 0; --i){
        v_aux[(v_estimacion_dias.size() - 1)- i] = v_estimacion_dias[i];
    }
    
    v_estimacion_dias = v_aux;
    
    
    
    resolver(matriz, v_precio_hotel_temp_alta, v_precio_hotel_temp_baja, v_sol_recorrido_trayecto,  v_ciudades_visitadas, diaComienzoTemp_baja, presupuestoTotal, k_dias, numCiudades, cont_presupuesto, presupuesto_min, v_estimacion_dias);
    
    // escribir sol
    if(presupuesto_min > presupuestoTotal){
        std::cout << "No puedes ir" << std::endl;
    }else{
        std::cout << presupuesto_min << std::endl;
    }
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda32.txt");
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
