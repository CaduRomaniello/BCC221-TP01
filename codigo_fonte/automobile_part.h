#ifndef AUTOMOBILE_PART_H
#define AUTOMOBILE_PART_H

using namespace std;

#include <iostream>
#include <string>
#include <map>

class AutoPart{

  string part_name;
  int quantity; // por veículo
  float part_price;

public:

  AutoPart(string="", int=0, float=0.0);
  ~AutoPart();

  //setter e getter part_name
  void set_part_name(string);
  string get_part_name() const;

  //setter e getter part_price
  void set_part_price(float);
  float get_part_price() const;

  //setter e getter quantity
  void set_quantity(int quantity);
  int get_quantity() const;

};

#endif