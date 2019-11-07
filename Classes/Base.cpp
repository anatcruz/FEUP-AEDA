#include "Base.h"

Base::Base(Location location, Admin* manager, vector<Client*> clients, vector<Restaurant*> restaurants,
           vector<string> municipalities) {
    this->location=location;
    this->manager=manager;
    this->clients=clients;
    this->restaurants=restaurants;
    this->municipalities=municipalities;
}

//Metodos Set
void Base::setBaseLocation(Location location) {
    this->location = location;
}

void Base::setBaseManager(Admin* manager) {
    this->manager = manager;
}

void Base::setBaseClients(vector<Client*> clients) {
    this->clients = clients;
}

void Base::setBaseRestaurants(vector<Restaurant*> restaurants) {
    this->restaurants = restaurants;
}

void Base::setBaseMunicipalities(vector<string> municipalities) {
    this->municipalities = municipalities;
}

//Metodos Get
Location Base::getBaseLocation() const {
    return location;
}

Admin* Base::getBaseManager() const {
    return manager;
}

vector<Client*> Base::getBaseClients() const {
    return clients;
}

vector<Restaurant*> Base::getBaseRestaurants() const {
    return restaurants;
}

vector<string> Base::getBaseMunicipalities() const {
    return municipalities;
}

//Other Methods

