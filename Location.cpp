#include "Location.h"

Location::Location(Address address, pair<int, int> coords) {
    this->address=address;
    this->coords=coords;
}

//Metodos Set
void Location::setLocationAddress(Address address) {
    this->address = address;
}

void Location::setLocationCoords(pair<int, int> coords) {
    this->coords = coords;
}

//Metodos Get
Address Location::getLocationAddress() const {
    return address;
}

pair<int, int> Location::getLocationCoords() const {
    return coords;
}

//Other Methods


