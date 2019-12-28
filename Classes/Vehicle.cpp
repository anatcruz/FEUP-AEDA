#include "Vehicle.h"

Vehicle::Vehicle(string manufacturer, string type, Date purchaseDate) {
    this->manufacturer=manufacturer;
    this->type=type;
    this->purchaseDate=purchaseDate;
    drivenKms = 0;
    numDeliveries = 0;
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

void Vehicle::setDrivenKms(int kms) {
    drivenKms = kms;
}

void Vehicle::setNumDeliveries(int deliveries) {
    numDeliveries = deliveries;
}


//Metodos Get

string Vehicle::getManufacturer() const { return manufacturer; }

string Vehicle::getType() const { return type; }

Date Vehicle::getPurchaseDate() const { return purchaseDate; }

int Vehicle::getDrivenKms() const { return drivenKms; }

int Vehicle::getNumDeliveries() const { return numDeliveries; }


//Other Methods

bool Vehicle::operator<(const class Vehicle & vhc) const {
    if (this->numDeliveries < vhc.getNumDeliveries()) {
        return true;
    } else if (this->numDeliveries == vhc.getNumDeliveries() && this->drivenKms < vhc.getDrivenKms()) {
        return true;
    } else if (this->numDeliveries == vhc.getNumDeliveries() && this->drivenKms == vhc.getDrivenKms() && this->purchaseDate < vhc.getPurchaseDate()) {
        return true;
    }
    return false;
}

ostream& operator<<(ostream& out, const Vehicle &vehicle){
    out << vehicle.manufacturer << ", " << vehicle.type << ", " << vehicle.purchaseDate << ", " << vehicle.drivenKms <<
    ", " << vehicle.numDeliveries;
    return out;
}



