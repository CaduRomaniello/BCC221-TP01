#ifndef VENDOR_H
#define VENDOR_H

using namespace std;
#include <iostream>
#include <string>
#include <limits.h>
#include <map>

#include "user.h"

class Vendor : public User{

  int id;

public:

    Vendor(string="", string="", string="", string="");
    ~Vendor();

    // Set and Get
    int get_id() const;
    int interface();

};

#endif