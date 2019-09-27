// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include "treemap_eda.h"


//==========================>   EJERCICIO 31 <==========================//

/*COSTE:

 
 El primer coste obtenido:
 O(nlog(n)) siendo n el numero de palabras.
 
 
 
 El segundo for:
 Coste = n*z siendo n el numero de palabras y z el numero de lineas perteneciendo al orden O(n)
 O(n) siendo n el numero de palabras.
 
 Por lo que el coste final es:
 max(nlog(n)), (n * z) perteneciendo esto al orden de O(n*log(n)) siendo n el numero de palabras
 */

void toLowerCase(std::string& palabra){
    std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numeroLineas;
    std::cin >> numeroLineas;
   
    if (numeroLineas == 0)
        return false;
    
    std::string frase, palabra;
    //Clave -> la palabra del texto y Valor --> numero o numeros de lineas donde aparece la palabra
    map<std::string, std::vector<int>> mapa;
    std::cin.ignore();
    for(int numLinea = 1; numLinea <= numeroLineas; ++numLinea){
        std::getline(std::cin, frase);
        std::stringstream ss(frase);
       
        while(ss >> palabra){
            // da igual que la palabra este en el diccionario o no, puesto que siempre va haber que insertarla
            if(palabra.size() > 2){
                toLowerCase(palabra);
                if(mapa[palabra].size() >= 1){
                    
                    if(mapa[palabra][mapa[palabra].size() - 1] != numLinea){
                        mapa[palabra].push_back(numLinea);
                    }
                }else{
                    mapa[palabra].push_back(numLinea);
                }
               
            }
            
        }
    }
    
    for(auto it = mapa.begin(); it != mapa.end(); ++it){
        std::cout << it -> clave << ' ';
        for(int i = 0; i < it->valor.size(); ++i){
            std::cout << (it->valor)[i] << ' ';
        }
        std::cout << std::endl;
    }
    
    
    
  
    
    std::cout << "----" << std::endl;
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda31.txt");
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
