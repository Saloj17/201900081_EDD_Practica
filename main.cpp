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

CircularDoble listaDisponible;
CircularDoble listaMantenimiento;

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
    

    

    return 0;
}
