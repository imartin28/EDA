// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
//==========================>   EJERCICIO 24 <==========================//



bool esValida(std::vector<std::string>const& vector_solucion, int cont_azules, int cont_rojas, int cont_verdes, int k, int azul, int rojo, int verde, int alturaTorre){

    if(vector_solucion[0] != "rojo"){   //En la primera posición no este una pieza roja
        return false;
    }
    
    if(cont_verdes > cont_azules){  // El numero de piezas verdes sea mayor que el numero de piezas azules
        return false;
    }
    
    if(vector_solucion[k] == "verde" && vector_solucion[k - 1] == "verde"){     //Dos piezas verdes consecutivas
        return false;
    }
    
    if(cont_verdes > verde || cont_rojas > rojo || cont_azules > azul)  //El numero de piezas no debe superar a las
        return false;                                                   // piezas iniciales
    
    if(alturaTorre - 1 == k){
        if(cont_rojas <= cont_verdes + cont_azules){     //Si se ha llegado al final el numero total de piezas rojas
            return false;                           //no debe superar a la suma total de piezas verdes mas azules
        }
    }
        
    return true;
}


/*Si se ha llegado al final de la torre se termina*/

bool esSolucion(int alturaTorre, int k){
    if(alturaTorre - 1 == k){
        return true;
    }else return false;
}

// función que resuelve el problema
void resolver(int alturaTorre, int azules, int rojas, int verdes, std::vector<std::string> vector_solucion, int k, int cont_azules, int cont_rojas, int cont_verdes, bool& seConstruye) {
    
    for(auto i = 0; i < 3 ; ++i){   /*Se realiza un bucle hasta el numero de posibilidades que existen*/
        if(i == 0){
            vector_solucion[k] = "azul";
            ++cont_azules;
       
        }else if(i == 1){
            vector_solucion[k] = "rojo";
            ++cont_rojas;
            
        }else{
            vector_solucion[k] = "verde";
            ++cont_verdes;
        }
        
        
        if(esValida(vector_solucion, cont_azules, cont_rojas, cont_verdes, k, azules, rojas, verdes, alturaTorre)){
            if(esSolucion(alturaTorre, k)){
                seConstruye = true;
                for(int i = 0; i < alturaTorre; ++i){
                    std::cout << vector_solucion[i] << ' ';
                }
                std::cout << std::endl;
            
                
            }else{
                resolver(alturaTorre, azules, rojas, verdes, vector_solucion, k + 1, cont_azules, cont_rojas, cont_verdes, seConstruye);
            }
        }
        
        
        if(i == 0){
            --cont_azules;
        }else if(i == 1){
            --cont_rojas;
        }else{
            --cont_verdes;
        }
        
        
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int alturaTorre, piezasTotalAzules, piezasTotalRojas, piezasTotalVerdes;
    std::cin >> alturaTorre >> piezasTotalAzules >> piezasTotalRojas >> piezasTotalVerdes;
    
    if (alturaTorre == 0)
        return false;
    
    std::vector<std::string> vector_soluciones(alturaTorre);
    int cont_aules = 0;
    int cont_rojas = 0;
    int cont_verdes = 0;
    bool seConstruye = false;
    resolver(alturaTorre, piezasTotalAzules, piezasTotalRojas, piezasTotalVerdes, vector_soluciones, 0, cont_aules, cont_rojas, cont_verdes, seConstruye);
    
    
    // escribir sol
    if(!seConstruye){
        std::cout << "SIN SOLUCION" << std::endl;
    }
     std::cout << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda24.txt");
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
