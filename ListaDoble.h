#include <iostream>
using namespace std;
#include "NodoEquipaje.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

class ListaDoble
{
private:
    /* data */
    NodoEquipaje *primero;
    NodoEquipaje *ultimo;
public:
    ListaDoble(/* args */);
    bool estaVacia();
    void insertarInicio(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje);
    void insertarFinal(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    void visualizarListaDot();
    void visualizarPasajeros();
    ~ListaDoble();
};

ListaDoble::ListaDoble(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

bool ListaDoble::estaVacia(){
    return (primero == nullptr) && (ultimo == nullptr);
}


void ListaDoble::insertarInicio(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje){
    NodoEquipaje *nuevo = new NodoEquipaje(nombre, nacionalidad,pasaporte, vuelo, asiento, destino, origen, equipaje);
    if (ListaDoble::estaVacia())
    {
        primero = ultimo = nuevo;
    }
    else
    {
        primero->setAnterior(nuevo);
        nuevo->setSiguiente(primero);
        primero = nuevo;
    }
}

void ListaDoble::insertarFinal(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje){
    NodoEquipaje *nuevo = new NodoEquipaje(nombre, nacionalidad,pasaporte, vuelo, asiento, destino, origen, equipaje);
    if (ListaDoble::estaVacia()){
        primero = ultimo = nuevo;
    }
    else{
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
}

void ListaDoble::eliminarInicio(){
    if (ListaDoble::estaVacia()){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        if(primero == ultimo){
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            NodoEquipaje *segundo = primero->getSiguiente();
            segundo->setAnterior(nullptr);
            delete primero;
            primero = segundo;
        }
    }
}

void ListaDoble::eliminarFinal(){
    if (ListaDoble::estaVacia()){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        if (primero == ultimo){
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            NodoEquipaje* antepenultimo = ultimo->getAnterior();
            delete ultimo;
            antepenultimo->setSiguiente(nullptr);
            ultimo = antepenultimo;
        }
    }
}

void ListaDoble::visualizarLista(){
    if (ListaDoble::estaVacia()){
        cout<<"La lista está vacía\n"<<endl;
    }
    else{
        NodoEquipaje *actual = primero;
        while(actual != nullptr){

            std::cout << "Nombre: " << actual->getNombre() <<endl;
            std::cout << "Nacionalidad: " << actual->getNacionalidad() <<endl;
            std::cout << "Pasaporte: " << actual->getPasaporte() <<endl;
            std::cout << "Vuelo: " << actual->getVuelo() <<endl;
            cout << "Asiento: " << actual->getAsiento() <<endl;
            std::cout << "Destino: " << actual->getDestino() <<endl;
            std::cout << "Origen: " << actual->getOrigen() <<endl;
            cout << "Equipaje: " << actual->getEquipaje() <<endl;
            cout<<endl;
            actual = actual->getSiguiente();
        }
    }
}

void ListaDoble::visualizarListaDot() {
    std::ofstream archivo("lista_equipaje.dot");

    archivo << "digraph ListaEquipaje {" << std::endl;
    archivo << "    rankdir=LR;" << std::endl; // Opcional: Organiza los nodos de izquierda a derecha

    if (estaVacia()) {
        archivo << "    vacia [label=\"La lista está vacía\", shape=box];" << std::endl;
    } else {
        NodoEquipaje* actual = primero;
        while(actual != nullptr) {
            archivo << "    \"" << actual->getNombre() << "\" [label=\"" << actual->getNombre() << "\\n" << actual->getNacionalidad() << "\\n" << actual->getPasaporte() << "\\n" << actual->getVuelo() << "\\n" << actual->getAsiento() << "\\n" << actual->getDestino() << "\\n" << actual->getOrigen() << "\\n" << actual->getEquipaje() << "\"];" << std::endl;
            if (actual->getSiguiente() != nullptr) {
                archivo << "    \"" << actual->getNombre() << "\" -> \"" << actual->getSiguiente()->getNombre() << "\";" << std::endl;
                archivo << "    \"" << actual->getSiguiente()->getNombre() << "\" -> \"" << actual->getNombre() << "\";" << std::endl; // Conexión en ambos sentidos para lista doblemente enlazada
            }
            actual = actual->getSiguiente();
        }
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo DOT generado: lista_equipaje.dot" << std::endl;

    // Generar el archivo PNG utilizando Graphviz
    std::string comando_dot = "dot -Tpng lista_equipaje.dot -o lista_equipaje.png";
    int resultado = std::system(comando_dot.c_str());
    if (resultado == 0) {
        std::cout << "Archivo PNG generado: lista_equipaje.png" << std::endl;
    } else {
        std::cerr << "Error al generar el archivo PNG" << std::endl;
    }
}

void ListaDoble::visualizarPasajeros() {
    std::ofstream archivo("listaDoblePasajeros.dot");

    archivo << "digraph listaDoblePasajeros {" << std::endl;
    archivo << "    rankdir=LR;" << std::endl; // Opcional: Organiza los nodos de izquierda a derecha

    if (estaVacia()) {
        archivo << "    vacia [label=\"La lista está vacía\", shape=box];" << std::endl;
    } else {
        NodoEquipaje* actual = primero;
        while(actual != nullptr) {
            archivo << "    \"" << actual->getNombre() << "\" [label=\"" << actual->getNombre() << "\\n" << actual->getNacionalidad() << "\\n" << actual->getPasaporte() << "\\n" << actual->getVuelo() << "\\n" << actual->getAsiento() << "\\n" << actual->getDestino() << "\\n" << actual->getOrigen() << "\\n" << actual->getEquipaje() << "\"];" << std::endl;
            if (actual->getSiguiente() != nullptr) {
                archivo << "    \"" << actual->getNombre() << "\" -> \"" << actual->getSiguiente()->getNombre() << "\";" << std::endl;
                archivo << "    \"" << actual->getSiguiente()->getNombre() << "\" -> \"" << actual->getNombre() << "\";" << std::endl; // Conexión en ambos sentidos para lista doblemente enlazada
            }
            actual = actual->getSiguiente();
        }
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo DOT generado: listaDoblePasajeros.dot" << std::endl;

    // Generar el archivo PNG utilizando Graphviz
    std::string comando_dot = "dot -Tpng listaDoblePasajeros.dot -o listaDoblePasajeros.png";
    int resultado = std::system(comando_dot.c_str());
    if (resultado == 0) {
        std::cout << "Archivo PNG generado: listaDoblePasajeros.png" << std::endl;
    } else {
        std::cerr << "Error al generar el archivo PNG" << std::endl;
    }
}

ListaDoble::~ListaDoble()
{
}
