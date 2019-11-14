#ifndef AEDA_UGHEATS_VEHICLE_H
#define AEDA_UGHEATS_VEHICLE_H

#include <string>
#include "Date.h"
#include "../utils.h"

using namespace std;

class Vehicle {
private:
    string manufacturer;
    string type;
    Date purchaseDate;
public:
    /** Constructor default.
*/
    Vehicle() = default;
    /** Constructor of a Vehicle from the manufacturer, type and purchase date.
*/
    Vehicle(string manufacturer, string type, Date purchaseDate);
    //Metodos Set
    /** Sets the manufacturer of a Vehicle.
       * @param manufacturer is the parameter you want the new Vehicle to have.
*/
    void setManufacturer(string manufacturer);
    /** Sets the type of a Vehicle.
       * @param type is the parameter you want the new Vehicle to have.
*/
    void setType(string type);
    /** Sets the purchase date of a Vehicle.
       * @param purchaseDate is the parameter you want the new Vehicle to have.
*/
    void setPurchaseDate(Date purchaseDate);
    //Metodos Get
    /**
       * @return the facturer.
*/
    string getManufacturer() const;
    /**
       * @return the type.
*/
    string getType() const;
    /**
       * @return the purchase date.
*/
    Date getPurchaseDate() const;
    //Other Methods
    /** Displays the Vehicle in a nice format.
      * @param out is the ostream.
      * @param vehicle is the Vehicle you want to display.
     */
    friend ostream& operator<<(ostream& out, const Vehicle &vehicle);
};


#endif //AEDA_UGHEATS_VEHICLE_H
