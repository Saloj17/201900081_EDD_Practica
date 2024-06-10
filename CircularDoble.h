#include <iostream>
using namespace std;
#include "NodoAvion.h"

class CircularDoble
{
private:
    /* data */
    Nodo *primero;
    Nodo *ultimo;
public:
    CircularDoble(/* args */);
    bool estaVacia();
    void insertarInicio(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado);
    void insertarFinal(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado);
    void eliminarInicio();
    void eliminarFinal();
    void visualizarLista();
    void ordenar();
    ~CircularDoble();
};

CircularDoble::CircularDoble(/* args */)
{
    primero = nullptr;
    ultimo = nullptr;
}

bool CircularDoble::estaVacia(){
    return (primero == nullptr) && (ultimo == nullptr);
}

void CircularDoble::insertarInicio(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado){
    Nodo *nuevo = new Nodo(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado);
    if (CircularDoble::estaVacia())
    {
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        primero = ultimo = nuevo;
    }
    else
    {
        nuevo->setSiguiente(primero);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        primero->setAnterior(nuevo);
        primero = nuevo;
    }
}

void CircularDoble::insertarFinal(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado){
    Nodo *nuevo = new Nodo(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado);
    if (CircularDoble::estaVacia()){
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        primero = ultimo = nuevo;
    }
    else{
        nuevo->setSiguiente(primero);
        nuevo->setAnterior(ultimo);
        ultimo->setSiguiente(nuevo);
        primero->setAnterior(nuevo);
        ultimo = nuevo;
    }
}

void CircularDoble::eliminarInicio(){
    if (CircularDoble::estaVacia()){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        if(primero == ultimo){
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            Nodo *segundo = primero->getSiguiente();
            ultimo->setSiguiente(segundo);
            segundo->setAnterior(ultimo);
            delete primero;
            primero = segundo;
        }
    }
}

void CircularDoble::eliminarFinal(){
    if (CircularDoble::estaVacia()){
        cout<<"La lista está vacía"<<endl;
    }
    else{
        if (primero == ultimo){
            delete primero;
            primero = ultimo = nullptr;
        }
        else{
            Nodo *penultimo = ultimo->getAnterior();
            penultimo->setSiguiente(primero);
            primero->setAnterior(penultimo);
            delete ultimo;
            ultimo = penultimo;
        }
    }
}

void CircularDoble::visualizarLista(){
    if (CircularDoble::estaVacia()){
        cout<<"La lista esta vacia\n"<<endl;
    }
    else{
        Nodo *actual = primero;
        do{
            std::cout << "Vuelo: " << actual->getVuelo() <<endl;
            std::cout << "Registro: " << actual->getRegistro() <<endl;
            std::cout << "Modelo: " << actual->getModelo() <<endl;
            std::cout << "Fabricante: " << actual->getFabricante() <<endl;
            cout << "Anioo: " << actual->getAnio() <<endl;
            cout << "Capacidad: " << actual->getCapacidad() <<endl;
            cout << "Peso: " << actual->getPeso() <<endl;
            std::cout << "Aerolinea: " << actual->getAreolinea() <<endl;
            std::cout << "Estado: " << actual->getEstado() <<endl;
            cout<<endl;
            actual = actual->getSiguiente();
        }while (actual != primero);
    }
}

CircularDoble::~CircularDoble()
{
}
