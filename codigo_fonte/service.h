#ifndef SERVICE_H
#define SERVICE_H

using namespace std;

#include <iostream>
#include <string>
#include <map>

class Service{
    
  string service_name;
  float service_price;

public:

  Service(string="", float=0.0);
  ~Service();

  // Setters and Getters
  void set_service_name(string);
  string get_service_name() const;

  void set_service_price(float);
  float get_service_price() const;

};

#endif