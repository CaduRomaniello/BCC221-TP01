#ifndef VEHICLE_H
#define VEHICLE_H

using namespace std;

#include <iostream>
#include <string>
#include <map>

#include "service_order.h"

class Vehicle{

  friend class Oficina;
  
  string tipo;
  string placa;
  float km;
  std::map<int, ServiceOrder> historic;
  string owner;

  public:

    Vehicle(string = "", string = "", float = 0.0, string = "");
    ~Vehicle();

    // setters de Vehicle
    void set_tipo(string tipo);
    void set_placa(string placa);
    void set_km(float km);
    void set_owner(string owner_cpf);

    // getters de Vehicle
    string get_tipo() const;
    string get_placa() const;
    float get_km() const;
    string get_owner() const;

    //push e pop do map historic
    void push_historic(int id, ServiceOrder service_order);
    void pop_historic(int id);

};

#endif