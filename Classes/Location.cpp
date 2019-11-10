#include "Location.h"

Location::Location(Address address, pair<float, float> coords) {
    this->address=address;
    this->coords=coords;
}

Location::Location(string location) {
    vector<string> temp;
    Address address;
    pair<float,float> coords;
    temp = strToVect(location, ',');
    address.setStreet(temp.at(0));
    address.setDoor(temp.at(1));
    address.setFloor(temp.at(2));
    address.setPostCode(temp.at(3));
    address.setMunicipality(temp.at(4));
    coords.first = stof(temp.at(5));
    coords.second = stof(temp.at(6));
    this->address=address;
    this->coords=coords;
}

//Metodos Set
void Location::setLocationAddress(Address address) {
    this->address = address;
}

void Location::setLocationCoords(pair<float, float> coords) {
    this->coords = coords;
}

//Metodos Get
Address Location::getLocationAddress() const {
    return address;
}

pair<float, float> Location::getLocationCoords() const {
    return coords;
}

//Other Methods

ostream& operator<<(ostream& out, const Location &location){
    out << location.address << " / " << location.coords.first << ", " << location.coords.second;
    return out;
}


