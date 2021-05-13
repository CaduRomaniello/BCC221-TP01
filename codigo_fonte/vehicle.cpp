#include "vehicle.h"

Vehicle::Vehicle(string tipo, string placa, float km, string cpf) : tipo(tipo), placa(placa), km(km), owner(cpf){}
Vehicle::~Vehicle(){}

void Vehicle::set_tipo(string tipo){
    this->tipo = tipo;
}
void Vehicle::set_placa(string placa){
    this->placa = placa;
}
void Vehicle::set_km(float km){
    this->km = km;
}
void Vehicle::set_owner(string owner_cpf){
    this->owner = owner_cpf;
}

string Vehicle::get_tipo() const {return tipo;}   
string Vehicle::get_placa() const {return placa;}
float Vehicle::get_km() const {return km;}
string Vehicle::get_owner() const {return owner;}

void Vehicle::push_historic(int id, ServiceOrder service_order){
    bool criou =  historic.insert(make_pair(id, service_order)).second;
    if (criou == false){
        cout << "O carro já possui uma ordem de serviço com o ID: " << id << "\n";
    }
}
void Vehicle::pop_historic(int id){
    int removidos = historic.erase(id);
    if (removidos == 0){
        cout << "O carro não possui uma ordem de serviço com o id: " << id << "\n";
    }
}