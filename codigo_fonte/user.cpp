#include "user.h"

User::User(string name, string cpf, string email, string password) : name(name), cpf(cpf), email(email), psswd(password){}
User::~User(){}

void User::set_name(string name){
    this->name = name;
}
void User::set_cpf(string cpf){
    this->cpf = cpf;
}
void User::set_email(string email){
    this->email = email;
}
void User::set_password(string password){
    this->psswd = password;
}

string User::get_name() const { return name; }
string User::get_cpf() const { return cpf; }
string User::get_email() const { return email; }
string User::get_password() const { return psswd; }

std::ostream& operator<<(std::ostream& out, User const& user){
    out << "printar user";
    return out;
}

string display_pipe(int end, int begin){
    string ending_pipe = " ";
    for (int i = begin; i <= end; i++) ending_pipe.append(" ");

    return ending_pipe.append("|");
}
void User::display(){
    int name_length = get_name().length();
    int cpf_length = get_cpf().length();
    int email_length = get_email().length();

    int length = 0;

    if (name_length > length) length = name_length;
    if (cpf_length > length) length = cpf_length;
    if (email_length > length) length = email_length;


    cout << " ";
    for(int i = 0; i < length + 10; i++) cout << "_";
    cout << " \n";

    cout << "|        " << display_pipe(length, 0) << endl;
    cout << "| Dados  " << display_pipe(length, 0) << endl;
    cout << "|        " << display_pipe(length, 0) << endl;
    cout << "| Nome : " << get_name() << display_pipe(length, name_length) << endl;
    cout << "| CPF  : " << get_cpf() << display_pipe(length, cpf_length) << endl;
    cout << "| Email: " << get_email() << display_pipe(length, email_length) << endl;

    cout << "|";
    for (int i = 0; i < length + 10; i++) cout << "_";
    cout << "|\n";
}
