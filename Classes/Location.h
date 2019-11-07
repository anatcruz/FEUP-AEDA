#ifndef AEDA_UGHEATS_LOCATION_H
#define AEDA_UGHEATS_LOCATION_H

#include "Address.h"
#include <utility>
#include "../utils.h"

using namespace std;

class Location {
private:
    Address address;
    pair<float,float> coords;
public:
    Location() = default;
    Location(Address address, pair<float, float> coords);
    //Metodos Set
    void setLocationAddress(Address address);
    void setLocationCoords(pair<float,float> coords);
    //Metodos Get
    Address getLocationAddress() const;
    pair <float,float> getLocationCoords() const;
    //Other Methods

};


#endif //AEDA_UGHEATS_LOCATION_H
