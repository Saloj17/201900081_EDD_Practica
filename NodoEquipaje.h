#include <iostream>
using namespace std;

class NodoEquipaje
{
private:
    /* data */
    string nombre = "";
    string nacionalidad="";
    string numero_de_pasaporte="";
    string vuelo="";
    int asiento=0;
    string destino="";
    string origen="";
    int equipaje_facturado=0;

    NodoEquipaje *anterior;
    NodoEquipaje *siguiente;
public:
    NodoEquipaje(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje);

    NodoEquipaje *getSiguiente();
    void setSiguiente(NodoEquipaje *siguiente);
    NodoEquipaje *getAnterior();
    void setAnterior(NodoEquipaje *anterior);

    string getNombre();
    void setNombre(string nombre);
    string getNacionalidad();
    void setNacionalidad(string nacionalidad);
    string getPasaporte();
    void setPasaporte(string pasaporte);
    string getVuelo();
    void setVuelo(string vuelo);
    int getAsiento();
    void setAsiento(int asiento);
    string getDestino();
    void setDestino(string destino);
    string getOrigen();
    void setOrigen(string origen);
    int getEquipaje();
    void setEquipaje(int equipaje);

    ~NodoEquipaje();
};

NodoEquipaje::NodoEquipaje(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje)
{
    this->nombre = nombre;
    this->nacionalidad =  nacionalidad;
    this->numero_de_pasaporte=pasaporte;
    this->vuelo=vuelo;
    this->asiento= asiento;
    this->destino= destino;
    this->origen= origen;
    this->equipaje_facturado= equipaje;

    this->anterior = nullptr;
    this->siguiente = nullptr;
}

NodoEquipaje* NodoEquipaje::getSiguiente(){
    return this->siguiente;
}

NodoEquipaje* NodoEquipaje::getAnterior(){
    return this->anterior;
}

void NodoEquipaje::setSiguiente(NodoEquipaje *siguiente){
    this->siguiente = siguiente;
}

void NodoEquipaje::setAnterior(NodoEquipaje *anterior){
    this->anterior = anterior;
}

/*Getters*/
string NodoEquipaje::getNombre(){
    return this->nombre;
}
string NodoEquipaje::getNacionalidad(){
    return this->nacionalidad;
}
string NodoEquipaje::getPasaporte(){
    return this->numero_de_pasaporte;
}
string NodoEquipaje::getVuelo(){
    return this->vuelo;
}
int NodoEquipaje::getAsiento(){
    return this->asiento;
}
string NodoEquipaje::getDestino(){
    return this->destino;
}
string NodoEquipaje::getOrigen(){
    return this->origen;
}
int NodoEquipaje::getEquipaje(){
    return this->equipaje_facturado;
}


/*Setters*/
void NodoEquipaje::setNombre(string nombre){
    this->nombre = nombre;
}
void NodoEquipaje::setNacionalidad(string nacionalidad){
    this->nacionalidad= nacionalidad;
}
void NodoEquipaje::setPasaporte(string pasaporte){
    this->numero_de_pasaporte = pasaporte;
}
void NodoEquipaje::setVuelo(string vuelo){
    this->vuelo = vuelo;
}
void NodoEquipaje::setAsiento(int asiento){
    this->asiento = asiento;
}
void NodoEquipaje::setDestino(string destino){
    this->destino = destino;
}
void NodoEquipaje::setOrigen(string origen){
    this->origen = origen;
}
void NodoEquipaje::setEquipaje(int equipaje){
    this->equipaje_facturado = equipaje;
}

NodoEquipaje::~NodoEquipaje()
{
}

