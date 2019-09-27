// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 41 <==========================

/*COSTE:
 
    O(n) siendo n el numero de elementos del vector
 
 */


enum piedrasPreciosas {diamante, rubi, esmeralda, zafiro, jade};

std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
    char num;
    entrada >> num;
    switch (num) {
        case 'd': p = diamante; break;
        case 'r': p = rubi; break;
        case 'e': p = esmeralda; break;
        case 'z': p = zafiro; break;
        case 'j': p = jade; break;
    }
    return entrada;
}

// función que resuelve el problema
int resolver(std::vector<piedrasPreciosas>const& v_piedras, int& tamSecuencia, piedrasPreciosas &tipo1, int& numTipo1, piedrasPreciosas& tipo2, int& numTipo2) {
    
    
    int cont_tipo1 = 0, cont_tipo2 = 0, cont_secuencias = 0;
    
    for(int i = 0; i < tamSecuencia; ++i){  /* Primero miramos si en el tamaño maximo de la secuencia existen letras que queremos en nuestra secuencia*/
        if(v_piedras[i] == tipo1){
            ++cont_tipo1;
        }else if(v_piedras[i] == tipo2){
            ++cont_tipo2;
        }
    }
    
    
    if(cont_tipo1 >= numTipo1 && cont_tipo2 >= numTipo2)            //Si tenemos al menos el valor de veces que debe repetirse la letra, entonces aumentamos hemos encontrado una secuencia
        ++cont_secuencias;
    
    
    for(int i = tamSecuencia; i < v_piedras.size(); ++i){
    
        if(v_piedras[i - tamSecuencia] == tipo1)    /*Debemos quitar la primera posición y añadir una nueva, por lo que si en la primera posicion esta una letra ya contada, la descontamos*/
            --cont_tipo1;
        if(v_piedras[i - tamSecuencia] == tipo2)
            --cont_tipo2;
        
        if(v_piedras[i] == tipo1)           /*Si en el nuevo indice existen una letra que necesitamos para la secuencia, aumentamos el contador de cada tipo*/
            ++cont_tipo1;
        else if(v_piedras[i] == tipo2)
            ++cont_tipo2;
        
        
        if(cont_tipo1 >= numTipo1 && cont_tipo2 >= numTipo2)            //Si tenemos al menos el valor de veces que debe repetirse la letra, entonces aumentamos hemos encontrado una secuencia
            ++cont_secuencias;
    }
    
    return cont_secuencias;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    int numpiedras, tamanioSecuencia;
    int numtipo1,numtipo2;
    piedrasPreciosas tipo1, tipo2;
    std::cin >> numpiedras >> tamanioSecuencia >> tipo1 >> numtipo1 >> tipo2 >> numtipo2;
    
    std::vector<piedrasPreciosas> v_piedras(numpiedras);
    
    for (piedrasPreciosas& i : v_piedras)
        std::cin >> i;
    
    int sol = resolver(v_piedras, tamanioSecuencia, tipo1, numtipo1, tipo2, numtipo2);
    // escribir sol
    std::cout << sol << std::endl;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda41.txt");
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
