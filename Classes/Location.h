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
    /** Constructor default.
*/
    Location() = default;
    /** Constructor of a Location from the location in the format of a string.
*/
    Location(string location);
    /** Constructor of a Location from the address and coordinates given.
*/
    Location(Address address, pair<float, float> coords);
    //Metodos Set
    /** Sets the Address of a Location.
       * @param address is the parameter you want the new Date to have.
*/
    void setLocationAddress(Address address);
    /** Sets the coords of a Location.
       * @param coords is the parameter you want the new Date to have.
*/
    void setLocationCoords(pair<float,float> coords);
    //Metodos Get
    /**
      * @return the Address.
*/
    Address getLocationAddress() const;
    /**
      * @return the coords.
*/
    pair <float,float> getLocationCoords() const;
    //Other Methods
    /** Displays the Location in a nice format.
      * @param out is the ostream.
      * @param location is the Location you want to display.
     */
    friend ostream& operator<<(ostream& out, const Location &location);
};


#endif //AEDA_UGHEATS_LOCATION_H
