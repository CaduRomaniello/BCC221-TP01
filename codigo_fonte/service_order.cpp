#include "service_order.h"

ServiceOrder::ServiceOrder(string tipo, string motivo, string placa, float km, bool concluded, bool approved, float cost, string cpf) : id(0), tipo(tipo), motivo(motivo), placa(placa), km(km), concluded(concluded), approved(approved), cost(cost), owner_cpf(cpf){}
ServiceOrder::~ServiceOrder(){}

void ServiceOrder::set_id(int id){
    this->id = id;
}
void ServiceOrder::set_tipo(string tipo){
    this->tipo = tipo;
}
void ServiceOrder::set_motivo(string motivo){
    this->motivo = motivo;
}
void ServiceOrder::set_placa(string placa){
    this->placa = placa;
}
void ServiceOrder::set_km(float km){
    this->km = km;
}
void ServiceOrder::set_concluded(bool condition){
    this->concluded = condition;
}
void ServiceOrder::set_approved(bool condition){
    this->approved = condition;
}
void ServiceOrder::set_cost(float cost){
    this->cost = cost;
}
void ServiceOrder::set_owner_cpf(string cpf){
    this->owner_cpf = cpf;
}

// Getters

int ServiceOrder::get_id() const {return id;}
string ServiceOrder::get_tipo() const {return tipo;}
string ServiceOrder::get_motivo() const {return motivo;}
string ServiceOrder::get_placa() const {return placa;}
float ServiceOrder::get_km() const {return km;}
bool ServiceOrder::get_concluded() const {return concluded;}
bool ServiceOrder::get_approved() const {return approved;}
float ServiceOrder::get_cost() const {return cost;}
string ServiceOrder::get_owner_cpf() const {return owner_cpf;}

// Push on MAP

void ServiceOrder::push_service(string service_name, Service service){
    bool criou = services.insert(make_pair(service_name, service)).second;
    if (!criou){
        cout << "O serviço: " << service_name << " já foi registrado na ordem de serviço.\n";
    }
}
void ServiceOrder::push_automobile_part(string part_name, AutoPart part)
{
    bool criou = automobile_parts.insert(make_pair(part_name, part)).second;
    if (!criou){
        int qntd = automobile_parts[part_name].get_quantity();
        automobile_parts[part_name].set_quantity(qntd + part.get_quantity());
    }
}

// Pop from MAP

void ServiceOrder::pop_service(string service_name){
    int removeu = services.erase(service_name);
    if (removeu == 0){
        cout << "Não existe o serviço: " << service_name << " na ordem de serviço.\n";
    }
}
void ServiceOrder::pop_automobile_part(string part_name)
{
    int removeu = automobile_parts.erase(part_name);
    if (removeu == 0){
        cout << "Não existe a peça: " << part_name << " na ordem de serviço.\n";
    }
}

void ServiceOrder::display(){

    cout << "--------- Ordem Selecionada ---------\n";
    cout << "ID: " << get_id() << endl;
    cout << "CPF do cliente: " << get_owner_cpf() << endl;
    cout << "Placa do veiculo: " << get_placa() << endl;
    cout << "Quilometragem: " << get_placa() << endl;
    cout << "Motivo: " << get_motivo() << endl;
    cout << "Preco: R$ " << get_cost() << endl;
    cout << "-------------------------------------\n";

}