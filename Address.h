#ifndef AEDA_UGHEATS_ADDRESS_H
#define AEDA_UGHEATS_ADDRESS_H

#include <string>

using namespace std;

class Address {
private:
    string street;
    string door;
    string floor;
    string postcode;
    string municipality;
public:
    //Metodos Set
    void setStreet(string street);
    void setDoor(string door);
    void setFloor(string floor);
    void setPostCode(string postcode);
    void setMunicipality(string municipality);
    //Metodos Get
    string getStreet() const;
    string getDoor() const;
    string getFloor() const;
    string getPostCode() const;
    string getMunicipality() const;
};


#endif //AEDA_UGHEATS_ADDRESS_H
