// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#define INF 1000000000

//==========================>   EJERCICIO 28 (CON ESTIMACION)<==========================//

bool esSolucion(int columnas, int indiceProducto){
    if(columnas - 1 == indiceProducto){
        return true;
    }else return false;
}

// función que resuelve el problema
void resolver(std::vector<std::vector<int>>const& matriz, std::vector<int>& vector_marcas_supermecados, int indiceProducto, int precioTotal, int& precioMinTotal, std::vector<int>const& v_precio_min_producto_supermercado ) {
    
    for(int supermercado = 0; supermercado < matriz.size(); ++supermercado ){   //recorro por filas
        
        if(vector_marcas_supermecados[supermercado] < 3){   //esValida()
            ++vector_marcas_supermecados[supermercado];
            precioTotal += matriz[supermercado][indiceProducto];
            
            if(esSolucion(matriz[0].size(), indiceProducto)){
                if(precioTotal < precioMinTotal){
                    precioMinTotal = precioTotal;
                }
                
            }else{
                
                /* PODA */
                int precioMinimoEstimado = precioTotal + v_precio_min_producto_supermercado[indiceProducto + 1];
                if(precioMinimoEstimado < precioMinTotal)
                    resolver(matriz, vector_marcas_supermecados, indiceProducto + 1, precioTotal, precioMinTotal, v_precio_min_producto_supermercado);
            }
            
            --vector_marcas_supermecados[supermercado];
            precioTotal -= matriz[supermercado][indiceProducto];
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numSupermercadosFilas, numProductosColumnas;
    std::cin >> numSupermercadosFilas >> numProductosColumnas;
    
    int precio;
    
    std::vector<std::vector<int>> matriz(numSupermercadosFilas, std::vector<int> (numProductosColumnas, 0));
    
    for(int i = 0; i < matriz.size(); ++i){
        for(int j = 0; j < matriz[0].size(); ++j){
            std::cin >> precio;
            matriz[i][j] = precio;
        }
    }
    
    std::vector<int> vector_marcas_supermecados(numSupermercadosFilas);
    int indiceProducto = 0; // k
    int precioTotal = 0, precioMinimoTotal = INF;
    
    /*ESTIMACION: Compruebo por columnas en que supermercado esta el producto mas barato y lo añado a un vector de precio min*/
    
    std::vector<int> v_precio_min_producto_supermercado(numProductosColumnas);
    int minPrecio;
    
    for(int j = 0; j < matriz[0].size(); ++j){
        minPrecio = matriz[0][j] ;
        
        for(int i = 0; i < matriz.size(); ++i){
            if(matriz[i][j] < minPrecio){
                minPrecio = matriz[i][j];
            }
        }
        v_precio_min_producto_supermercado[j] = minPrecio;
    }
    
    
    for(int i = v_precio_min_producto_supermercado.size() - 2; i >= 0; --i){
        v_precio_min_producto_supermercado[i] += v_precio_min_producto_supermercado[i + 1];
    }
    
    resolver(matriz, vector_marcas_supermecados, indiceProducto, precioTotal, precioMinimoTotal, v_precio_min_producto_supermercado);
    // escribir sol
    std::cout << precioMinimoTotal << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda28.txt");
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
