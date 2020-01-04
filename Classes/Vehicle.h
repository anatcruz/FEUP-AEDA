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
    /**The licence plate of the Vehicle.
    */
    string licensePlate;
    /**The total kilometers done by the Vehicle.
    */
    int drivenKms;
    /**The number of deliveries done by the Vehicle.
    */
    int numDeliveries;
public:
    /**Default Constructor.
    */
    Vehicle() = default;

    /** Constructor of a Vehicle from the manufacturer, type, purchase date and licence plate given.
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

    /** Sets the licence plate of a Vehicle.
       * @param licensePlate is the parameter you want the new Vehicle to have.
    */
    void setLicensePlate(string licensePlate);

    /** Sets the total kilometers done by a Vehicle.
       * @param kms is the parameter you want the new Vehicle to have.
    */
    void setDrivenKms(int kms);

    /** Sets the number of deliveries done by a Vehicle.
       * @param deliveries is the parameter you want the new Vehicle to have.
    */
    void setNumDeliveries(int deliveries);

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

    /**
       * @return the Vehicle's licence date.
    */
    string getLicensePlate() const;

    /**
       * @return the Vehicle's driven kilometers.
    */
    int getDrivenKms() const;

    /**
       * @return the Vehicle's number of deliveries.
    */
    int getNumDeliveries() const;


    //Other Methods
    /**
      * Updates vehicle kilometers and number of deliveries.
      * @param kms is the number of kilometers to add.
      */
    void new_delivery(int kms);

    /** Compares 2 vehicles. It's the method to order the BST.
     * It is ordered by the number of deliveries done, in the event of a tie, the number of kilometers driven and in the event of a tie, by the date of purchase.
      * @param vhc is the Vehicle to compare to.
     */
    bool operator<(const Vehicle &vhc) const;

    /**
     * Compares two vehicles by their license plates.
     * @param vhc is the Vehicle on the rhs of the comparison.
     * @return is whether the vehicles are equal or not.
     */
    bool operator==(const Vehicle &vhc);

    /** Displays the Vehicle in a nice format.
      * @param out is the ostream.
      * @param vehicle is the Vehicle you want to display.
     */
    friend ostream& operator<<(ostream& out, const Vehicle &vehicle);
};


#endif //AEDA_UGHEATS_VEHICLE_H
