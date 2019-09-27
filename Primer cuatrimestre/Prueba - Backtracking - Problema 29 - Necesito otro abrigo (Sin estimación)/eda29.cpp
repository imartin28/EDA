// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 29 <==========================//

/*COSTE:
 
 
 */


bool esValida(std::vector<int>const& v_abrigos_utilizados_porDia, int indice_abrigo, int k_dia, std::vector<int>const& v_precipitaciones, std::vector<int>const& v_precipitacionMaxPorAbrigo, std::vector<int>& v_cont_abrigos, int abrigoMasUtilizado){
    
    if(k_dia > 0){
        if(v_abrigos_utilizados_porDia[k_dia] == v_abrigos_utilizados_porDia[k_dia - 1])    //No puede utilizar dos dias seguidos el mismo abrigo
            return false;
    }
    
    if(v_cont_abrigos[abrigoMasUtilizado] >  (2 + (k_dia/3))){        //El abrigo mas utilizado no puede superar en dos dias o mas a un tercio de los dias transcurridos
        return false;
    }
    
    
    if(v_precipitacionMaxPorAbrigo[v_abrigos_utilizados_porDia[k_dia]] < v_precipitaciones[k_dia] )      //si el abrigo no soporta la precipitacion de ese dia
        return false;
    
    
    return true;
}







// función que resuelve el problema
void resolver(std::vector<int>const& v_precipitaciones, std::vector<int>const& v_precipitacionMaxPorAbrigo,std::vector<int>& v_abrigos_utilizados_porDia, std::vector<int>& v_cont_abrigos, int numDias, int numAbrigos, int k_dia, int abrigoMasUtilizado, int& cont_combinaciones ) {
    
    for(int indice_abrigo = 0; indice_abrigo < numAbrigos; ++indice_abrigo){
        v_abrigos_utilizados_porDia[k_dia] = indice_abrigo;
        ++v_cont_abrigos[indice_abrigo];
        
        if(v_cont_abrigos[indice_abrigo] > v_cont_abrigos[abrigoMasUtilizado]){     //Miramos cual es el abrigo que mas se utiliza
            abrigoMasUtilizado = indice_abrigo;
        }
        
        if(esValida(v_abrigos_utilizados_porDia, indice_abrigo, k_dia,  v_precipitaciones, v_precipitacionMaxPorAbrigo, v_cont_abrigos, abrigoMasUtilizado )){
            
            if(k_dia == v_abrigos_utilizados_porDia.size() - 1){
                if(v_abrigos_utilizados_porDia[k_dia] != v_abrigos_utilizados_porDia[0])   //El primer y ultimo abrigo deben ser distintos
                    ++cont_combinaciones;
                
            }else{
                resolver(v_precipitaciones, v_precipitacionMaxPorAbrigo, v_abrigos_utilizados_porDia, v_cont_abrigos, numDias, numAbrigos, k_dia + 1, abrigoMasUtilizado, cont_combinaciones);
            }
            
        }
        
        
        --v_cont_abrigos[indice_abrigo];
        
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numDias, numAbrigosTotal;
    std::cin >> numDias >> numAbrigosTotal;
    
    if (numDias == 0 && numAbrigosTotal == 0)
        return false;
    
    
    std::vector<int> v_precipitaciones(numDias);
    int precipitacionPorDia;
    
    for(int i = 0; i < numDias; ++i){
        std::cin >> precipitacionPorDia;
        v_precipitaciones[i] = precipitacionPorDia;
    }
    
    
    std::vector<int> v_precipitacionMaxPorAbrigo(numAbrigosTotal);
    int precipitacionMaxSoportadaPorAbrigo;
    
    for(int i = 0; i < numAbrigosTotal; ++i){
        std::cin >> precipitacionMaxSoportadaPorAbrigo;
        v_precipitacionMaxPorAbrigo[i] = precipitacionMaxSoportadaPorAbrigo;
    }
    
    
    
    
    std::vector<int> v_abrigos_utilizados_porDia(numDias);
    std::vector<int> v_cont_abrigos(numAbrigosTotal);
    int k_abrigo = 0;
    int abrigoMasUtilizado = 0;
    int cont_combinaciones = 0;
    
    resolver(v_precipitaciones, v_precipitacionMaxPorAbrigo, v_abrigos_utilizados_porDia, v_cont_abrigos, numDias, numAbrigosTotal,  k_abrigo, abrigoMasUtilizado, cont_combinaciones );
    
    
    // escribir sol(
    if(cont_combinaciones == 0)
        std::cout << "Lo puedes comprar" << std::endl;
    else{
        std::cout << cont_combinaciones << std::endl;
        
    }
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda29.txt");
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
