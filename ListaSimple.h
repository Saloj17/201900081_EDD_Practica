#include <iostream>
using namespace std;
#include "NodoPasajero.h"

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
ListaSimple::~ListaSimple()
{
}
