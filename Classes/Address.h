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
    /** Default Constructor.
*/
    Address() = default;
    /** Constructor of an Address from the street, door, floor, postcode and municipality given.
*/
    Address(string street, string door, string floor, string postcode, string municipality);
    /** Constructor of an Address from a given address in the format of a string.
       * @param fullAddress is what you want to transform in an Address.
*/
    Address(string fullAddress);
    //Metodos Set
    /** Sets the street of an Address.
       * @param street is the parameter you want the new Address to have.
*/
    void setStreet(string street);
    /** Sets the door of an Address.
       * @param door is the parameter you want the new Address to have.
*/
    void setDoor(string door);
    /** Sets the floor of an Address.
       * @param floor is the parameter you want the new Address to have.
*/
    void setFloor(string floor);
    /** Sets the postcode of an Address.
       * @param postcode is the parameter you want the new Address to have.
*/
    void setPostCode(string postcode);
    /** Sets the municipality of an Address.
       * @param municipality is the parameter you want the new Address to have.
*/
    void setMunicipality(string municipality);
    //Metodos Get
    /**
       * @return the Address'street.
*/
    string getStreet() const;
    /**
       * @return the Address'door.
*/
    string getDoor() const;
    /**
       * @return the Address'floor.
*/
    string getFloor() const;
    /**
       * @return the Address'postcode.
*/
    string getPostCode() const;
    /**
       * @return the Address'municipality.
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
