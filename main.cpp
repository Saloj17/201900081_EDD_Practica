#include <iostream>
#include <fstream>
using namespace std;
#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <fstream>
#include "json.hpp" // Incluir la biblioteca json.hpp

#include "CircularDoble.h"
#include "ListaSimple.h"

using json = nlohmann::json;
using namespace std;

CircularDoble listaDisponible;
CircularDoble listaMantenimiento;

ListaSimple listaPasajeros;


void leerPasajeros() {
    // Abrir el archivo JSON
    ifstream archivo("C:\\Users\\SALOJ\\Desktop\\EDD\\201900081_EDD_Practica\\pasajeros.json");
   
    // Leer el archivo JSON
    json j;
    archivo >> j;


    // Procesar cada objeto en el archivo JSON
    for (const auto& item : j){
        string nombre=item["nombre"].get<std::string>();
        string nacionalidad=item["nacionalidad"].get<std::string>();
        string pasaporte=item["numero_de_pasaporte"].get<std::string>();
        string vuelo=item["vuelo"].get<std::string>();
        int asiento=item["asiento"].get<int>();
        string destino=item["destino"].get<std::string>();
        string origen=item["origen"].get<std::string>();
        int equipaje=item["equipaje_facturado"].get<int>();

        listaPasajeros.insertarFinal(nombre, nacionalidad, pasaporte, vuelo, asiento, destino, origen, equipaje);  
    }
}


void leerAviones() {
    // Abrir el archivo JSON
    ifstream archivo("C:\\Users\\SALOJ\\Desktop\\EDD\\201900081_EDD_Practica\\aviones.json");
   
    // Leer el archivo JSON
    json j;
    archivo >> j;

    // Procesar cada objeto en el archivo JSON
    for (const auto& item : j){
        string vuelo=item["vuelo"].get<std::string>();
        string numero_de_registro=item["numero_de_registro"].get<std::string>();
        string modelo=item["modelo"].get<std::string>();
        string fabricante=item["fabricante"].get<std::string>();
        int ano_fabricacion=item["ano_fabricacion"].get<int>();
        int capacidad=item["capacidad"].get<int>();
        int peso_max_despegue=item["peso_max_despegue"].get<int>();
        string aerolinea=item["aerolinea"].get<std::string>();
        string estado=item["estado"].get<std::string>();

        if (estado == "Disponible"){
            listaDisponible.insertarFinal(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado); 
        }
        else{
            if (estado == "Mantenimiento"){
                listaMantenimiento.insertarFinal(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado);
            }
            else{
                cout<<"El estado no esta especificado"<<endl;
            }
        }  
    }
}

int main() {
    leerAviones(); // Usar el nombre del archivo JSON
    
    cout<<"Lista de los disponibles"<<endl;
    listaDisponible.visualizarLista(); 
    cout<<endl;
    cout<<"================================"<<endl;
    cout<<"Lista de mantenimientos"<<endl;
    cout<<endl;
    listaMantenimiento.visualizarLista();

    leerPasajeros();
    cout<<"********************************"<<endl;
    cout<<"Lista de pasajeros"<<endl;
    cout<<endl;
    listaPasajeros.visualizarLista();

    cout<<"********************************"<<endl;
    cout<<"Busca pasajeros"<<endl;
    cout<<"********************************"<<endl;
    cout<<listaPasajeros.buscaPorPasaporte("P12345678")->getNombre()<<endl;
    cout<<listaPasajeros.buscaPorPasaporte("P12345678")->getPasaporte()<<endl;

    

    

    return 0;
}
