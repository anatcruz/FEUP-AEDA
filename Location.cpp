#include "Location.h"

void Location::setLocationAddress(Address address) {
    this->address = address;
}

void Location::setLocationCoords(pair<int, int> coords) {
    this->coords = coords;
}

Address Location::getLocationAddress() const {
    return address;
}

pair<int, int> Location::getLocationCoords() const {
    return coords;
}
