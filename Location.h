#ifndef AEDA_UGHEATS_LOCATION_H
#define AEDA_UGHEATS_LOCATION_H

#include "Address.h"
#include <utility>

using namespace std;

class Location {
private:
    Address address;
    pair<int,int> coords;
};


#endif //AEDA_UGHEATS_LOCATION_H
