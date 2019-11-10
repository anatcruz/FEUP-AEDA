#ifndef AEDA_UGHEATS_BASE_H
#define AEDA_UGHEATS_BASE_H

#include <string>
#include <vector>
#include "Location.h"
#include "Worker.h"
#include "Client.h"
#include "Restaurant.h"
#include "../utils.h"

using namespace std;

class Client;
class Restaurant;
class Admin;

class Base {
private:
    Admin* manager;
    vector<Client> clients;
    vector<Restaurant> restaurants;
    vector<string> municipalities;
    string clientsFile;
    string restaurantsFile;
protected:
    Location location;
public:
    Base() = default;
    Base(Location location, Admin* manager, vector<Client> clients, vector<Restaurant> restaurants, vector<string> municipalities);
    //Metodos Set
    void setBaseLocation(Location location);
    void setBaseManager(Admin* manager);
    void setBaseClients(vector<Client> clients);
    void setBaseRestaurants(vector<Restaurant> restaurants);
    void setBaseMunicipalities(vector<string> municipalities);
    void setBaseClientsFile(string clientsFile);
    void setBaseRestaurantsFile(string restaurantsFile);
    //Metodos Get
    Location getBaseLocation() const;
    Admin* getBaseManager() const;
    vector<Client> getBaseClients() const;
    vector<Restaurant> getBaseRestaurants() const;
    vector<string> getBaseMunicipalities() const;
    string getBaseClientsFile() const;
    string getBaseRestaurantsFile() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Base &base);
    void addClientToBase(const Client &client);
    void addRestaurantToBase(const Restaurant &restaurant);
};


#endif //AEDA_UGHEATS_BASE_H
