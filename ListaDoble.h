#include <iostream>
using namespace std;
#include "NodoEquipaje.h"

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

ListaDoble::~ListaDoble()
{
}
