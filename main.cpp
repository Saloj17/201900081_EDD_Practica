#include <iostream>
#include <fstream>
using namespace std;
#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <fstream>
#include "json.hpp" // Incluir la biblioteca json.hpp

#include "CircularDoble.h"

using json = nlohmann::json;
using namespace std;

CircularDoble miLista;

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


        miLista.insertarInicio(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado);   
    }
}

int main() {
    leerAviones(); // Usar el nombre del archivo JSON
    
    miLista.visualizarLista(); 
    

    

    return 0;
}



// struct Flight {
//     string vuelo;
//     string numero_de_registro;
//     string modelo;
//     string fabricante;
//     int ano_fabricacion;
//     int capacidad;
//     int peso_max_despegue;
//     string aerolinea;
//     string estado;
// };

// vector<Flight> parseJSON(string filename) {
//     vector<Flight> flights;

//     FILE* fp = fopen(filename.c_str(), "r");
//     if (fp == nullptr) {
//         cerr << "Error al abrir el archivo JSON." << endl;
//         return flights;
//     }

//     char readBuffer[65536];
//     FileReadStream is(fp, readBuffer, sizeof(readBuffer));

//     Document document;
//     document.ParseStream(is);

//     if (!document.IsArray()) {
//         cerr << "El archivo JSON no contiene un arreglo de vuelos." << endl;
//         fclose(fp);
//         return flights;
//     }

//     for (SizeType i = 0; i < document.Size(); i++) {
//         const Value& flightObject = document[i];
//         Flight flight;

//         flight.vuelo = flightObject["vuelo"].GetString();
//         flight.numero_de_registro = flightObject["numero_de_registro"].GetString();
//         flight.modelo = flightObject["modelo"].GetString();
//         flight.fabricante = flightObject["fabricante"].GetString();
//         flight.ano_fabricacion = flightObject["ano_fabricacion"].GetInt();
//         flight.capacidad = flightObject["capacidad"].GetInt();
//         flight.peso_max_despegue = flightObject["peso_max_despegue"].GetInt();
//         flight.aerolinea = flightObject["aerolinea"].GetString();
//         flight.estado = flightObject["estado"].GetString();

//         flights.push_back(flight);
//     }

//     fclose(fp);
//     return flights;
// }

// int main() {
//     string filename = "flights.json";
//     vector<Flight> flights = parseJSON(filename);

//     // Mostrar los vuelos almacenados en la lista
//     for (const auto& flight : flights) {
//         cout << "Vuelo: " << flight.vuelo << endl;
//         cout << "Número de registro: " << flight.numero_de_registro << endl;
//         cout << "Modelo: " << flight.modelo << endl;
//         cout << "Fabricante: " << flight.fabricante << endl;
//         cout << "Año de fabricación: " << flight.ano_fabricacion << endl;
//         cout << "Capacidad: " << flight.capacidad << endl;
//         cout << "Peso máximo de despegue: " << flight.peso_max_despegue << endl;
//         cout << "Aerolínea: " << flight.aerolinea << endl;
//         cout << "Estado: " << flight.estado << endl;
//         cout << endl;
//     }

//     return 0;
// }