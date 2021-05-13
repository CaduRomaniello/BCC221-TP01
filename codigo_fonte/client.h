#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

#include <iostream>
#include <string>
#include <map>

#include "vehicle.h"

class Client{
  friend class Oficina;

  string name;
  string cpf;
  map<string, Vehicle> vehicles;

  public:

    Client(string = "", string = "");
    ~Client();

    //setters dos atributos de Client
    void set_name(string name);
    void set_cpf(string cpf);

    // getters dos atibutos de Client
    string get_name() const;   
    string get_cpf() const;

    //push e pop do mapa de veiculos do Client
    void push_vehicles(string placa, Vehicle veiculo);
    void pop_vehicles(string placa);
};

#endif