#ifndef AEDA_UGHEATS_ADDRESS_H
#define AEDA_UGHEATS_ADDRESS_H

#include <string>
#include <vector>
#include "../utils.h"

using namespace std;

class Address {
private:
    string street;
    string door;
    string floor;
    string postcode;
    string municipality;
public:
    /** Constructor default.
*/
    Address() = default;
    /** Constructor of a Address from the street, door, floor, postcode, municipality given.
*/
    Address(string street, string door, string floor, string postcode, string municipality);
    /** Constructor of a Address from a given address in the format of string.
       * @param fullAddress is what you want to transform in a Address.
*/
    Address(string fullAddress);
    void makeAddress();
    //Metodos Set
    /** Sets the street of a Address.
       * @param street is the parameter you want the new Address to have.
*/
    void setStreet(string street);
    /** Sets the door of a Address.
       * @param door is the parameter you want the new Address to have.
*/
    void setDoor(string door);
    /** Sets the floor of a Address.
       * @param floor is the parameter you want the new Address to have.
*/
    void setFloor(string floor);
    /** Sets the postcode of a Address.
       * @param postcode is the parameter you want the new Address to have.
*/
    void setPostCode(string postcode);
    /** Sets the municipality of a Address.
       * @param municipality is the parameter you want the new Address to have.
*/
    void setMunicipality(string municipality);
    //Metodos Get
    /**
       * @return the street.
*/
    string getStreet() const;
    /**
       * @return the door.
*/
    string getDoor() const;
    /**
       * @return the floor.
*/
    string getFloor() const;
    /**
       * @return the postcode.
*/
    string getPostCode() const;
    /**
       * @return the municipality.
*/
    string getMunicipality() const;
    //Other Methods
    /** Displays the Address in a nice format.
      * @param out is the ostream.
      * @param address is the Address you want to display.
     */
    friend ostream& operator<<(ostream& out, const Address &address);
};


#endif //AEDA_UGHEATS_ADDRESS_H
