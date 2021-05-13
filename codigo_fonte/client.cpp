#include "client.h"

Client::Client(string name, string cpf) : name(name), cpf(cpf){}
Client::~Client(){}

void Client::set_name(string name){
    this->name = name;
}
void Client::set_cpf(string cpf){
    this->cpf = cpf;
}

string Client::get_name() const {return name;}
string Client::get_cpf() const {return cpf;}

void Client::push_vehicles(string placa, Vehicle veiculo){
    bool criou =  vehicles.insert(make_pair(placa, veiculo)).second;
    if (criou == false){
        cout << "O usuário já tem um carro cadastrado com a placa: " << placa << "\n";
    }
}
void Client::pop_vehicles(string placa){
    int removidos = vehicles.erase(placa);
    if (removidos == 0){
        cout << "O usuário naõ possui um carros cadastrado com a placa: " << placa << "\n";
    }
}