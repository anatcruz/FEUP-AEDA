#include "Location.h"

Location::Location(Address address, pair<float, float> coords) {
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

