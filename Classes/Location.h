#ifndef AEDA_UGHEATS_LOCATION_H
#define AEDA_UGHEATS_LOCATION_H

#include "Address.h"
#include <utility>
#include "utils.h"

using namespace std;

class Location {
private:
    Address address;
    pair<int,int> coords;
public:
    Location() = default;
    Location(Address address, pair<float, float> coords);
    //Metodos Set
    void setLocationAddress(Address address);
    void setLocationCoords(pair<int,int> coords);
    //Metodos Get
    Address getLocationAddress() const;
    pair <int,int> getLocationCoords() const;
    //Other Methods

};


#endif //AEDA_UGHEATS_LOCATION_H
