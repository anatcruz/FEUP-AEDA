#include "Vehicle.h"

Vehicle::Vehicle(string manufacturer, string type, Date purchaseDate, string licensePlate) {
    this->manufacturer=manufacturer;
    this->type=type;
    this->purchaseDate=purchaseDate;
    this->licensePlate=licensePlate;
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

void Vehicle::setLicensePlate(string licensePlate) {
    this->licensePlate=licensePlate;
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

string Vehicle::getLicensePlate() const {return licensePlate;}

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
    out << vehicle.manufacturer << ", " << vehicle.type << ", " << vehicle.licensePlate << ", " <<vehicle.purchaseDate << ", " << vehicle.drivenKms <<
    "kms, " << vehicle.numDeliveries << " deliveries";
    return out;
}




