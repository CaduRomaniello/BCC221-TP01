#ifndef SERVICE_ORDER_H
#define SERVICE_ORDER_H

using namespace std;

#include <iostream>
#include <string>
#include <map>

#include "automobile_part.h"
#include "service.h"

class ServiceOrder{

//   friend class Admin;
//   friend class Mechanic;

  int id;
  string tipo;
  string motivo;
  string placa;
  float km;
  bool concluded;
  bool approved;
  map<string, Service> services;
  map<string, AutoPart> automobile_parts;
  float cost;
  string owner_cpf;

public:

  static int count;

  ServiceOrder(string = "", string = "", string = "", float = 0.0, bool = false, bool = false, float = 0.0, string = "");
  ~ServiceOrder();

  //setters dos atributos de SeviceOrde
  void set_id(int id);
  void set_tipo(string tipo);
  void set_motivo(string motivo);
  void set_placa(string placa);
  void set_km(float km);
  void set_concluded(bool condition);
  void set_approved(bool condition);
  void set_cost(float cost);
  void set_owner_cpf(string cpf);

  //gettes dos atributos de ServiceOrder
  int get_id() const;
  string get_tipo() const;
  string get_motivo() const;
  string get_placa() const;
  float get_km() const;
  bool get_concluded() const;
  bool get_approved() const;
  float get_cost() const;
  string get_owner_cpf() const;

  //push para os dois mapas de ServiceOrder
  void push_service(string service_name, Service service);
  void push_automobile_part(string part_name, AutoPart part);

  //pop para os dois mapas de ServiceOrder
  void pop_service(string service_name);
  void pop_automobile_part(string part_name);

  //mostra os atributos de ServiceOrder
  void display();
};

#endif