#include "automobile_part.h"

AutoPart::AutoPart(string part_name, int quantity, float part_price) : part_name(part_name), quantity(quantity), part_price(part_price){}
AutoPart::~AutoPart(){}

void AutoPart::set_part_name(string part_name){
    this->part_name = part_name;
}
void AutoPart::set_part_price(float part_price){
    this->part_price = part_price;
}
void AutoPart::set_quantity(int quantity){
    this->quantity = quantity;
}

string AutoPart::get_part_name() const { return part_name; }
float AutoPart::get_part_price() const { return part_price; }
int AutoPart::get_quantity() const { return quantity; }