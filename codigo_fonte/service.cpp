#include "service.h"

Service::Service(string service_name, float service_price) : service_name(service_name), service_price(service_price){}
Service::~Service(){}

void Service::set_service_name(string service_name){
    this->service_name = service_name;
}
void Service::set_service_price(float service_price){
    this->service_price = service_price;
}

string Service::get_service_name() const { return service_name; }
float Service::get_service_price() const { return service_price; }