#include <iostream>
using namespace std;

class NodoPasajero
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

    NodoPasajero *anterior;
    NodoPasajero *siguiente;
public:
    NodoPasajero(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje);

    NodoPasajero *getSiguiente();
    void setSiguiente(NodoPasajero *siguiente);
    NodoPasajero *getAnterior();
    void setAnterior(NodoPasajero *anterior);

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

    ~NodoPasajero();
};

NodoPasajero::NodoPasajero(string nombre, string nacionalidad, string pasaporte, string vuelo, int asiento, string destino,string origen, int equipaje)
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

NodoPasajero* NodoPasajero::getSiguiente(){
    return this->siguiente;
}

NodoPasajero* NodoPasajero::getAnterior(){
    return this->anterior;
}

void NodoPasajero::setSiguiente(NodoPasajero *siguiente){
    this->siguiente = siguiente;
}

void NodoPasajero::setAnterior(NodoPasajero *anterior){
    this->anterior = anterior;
}

/*Getters*/
string NodoPasajero::getNombre(){
    return this->nombre;
}
string NodoPasajero::getNacionalidad(){
    return this->nacionalidad;
}
string NodoPasajero::getPasaporte(){
    return this->numero_de_pasaporte;
}
string NodoPasajero::getVuelo(){
    return this->vuelo;
}
int NodoPasajero::getAsiento(){
    return this->asiento;
}
string NodoPasajero::getDestino(){
    return this->destino;
}
string NodoPasajero::getOrigen(){
    return this->origen;
}
int NodoPasajero::getEquipaje(){
    return this->equipaje_facturado;
}


/*Setters*/
void NodoPasajero::setNombre(string nombre){
    this->nombre = nombre;
}
void NodoPasajero::setNacionalidad(string nacionalidad){
    this->nacionalidad= nacionalidad;
}
void NodoPasajero::setPasaporte(string pasaporte){
    this->numero_de_pasaporte = pasaporte;
}
void NodoPasajero::setVuelo(string vuelo){
    this->vuelo = vuelo;
}
void NodoPasajero::setAsiento(int asiento){
    this->asiento = asiento;
}
void NodoPasajero::setDestino(string destino){
    this->destino = destino;
}
void NodoPasajero::setOrigen(string origen){
    this->origen = origen;
}
void NodoPasajero::setEquipaje(int equipaje){
    this->equipaje_facturado = equipaje;
}

NodoPasajero::~NodoPasajero()
{
}

