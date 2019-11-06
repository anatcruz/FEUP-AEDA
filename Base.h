//
// Created by antonio on 31/10/19.
//

#ifndef AEDA_UGHEATS_BASE_H
#define AEDA_UGHEATS_BASE_H

#include <string>
#include <vector>
#include "Location.h"
#include "Worker.h"
#include "Client.h"
#include "Restaurant.h"

using namespace std;

class Base {
private:
    Location location;
    Admin manager;
    vector<Client> clients;
    vector<Restaurant> restaurants;
    vector<string> municipalities;
public:
    Base(Location location, Admin manager, vector<Client> clients, vector<Restaurant> restaurants, vector<string> municipalities);
    //Metodos Set
    void setBaseLocation(Location location);
    void setBaseManager(Admin manager);
    void setBaseClients(vector<Client> clients);
    void setBaseRestaurants(vector<Restaurant> restaurants);
    void setBaseMunicipalities(vector<string> municipalities);
    //Metodos Get
    Location getBaseLocation() const;
    Admin getBaseManager() const;
    vector<Client> getBaseClients() const;
    vector<Restaurant> getBaseRestaurants() const;
    vector<string> getBaseMunicipalities() const;
    //Other Methods

};


#endif //AEDA_UGHEATS_BASE_H
