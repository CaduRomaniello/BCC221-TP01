#ifndef USER_H
#define USER_H

using namespace std;

#include <iostream>
#include <string>
#include <map>

class User{

    string name;
    string cpf;
    string email;
    string psswd;

public:

    User(string="", string="", string="", string="");
    ~User();

    //sette e getter para name
    void set_name(string);
    string get_name() const;

    //setter e getter para cpf
    void set_cpf(string);
    string get_cpf() const;

    //sette e getter para email
    void set_email(string);
    string get_email() const;

    //sette e getter para password
    void set_password(string);
    string get_password() const;

    //sobrecarga do operrador <<
    friend std::ostream& operator<<(std::ostream&, const User&);

    //mostra os dados do usuario
    void display();
};

#endif
