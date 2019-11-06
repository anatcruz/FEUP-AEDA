//
// Created by antonio on 31/10/19.
//

#ifndef AEDA_UGHEATS_VEHICLE_H
#define AEDA_UGHEATS_VEHICLE_H

#include <string>
#include "Date.h"

using namespace std;

class Vehicle {
private:
    string manufacturer;
    string type;
    Date purchaseDate;
public:
    Vehicle() = default;
    Vehicle(string manufacturer, string type, Date purchaseDate);
    //Metodos Set
    void setManufacturer(string manufacturer);
    void setType(string type);
    void setPurchaseDate(Date purchaseDate);
    //Metodos Get
    string getManufacturer() const;
    string getType() const;
    Date getPurchaseDate() const;
};


#endif //AEDA_UGHEATS_VEHICLE_H
