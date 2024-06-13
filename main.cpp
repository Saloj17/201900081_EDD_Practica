#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "json.hpp" // Incluir la biblioteca json.hpp

#include "CircularDoble.h"
#include "ListaSimple.h"
#include "ListaDoble.h"

using json = nlohmann::json;
using namespace std;

CircularDoble listaDisponible;
CircularDoble listaMantenimiento;

ListaSimple listaPasajeros;
ListaSimple listaConsulta;
ListaDoble listaEquipaje;
ListaDoble listaPasajerosOrdenados;

void menu(){
    cout<<"==========Menu=========="<<endl;
    cout<<"1. Carga de aviones"<<endl;
    cout<<"2. Carga de pasajeros"<<endl;
    cout<<"3. Carga de movimientos"<<endl;
    cout<<"4. Consulta pasajero"<<endl;
    cout<<"5. Visualizar reportes"<<endl;
    cout<<"6. Salir"<<endl;
}

void reportes(){
    cout<<"==========Reportes=========="<<endl;
    cout<<"1. Lista de aviones disponibles"<<endl;
    cout<<"2. Lista de aviones en mantenimiento"<<endl;
    cout<<"3. Cola de registro"<<endl;
    cout<<"4. Pila de equipaje"<<endl;
    cout<<"5. Lista de pasajeros"<<endl;
    cout<<"6. Regresar al menu"<<endl;
}

void reportesDespligue(){
    reportes();
    int valor;
    std::cout << "Ingrese el numero de la accion que desea realizar: "<<endl;
    cin >> valor;
    while (1<= valor && valor <=6){        
        if (valor == 1){
            cout<<"Aviones disponibles: "<<endl;
            cout<<endl;
            listaDisponible.visualizarLista();
        }else if (valor == 2){
            cout<<"Aviones en mantenimiento: "<<endl;
            cout<<endl;
            listaMantenimiento.visualizarLista();
        }else if (valor == 3){
            cout<<"Cola de registro: "<<endl;
            cout<<endl;
            listaPasajeros.visualizarLista();
            listaPasajeros.visualizarListaDot();
        }else if (valor == 4){
            cout<<"Lista de equipaje: "<<endl;
            cout<<endl;
            listaEquipaje.visualizarLista();
        }else if (valor == 5){
            cout<<"Lista de pasajeros (ordenados): "<<endl;
            cout<<endl;

            listaPasajerosOrdenados.visualizarLista();
        }else{
            cout << "Ha salido de reportes"<<endl;
            break;
        }   
        reportes();    
        std::cout << "Ingrese el numero de la accion que desea realizar: "<<endl;
        cin >> valor; 
    }
}

void procesarLinea(const std::string& linea) {
    std::istringstream ss(linea);
    std::string palabra;

    // Leer la primera palabra de la línea
    ss >> palabra;

    // Eliminar el punto y coma al final de la primera palabra si está presente
    if (!palabra.empty() && palabra.back() == ';') {
        palabra.pop_back();
    }

    // Procesar la línea según la primera palabra
    if (palabra == "IngresoEquipajes") {        
        if(listaPasajeros.visualizarPrimero()->getEquipaje()!=0){

            listaEquipaje.insertarFinal(listaPasajeros.visualizarPrimero()->getNombre(),listaPasajeros.visualizarPrimero()->getNacionalidad(),listaPasajeros.visualizarPrimero()->getPasaporte(),listaPasajeros.visualizarPrimero()->getVuelo(),listaPasajeros.visualizarPrimero()->getAsiento(),listaPasajeros.visualizarPrimero()->getDestino(),listaPasajeros.visualizarPrimero()->getOrigen(),listaPasajeros.visualizarPrimero()->getEquipaje());

            listaPasajeros.eliminarInicio();

        }else{
            listaPasajeros.eliminarInicio();
        }
    } else {
        std::istringstream ss(palabra);

        std::string palabra;
        std::string mantenimiento;
        std::string condicion;
        std::string registro;
        int i = 0;
        while (std::getline(ss, palabra, ',')) {
            // std::cout << palabra << std::endl;
            if (i == 0) {
                mantenimiento = palabra;
            }else if (i == 1){
                condicion = palabra;
            }else{
                registro = palabra;
            }
            i++;
        }

        if(condicion == "Ingreso"){
            listaMantenimiento.insertarFinal(listaDisponible.buscarPorRegistro(registro)->getVuelo(), registro, listaDisponible.buscarPorRegistro(registro)->getModelo(), listaDisponible.buscarPorRegistro(registro)->getFabricante(), listaDisponible.buscarPorRegistro(registro)->getAnio(), listaDisponible.buscarPorRegistro(registro)->getCapacidad(), listaDisponible.buscarPorRegistro(registro)->getPeso(), listaDisponible.buscarPorRegistro(registro)->getAreolinea(), "Mantenimiento");
            listaDisponible.eliminarPorRegistro(registro);
        }else if (condicion == "Salida"){
            listaDisponible.insertarFinal(listaMantenimiento.buscarPorRegistro(registro)->getVuelo(), registro, listaMantenimiento.buscarPorRegistro(registro)->getModelo(), listaMantenimiento.buscarPorRegistro(registro)->getFabricante(), listaMantenimiento.buscarPorRegistro(registro)->getAnio(), listaMantenimiento.buscarPorRegistro(registro)->getCapacidad(), listaMantenimiento.buscarPorRegistro(registro)->getPeso(), listaMantenimiento.buscarPorRegistro(registro)->getAreolinea(), "Disponible");
            listaMantenimiento.eliminarPorRegistro(registro);
        }else{
            cout<<endl;
        }
    }
}

void leerArchivoTxt(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        procesarLinea(linea);
    }

    archivo.close();
}

void leerPasajeros(const std::string& nombreArchivo) {
    // Abrir el archivo JSON
    ifstream archivo(nombreArchivo);
   
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

        listaConsulta.insertarFinal(nombre, nacionalidad, pasaporte, vuelo, asiento, destino, origen, equipaje);

        listaPasajerosOrdenados.insertarFinal(nombre, nacionalidad, pasaporte, vuelo, asiento, destino, origen, equipaje);
    }
}


void leerAviones(const std::string& nombreArchivo) {
    // Abrir el archivo JSON
    ifstream archivo(nombreArchivo);
   
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
    menu();
    int opcion;
    std::cout << "Ingrese el numero de la accion que desea realizar: "<<endl;
    cin >> opcion;
    while (1<= opcion && opcion <=6){        
        if (opcion == 1){
            string nombre;
            std::cout << "Ingrese el nombre del archivo de aviones"<<endl;
            std::cin >> nombre;
            leerAviones(nombre);
        }else if (opcion == 2){
            string nombre;
            std::cout << "Ingrese el nombre del archivo de pasajeros"<<endl;
            std::cin >> nombre;
            leerPasajeros(nombre);
        }else if (opcion == 3){
            string nombre;
            std::cout << "Ingrese el nombre del archivo de movimientos"<<endl;
            std::cin >> nombre;
            leerArchivoTxt(nombre);
        }else if (opcion == 4){
            string pasaporte;
            std::cout << "Ingrese el pasaporte del pasajero a consultar: "<<endl;
            std::cin >> pasaporte;
            cout<<endl;
            cout<<"Nombre: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getNombre()<<endl;
            cout<<"Nacionalidad: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getNacionalidad()<<endl;
            cout<<"Pasaporte: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getPasaporte()<<endl;
            cout<<"Vuelo: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getVuelo()<<endl;
            cout<<"Asiento: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getAsiento()<<endl;
            cout<<"Destino: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getDestino()<<endl;
            cout<<"Origen: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getOrigen()<<endl;
            cout<<"Equipaje_Facturado: "<<listaPasajeros.buscaPorPasaporte(pasaporte)->getEquipaje()<<endl;
            cout<<endl;

        }else if (opcion == 5){
            reportesDespligue();
        }else{
            cout << "Ha salido del sistema"<<endl;
            break;
        }   
        menu();    
        std::cout << "Ingrese el numero de la accion que desea realizar: "<<endl;
        cin >> opcion; 
    }
    

    return 0;
}
