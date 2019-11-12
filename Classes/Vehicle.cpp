#include "Vehicle.h"

Vehicle::Vehicle(string manufacturer, string type, Date purchaseDate) {
    this->manufacturer=manufacturer;
    this->type=type;
    this->purchaseDate=purchaseDate;
}

//Metodos Set
void Vehicle::setManufacturer(string manufacturer) {
    this->manufacturer=manufacturer;
}

void Vehicle::setType(string type) {
    this->type=type;
}

void Vehicle::setPurchaseDate(Date purchaseDate) {
    this->purchaseDate=purchaseDate;
}

//Metodos Get
string Vehicle::getManufacturer() const {
    return manufacturer;
}

string Vehicle::getType() const {
    return type;
}

Date Vehicle::getPurchaseDate() const {
    return purchaseDate;
}

//Other Methods

ostream& operator<<(ostream& out, const Vehicle &vehicle){
    out << vehicle.manufacturer << "," << vehicle.type << "," << vehicle.purchaseDate;
    return out;
}



