#include <iostream>
using namespace std;

class Avion
{
private:
    string vuelo;
    string numero_de_registro;
    string modelo;
    string fabricante;
    int ano_fabricacion;
    int capacidad;
    int peso_max_despegue;
    string aerolinea;
    string estado;
public:
    Avion(/*string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado*/);
    string getVuelo(string vuelo);
    string setVuelo();
    string getRegistro(string Registro);
    string setRegistro();
    string getVuelo(string vuelo);
    string setVuelo();

    ~Avion();
};

Avion::Avion(/*string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad,int peso_max_despegue,string aerolinea,string estado*/)
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
}



Avion::~Avion()
{
}

