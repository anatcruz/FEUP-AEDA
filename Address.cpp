#include "Address.h"

Address::Address(string street, string door, string floor, string postcode, string municipality) {
    this->street=street;
    this->door=door;
    this->floor=floor;
    this->postcode=postcode;
    this->municipality=municipality;
}

//Metodos Set
void Address::setStreet(string street) {
    this->street=street;
}

void Address::setDoor(string door) {
    this->door=door;
}

void Address::setFloor(string floor) {
    this->floor=floor;
}

void Address::setPostCode(string postcode) {
    this->postcode=postcode;
}

void Address::setMunicipality(string municipality) {
    this->municipality=municipality;
}

//Metodos Get
string Address::getStreet() const {
    return street;
}

string Address::getDoor() const {
    return door;
}

string Address::getFloor() const {
    return floor;
}

string Address::getPostCode() const {
    return postcode;
}

string Address::getMunicipality() const {
    return municipality;
}

//Other Methods

