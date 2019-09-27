// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "list_eda.h"

//==========================>   EJERCICIO 16 <==========================//

class persona{
private:
    int _edad;
    std::string _nombre;
    
public:
    persona(){}
    
    persona(int edad, std::string nombre) : _edad(edad), _nombre(nombre) {}
    
    
    int get_edad() const{
        return _edad;
    }
    
    std::string get_nombre() const{
        return _nombre;
    }
    
    void read(std::istream & in = std::cin){
        
        in >> _edad;
        in.ignore();
        getline(in, _nombre);
        
        
    }
    
    void print(std::ostream & out = std::cout) const{
        out << _nombre;
    }
    
   
    
};

inline std::istream & operator>>(std::istream & in, persona & p){
    
    p.read(in);
    return in;
}

inline std::ostream & operator<<(std::ostream & out, persona const& p){
    
    p.print(out);
    return out;
}


/*******************************************************/
/*******************************************************/
/*******************************************************/
/*******************************************************/


/* Clase que hereda de Lista y que recorre toda la lista de personas
 Al llamar al metodo remove_if se le pasa un objeto de tipo filtro_edad por lo que la clase predicado es del tipo
 filtro_edad y pred es filtro.
 Por cada elemento de la lista, si lo cumple, lo borra.
 
 */
template <class T>
class listaEliminar : public list<T> {
    
public:
    
    template<class Predicate>
    void remove_if(Predicate pred){
        
        for(auto it = this->begin(); it != this->end(); ++it){
            if(pred(*it)){
                this->erase(it);
            }
        }
        
    }
    
};


/*******************************************************/
/*******************************************************/
/*******************************************************/
/*******************************************************/


/* Clase que tiene el objeto funcion para comprobar que cumple la condición (predicado) */
class filtro_edad{
private:
    int _edad_min, _edad_max;
    
public:
    
    filtro_edad(int minimo, int maximo) : _edad_min(minimo), _edad_max(maximo) {}
    
    bool operator()(persona const& p)const{
        return p.get_edad() < _edad_min || p.get_edad() > _edad_max;
    }
    
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    int numPersonas, edad_min, edad_max;
    std::cin >> numPersonas >> edad_min >> edad_max;
    
    if (numPersonas == 0 && edad_min == 0 && edad_max == 0)
        return false;
    
    persona p;
    listaEliminar<persona> lista_personas;
    
    
    for(int i = 0; i < numPersonas; ++i){
        std::cin>> p;
        lista_personas.push_back(p);
    }
    
    filtro_edad filtro(edad_min, edad_max);
    
    lista_personas.remove_if(filtro);
    
    // escribir sol
    for(auto it = lista_personas.begin(); it != lista_personas.end(); ++it){
        std::cout << *it << std::endl;
    }
    std::cout << "---" << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA_2/txt/eda16.txt");
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
