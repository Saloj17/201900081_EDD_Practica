#include <iostream>
using namespace std;
#include "NodoAvion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

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
    Nodo* buscarPorRegistro(string registro);
    void eliminarPorRegistro(string registro);
    void visualizarMantenimiento();
    void visualizarDisponibles();
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

void CircularDoble::eliminarPorRegistro(string registro) {
    if (estaVacia()) {
        cout << "La lista está vacía. No se puede eliminar ningún nodo." << endl;
        return;
    }

    Nodo* nodoAEliminar = buscarPorRegistro(registro);

    if (nodoAEliminar == nullptr) {
        cout << "No se encontró ningún nodo con el registro " << registro << " en la lista." << endl;
        return;
    }

    if (primero == ultimo) {
        delete nodoAEliminar;
        primero = ultimo = nullptr;
        return;
    }

    // Caso general: hay más de un nodo en la lista
    Nodo* anterior = nodoAEliminar->getAnterior();
    Nodo* siguiente = nodoAEliminar->getSiguiente();

    anterior->setSiguiente(siguiente);
    siguiente->setAnterior(anterior);

    if (nodoAEliminar == primero) {
        primero = siguiente;
    }
    if (nodoAEliminar == ultimo) {
        ultimo = anterior;
    }

    delete nodoAEliminar;
}


Nodo* CircularDoble::buscarPorRegistro(string registro) {
    if (estaVacia()) {
        return nullptr; 
    }

    Nodo* actual = primero;
    do {
        if (actual->getRegistro() == registro) {
            return actual;
        }
        actual = actual->getSiguiente();
    } while (actual != primero); 

    return nullptr;
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

void CircularDoble::visualizarDisponibles() {
    std::ofstream archivo("disponibles.dot");

    archivo << "digraph AvionDisponible {" << std::endl;
    archivo << "    rankdir=LR;" << std::endl; // Opcional: Organiza los nodos de izquierda a derecha

    if (estaVacia()) {
        archivo << "    vacia [label=\"La lista está vacía\", shape=box];" << std::endl;
    } else {
        Nodo* actual = primero;
        do {
            archivo << "    \"" << actual->getVuelo() << "\" [label=\"Vuelo: " << actual->getVuelo() << "\\nRegistro: " << actual->getRegistro() << "\\nModelo: " << actual->getModelo() << "\\nFabricante: " << actual->getFabricante() << "\\nAño: " << actual->getAnio() << "\\nCapacidad: " << actual->getCapacidad() << "\\nPeso: " << actual->getPeso() << "\\nAerolínea: " << actual->getAreolinea() << "\\nEstado: " << actual->getEstado() << "\"];" << std::endl;
            archivo << "    \"" << actual->getVuelo() << "\" -> \"" << actual->getSiguiente()->getVuelo() << "\";" << std::endl;
            archivo << "    \"" << actual->getVuelo() << "\" -> \"" << actual->getAnterior()->getVuelo() << "\";" << std::endl;
            actual = actual->getSiguiente();
        } while (actual != primero); // Corregido: Utilizamos el bucle do-while para asegurarnos de que se recorra toda la lista
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo DOT generado: disponibles.dot" << std::endl;

    // Generar el archivo PNG utilizando Graphviz
    std::string comando_dot = "dot -Tpng disponibles.dot -o disponibles.png";
    int resultado = std::system(comando_dot.c_str());
    if (resultado == 0) {
        std::cout << "Archivo PNG generado: disponibles.png" << std::endl;
    } else {
        std::cerr << "Error al generar el archivo PNG" << std::endl;
    }
}

void CircularDoble::visualizarMantenimiento() {
    std::ofstream archivo("mantenimiento.dot");

    archivo << "digraph AvionesMantenimiento{" << std::endl;
    archivo << "    rankdir=LR;" << std::endl; // Opcional: Organiza los nodos de izquierda a derecha

    if (estaVacia()) {
        archivo << "    vacia [label=\"La lista está vacía\", shape=box];" << std::endl;
    } else {
        Nodo* actual = primero;
        do {
            archivo << "    \"" << actual->getVuelo() << "\" [label=\"Vuelo: " << actual->getVuelo() << "\\nRegistro: " << actual->getRegistro() << "\\nModelo: " << actual->getModelo() << "\\nFabricante: " << actual->getFabricante() << "\\nAño: " << actual->getAnio() << "\\nCapacidad: " << actual->getCapacidad() << "\\nPeso: " << actual->getPeso() << "\\nAerolínea: " << actual->getAreolinea() << "\\nEstado: " << actual->getEstado() << "\"];" << std::endl;
            archivo << "    \"" << actual->getVuelo() << "\" -> \"" << actual->getSiguiente()->getVuelo() << "\";" << std::endl;
            archivo << "    \"" << actual->getVuelo() << "\" -> \"" << actual->getAnterior()->getVuelo() << "\";" << std::endl;
            actual = actual->getSiguiente();
        } while (actual != primero);
    }

    archivo << "}" << std::endl;
    archivo.close();

    std::cout << "Archivo DOT generado: mantenimiento.dot" << std::endl;

    // Generar el archivo PNG utilizando Graphviz
    std::string comando_dot = "dot -Tpng mantenimiento.dot -o mantenimiento.png";
    int resultado = std::system(comando_dot.c_str());
    if (resultado == 0) {
        std::cout << "Archivo PNG generado: mantenimiento.png" << std::endl;
    } else {
        std::cerr << "Error al generar el archivo PNG" << std::endl;
    }
}


CircularDoble::~CircularDoble()
{
}
