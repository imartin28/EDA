// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
//==========================>   EJERCICIO 25 <==========================//

bool esValida(std::vector<int>const& vectorConsumoBombilla, int bombilla,std::vector<int>& vectorSolucion, int consumoMaxTira, int posicionLongitudTira, int contadorTotalColores, std::vector<int>& vectorContadorColores, int totalConsumo){
   
    if(posicionLongitudTira > 0){
        if(vectorSolucion[posicionLongitudTira] == vectorSolucion[posicionLongitudTira - 1] && vectorSolucion[posicionLongitudTira] == vectorSolucion[posicionLongitudTira - 2])
            return false;
    }
    
    if(vectorContadorColores[bombilla] - (contadorTotalColores - vectorContadorColores[bombilla]) > 1){
        return false;
    }
   
   if(totalConsumo > consumoMaxTira)
       return false;
    
        return true;
}


bool esSolucion(int longitudTira, int posicionLongitudTira){
    if(posicionLongitudTira == longitudTira - 1){
        return true;
    }
    else return false;
}

// función que resuelve el problema
void resolver(std::vector<int>const& vectorConsumoBombilla,std::vector<int>& vectorSolucion,std::vector<int>& vectorContadorColores,  int longitudTira, int posicionLongitudTira, int consumoMaxTira, int contadorTotalColores, int &combinacionPosible, int totalConsumo){
    for(int i= 0; i < vectorConsumoBombilla.size(); ++i){
        vectorSolucion[posicionLongitudTira] = i;
        vectorContadorColores[i]++;
        contadorTotalColores ++;
        totalConsumo += vectorConsumoBombilla[i];
        
        if(esValida(vectorConsumoBombilla, i, vectorSolucion, consumoMaxTira, posicionLongitudTira, contadorTotalColores, vectorContadorColores, totalConsumo)){
            
            if(esSolucion(longitudTira, posicionLongitudTira)){
               
                combinacionPosible ++;
           
            }
            
            else{
                resolver(vectorConsumoBombilla, vectorSolucion,vectorContadorColores, longitudTira, posicionLongitudTira + 1, consumoMaxTira, contadorTotalColores, combinacionPosible, totalConsumo);
            }
        }
        
        vectorContadorColores[i] --;
        contadorTotalColores --;
        totalConsumo -= vectorConsumoBombilla[i];
        
    
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int longitudTira, numColoresTotal, consumoMaxTira;
    std::cin >> longitudTira >> numColoresTotal >> consumoMaxTira;
    if (! std::cin)
        return false;
    
    std::vector<int> vectorConsumoBombilla(numColoresTotal);
    std::vector<int> vectorSolucion(longitudTira);
    std::vector<int> vectorContadorColores(numColoresTotal, 0);
    int combinacionPosible = 0;
    
    for(int i = 0; i < numColoresTotal; ++i){
        std::cin >> vectorConsumoBombilla[i];
    }
   
    
    
    resolver(vectorConsumoBombilla, vectorSolucion, vectorContadorColores, longitudTira, 0, consumoMaxTira, 0, combinacionPosible, 0 );
    
    std::cout << combinacionPosible << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
   std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda25.txt");
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
