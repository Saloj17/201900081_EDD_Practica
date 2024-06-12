#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <fstream>
#include "json.hpp" // Incluir la biblioteca json.hpp

#include "CircularDoble.h"
#include "ListaSimple.h"
#include "ListaDoble.h"

using json = nlohmann::json;
using namespace std;

CircularDoble listaDisponible;
CircularDoble listaMantenimiento;

ListaSimple listaPasajeros;
ListaDoble listaEquipaje;

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
        std::cout << "Procesando ingreso de equipajes..." << std::endl;
        // Agregar aquí el código para procesar el ingreso de equipajes
    } else if (palabra == "MantenimientoAviones") {
        std::cout << "Procesando mantenimiento de aviones..." << std::endl;
        // Agregar aquí el código para procesar el mantenimiento de aviones
    } else {
        std::cerr << "Palabra desconocida: " << palabra << std::endl;

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
    leerArchivoTxt("movimientos.txt");
    cout<<endl;
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
    cout<<endl;
    listaEquipaje.insertarInicio("nombre", "nacionalidad","pasaporte", "vuelo", 01, "destino", "origen", 0);
    listaEquipaje.visualizarLista();


    cout<<listaMantenimiento.buscarPorRegistro("A5432")->getModelo()<<endl;
    cout<<endl;
    listaMantenimiento.eliminarPorRegistro("A54321");
    listaMantenimiento.visualizarLista();

    return 0;
}
