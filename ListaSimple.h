#include <iostream>
using namespace std;
#include "NodoPasajero.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

class ListaSimple
{
private:
    NodoPasajero *primero, *ultimo;
public:
    ListaSimple(/* args */);
    bool estaVacia();
    void insertarInicio(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje);
    void insertarFinal(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    NodoPasajero* buscaPorPasaporte(string pasaporte);
    NodoPasajero* visualizarPrimero();
    void visualizarListaDot();
    ~ListaSimple();
};

ListaSimple::ListaSimple(/* args */)
{
    primero = ultimo = nullptr;
}

bool ListaSimple::estaVacia(){
    return (primero == nullptr) && (ultimo == nullptr);
}

NodoPasajero* ListaSimple::buscaPorPasaporte(string pasaporte) {
    NodoPasajero *actual = primero;
    while (actual != nullptr) {
        if (actual->getPasaporte() == pasaporte) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

void ListaSimple::insertarInicio(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje){
    NodoPasajero *nuevo = new NodoPasajero(nombre, nacionalidad,pasaporte, vuelo, asiento, destino, origen, equipaje);
    if (ListaSimple::estaVacia())
    {
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero);
        primero = nuevo;
    }
}

void ListaSimple::insertarFinal(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje){
    NodoPasajero *nuevo = new NodoPasajero(nombre, nacionalidad,pasaporte, vuelo, asiento, destino, origen, equipaje);
    if (ListaSimple::estaVacia()){
        primero = ultimo = nuevo;
    }
    else{
        ultimo->setSiguiente(nuevo);
        ultimo = nuevo;
    }
}

void ListaSimple::eliminarInicio(){
    if (ListaSimple::estaVacia()){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        if(primero == ultimo){
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            NodoPasajero *segundo = primero->getSiguiente();
            delete primero;
            primero = segundo;
        }
    }
}

NodoPasajero* ListaSimple::visualizarPrimero() {
    if (estaVacia()) {
        cout << "La lista está vacía" << endl;
        return nullptr; // Devuelve nullptr si la lista está vacía
    } else {
        NodoPasajero *primerNodo = primero;
        return primerNodo; // Devuelve el primer nodo
    }
}

void ListaSimple::eliminarFinal(){
    if (ListaSimple::estaVacia()){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        NodoPasajero *temporal = primero;
        if (primero == ultimo){
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            while(temporal != nullptr){
                if (temporal->getSiguiente()==ultimo){
                    delete ultimo;
                    temporal->setSiguiente(nullptr);
                    ultimo = temporal;
                }
                temporal = temporal->getSiguiente();
            }
        }
    }
}

void ListaSimple::visualizarLista(){
    if (ListaSimple::estaVacia()){
        cout<<"La lista está vacía\n"<<endl;
    }
    else{
        int nodoPasajeroDato;
        NodoPasajero *actual = primero;
        while(actual != nullptr){

            std::cout << "Nombre: " << actual->getNombre() <<endl;
            std::cout << "Nacionalidad: " << actual->getNacionalidad() <<endl;
            std::cout << "Pasaporte: " << actual->getPasaporte() <<endl;
            // std::cout << "Vuelo: " << actual->getVuelo() <<endl;
            // cout << "Asiento: " << actual->getAsiento() <<endl;
            // std::cout << "Destino: " << actual->getDestino() <<endl;
            // std::cout << "Origen: " << actual->getOrigen() <<endl;
            // cout << "Equipaje: " << actual->getEquipaje() <<endl;
            cout<<endl;
            actual = actual->getSiguiente();
        }
    }
}

void ListaSimple::visualizarListaDot() {
    std::ofstream archivo("lista_pasajeros.dot");

    archivo << "digraph ListaPasajeros {" << std::endl;
    archivo << "    rankdir=LR;" << std::endl; // Opcional: Organiza los nodos de izquierda a derecha

    if (estaVacia()) {
        archivo << "    vacia [label=\"La lista está vacía\", shape=box];" << std::endl;
    } else {
        NodoPasajero* actual = primero;
        while (actual != nullptr) {
            archivo << "    \"" << actual->getNombre() << "\" [label=\"" << actual->getNombre() << "\\n" << actual->getNacionalidad() << "\\n" << actual->getPasaporte() << "\"];" << std::endl;
            if (actual->getSiguiente() != nullptr) {
                archivo << "    \"" << actual->getNombre() << "\" -> \"" << actual->getSiguiente()->getNombre() << "\";" << std::endl;
            }
            actual = actual->getSiguiente();
        }
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo DOT generado: lista_pasajeros.dot" << std::endl;

    // Generar el archivo PNG utilizando Graphviz
    std::string comando_dot = "dot -Tpng lista_pasajeros.dot -o lista_pasajeros.png";
    int resultado = std::system(comando_dot.c_str());
    if (resultado == 0) {
        std::cout << "Archivo PNG generado: lista_pasajeros.png" << std::endl;
    } else {
        std::cerr << "Error al generar el archivo PNG" << std::endl;
    }
}

ListaSimple::~ListaSimple()
{
}
