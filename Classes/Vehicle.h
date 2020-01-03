#ifndef AEDA_UGHEATS_VEHICLE_H
#define AEDA_UGHEATS_VEHICLE_H

#include <string>
#include "Time.h"
#include "../utils.h"

using namespace std;

class Vehicle {
private:
    /**It can be Opel, Mercedes...
    */
    string manufacturer;

    /**It can be a car, motorcycle...
    */
    string type;

    /**The Date the Vehicle was purchased.
    */
    Date purchaseDate;

    string licensePlate;
    int drivenKms;
    int numDeliveries;
    Time lastMaintenance;
public:
    /**Default Constructor.
    */
    Vehicle() = default;

    /** Constructor of a Vehicle from the manufacturer, type and purchase date given.
    */
    Vehicle(string manufacturer, string type, Date purchaseDate, string licensePlate);


    //Metodos Set

    /** Sets the manufacturer of a Vehicle.
       * @param manufacturer is the parameter you want the new Vehicle to have.
    */
    void setManufacturer(string manufacturer);

    /** Sets the type of a Vehicle.
       * @param type is the parameter you want the new Vehicle to have.
    */
    void setType(string type);

    /** Sets the purchase Date of a Vehicle.
       * @param purchaseDate is the parameter you want the new Vehicle to have.
    */
    void setPurchaseDate(Date purchaseDate);

    void setLicensePlate(string licensePlate);

    void setDrivenKms(int kms);

    void setNumDeliveries(int deliveries);

    void setLastMaintenance(Time time);


    //Metodos Get

    /**
       * @return the Vehicle's manufacturer.
    */
    string getManufacturer() const;

    /**
       * @return the Vehicle's type.
    */
    string getType() const;

    /**
       * @return the Vehicle's purchase date.
    */
    Date getPurchaseDate() const;

    string getLicensePlate() const;

    int getDrivenKms() const;

    int getNumDeliveries() const;

    Time getLastMaintenance() const;


    //Other Methods

    bool isAvailable() const;

    bool operator<(const Vehicle &vhc) const;

    bool operator==(const Vehicle &vhc);

    /** Displays the Vehicle in a nice format.
      * @param out is the ostream.
      * @param vehicle is the Vehicle you want to display.
     */
    friend ostream& operator<<(ostream& out, const Vehicle &vehicle);
};


#endif //AEDA_UGHEATS_VEHICLE_H
