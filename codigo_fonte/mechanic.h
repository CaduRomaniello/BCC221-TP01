#ifndef MECHANIC_H
#define MECHANIC_H

using namespace std;
#include <iostream>
#include <string>
#include <limits.h>
#include <map>

#include "user.h"

class Mechanic : public User{

  int id;

public:

    Mechanic(string="", string="", string="", string="");
    ~Mechanic();

    //getter e setter
    int get_id() const;
    int interface();

};

#endif