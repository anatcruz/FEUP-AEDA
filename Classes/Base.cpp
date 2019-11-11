#include "Base.h"

Base::Base(Location location, Admin* manager, vector<Client> clients, vector<Restaurant> restaurants,
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

void Base::setBaseClients(vector<Client> clients) {
    this->clients = clients;
}

void Base::setBaseRestaurants(vector<Restaurant> restaurants) {
    this->restaurants = restaurants;
}

void Base::setBaseOrders(vector<Order *> orders) {
    this->orders=orders;
}

void Base::setBaseMunicipalities(vector<string> municipalities) {
    this->municipalities = municipalities;
}

void Base::setBaseClientsFile(string clientsFile) {
    this->clientsFile=clientsFile;
}

void Base::setBaseRestaurantsFile(string restaurantsFile) {
    this->restaurantsFile=restaurantsFile;
}

//Metodos Get
Location Base::getBaseLocation() const {
    return location;
}

Admin* Base::getBaseManager() const {
    return manager;
}

vector<Client> Base::getBaseClients() const {
    return clients;
}

vector<Restaurant> Base::getBaseRestaurants() const {
    return restaurants;
}

vector<Order*> Base::getBaseOrders() const {
    return orders;
}

vector<string> Base::getBaseMunicipalities() const {
    return municipalities;
}

string Base::getBaseClientsFile() const {
    return clientsFile;
}

string Base::getBaseRestaurantsFile() const {
    return restaurantsFile;
}

//Other Methods

ostream& operator<<(ostream& out, const Base &base){
    out << "/" << endl;
    out << setw(4) << left << '|' << "Location: " << base.location <<endl;
    out << setw(4) << left << '|' << "Manager: " << base.manager <<endl;
    out << setw(4) << left << '|' << "Clients: ";
    for(int i=0 ; i<base.clients.size() ; i++){
        if (i == base.clients.size() - 1)
            out << base.clients.at(i);
        else
            out << base.clients.at(i);
    }
    out << setw(4) << left << '|' << "Restaurants: ";
    for(int i=0 ; i<base.restaurants.size() ; i++){
        if (i == base.restaurants.size() - 1)
            out << base.restaurants.at(i);
        else
            out << base.restaurants.at(i);
    }
    out << setw(4) << left << '|' << "Municipalities: ";
    for(int i=0 ; i<base.municipalities.size() ; i++){
        if (i == base.municipalities.size() - 1)
            out << base.municipalities.at(i);
        else
            out << base.municipalities.at(i);
    }
    out << "\\_" << endl;
    return out;
}

void Base::addClientToBase(const Client &client) {
    clients.push_back(client);
}

void Base::addRestaurantToBase(const Restaurant &restaurant) {
    restaurants.push_back(restaurant);
}

bool searchbyMunicipality(string municipality, vector<string> municipalities){
    for (int i = 0; i < municipalities.size(); i++){
        if (municipalities.at(i) == municipality)
            return true;
    }
    return false;
}

bool exitsBase(vector<Base> bases, string municipality){
    for(int i = 0; i < bases.size(); i++){
        if(searchbyMunicipality(municipality, bases.at(i).getBaseMunicipalities()))
            return true;
    }
    return false;
}