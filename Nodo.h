#include <iostream>
using namespace std;

class Nodo
{
private:
    /* data */
    Nodo *dato;
    Nodo *anterior;
    Nodo *siguiente;
public:
    Nodo(Nodo *dato);
    Nodo *getSiguiente();
    void setSiguiente(Nodo *siguiente);
    Nodo *getAnterior();
    void setAnterior(Nodo *anterior);
    int getDato();
    void setDato(int dato);
    ~Nodo();
};

Nodo::Nodo(Nodo *dato)
{
    this->dato = dato;
    this->anterior = nullptr;
    this->siguiente = nullptr;
}

Nodo* Nodo::getSiguiente(){
    return this->siguiente;
}

Nodo* Nodo::getAnterior(){
    return this->anterior;
}

void Nodo::setSiguiente(Nodo *siguiente){
    this->siguiente = siguiente;
}

void Nodo::setAnterior(Nodo *anterior){
    this->anterior = anterior;
}

int Nodo::getDato(){
    return this->dato;
}

void Nodo::setDato(int dato){
    this->dato = dato;
}

Nodo::~Nodo()
{
}

