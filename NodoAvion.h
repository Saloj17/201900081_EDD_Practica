#include <iostream>
using namespace std;

class Nodo
{
private:
    /* data */
    string vuelo="";
    string numero_de_registro="";
    string modelo="";
    string fabricante="";
    int ano_fabricacion=0;
    int capacidad=0;
    int peso_max_despegue=0;
    string aerolinea="";
    string estado="";

    Nodo *anterior;
    Nodo *siguiente;
public:
    Nodo(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado);

    Nodo *getSiguiente();
    void setSiguiente(Nodo *siguiente);
    Nodo *getAnterior();
    void setAnterior(Nodo *anterior);

    string getVuelo();
    void setVuelo(string vuelo);
    string getRegistro();
    void setRegistro(string registro);
    string getModelo();
    void setModelo(string modelo);
    string getFabricante();
    void setFabricante(string fabricante);
    int getAnio();
    void setAnio(int anio);
    int getCapacidad();
    void setCapacidad(int capacidad);
    int getPeso();
    void setPeso(int peso);
    string getAreolinea();
    void setAerolinea(string aerolinea);
    string getEstado();
    void setEstado(string estado);

    ~Nodo();
};

Nodo::Nodo(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado)
{
    this->vuelo = vuelo;
    this->numero_de_registro=numero_de_registro;
    this->modelo=modelo;
    this->fabricante=fabricante;
    this->ano_fabricacion=ano_fabricacion;
    this->capacidad=capacidad;
    this->peso_max_despegue=peso_max_despegue;
    this->aerolinea=aerolinea;
    this->estado=estado;

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

/*Getters*/
string Nodo::getVuelo(){
    return this->vuelo;
}
string Nodo::getRegistro(){
    return this->numero_de_registro;
}
string Nodo::getModelo(){
    return this->modelo;
}
string Nodo::getFabricante(){
    return this->fabricante;
}
int Nodo::getAnio(){
    return this->ano_fabricacion;
}
int Nodo::getCapacidad(){
    return this->capacidad;
}
int Nodo::getPeso(){
    return this->peso_max_despegue;
}
string Nodo::getAreolinea(){
    return this->aerolinea;
}
string Nodo::getEstado(){
    return this->estado;
}

/*Setters*/
void Nodo::setVuelo(string vuelo){
    this->vuelo = vuelo;
}
void Nodo::setRegistro(string registro){
    this->numero_de_registro= registro;
}
void Nodo::setModelo(string modelo){
    this->modelo = modelo;
}
void Nodo::setFabricante(string fabricante){
    this->fabricante = fabricante;
}
void Nodo::setAnio(int anio){
    this->ano_fabricacion = anio;
}
void Nodo::setCapacidad(int capacidad){
    this->capacidad = capacidad;
}
void Nodo::setPeso(int peso){
    this->peso_max_despegue = peso;
}
void Nodo::setAerolinea(string aerolinea){
    this->aerolinea = aerolinea;
}
void Nodo::setEstado(string estado){
    this->estado = estado;
}

Nodo::~Nodo()
{
}

