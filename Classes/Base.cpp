#include "Base.h"

Base::Base(Location location, Admin *manager, vector<Client> clients, vector<Restaurant> restaurants,
           vector<Worker *> workers, vector<Order *> orders, vector<string> municipalities, string clientsFile, string restaurantsFile, string workersFile){
    this->location=location;
    this->manager=manager;
    this->clients=clients;
    this->restaurants=restaurants;
    this->municipalities=municipalities;
    this->workers=workers;
    this->orders=orders;
    this->clientsFile=clientsFile;
    this->restaurantsFile=restaurantsFile;
    this->workersFile=workersFile;
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


void Base::setBaseWorkers(vector<Worker *> workers) {
    this->workers=workers;
}

void Base::setBaseClientsFile(string clientsFile) {
    this->clientsFile=clientsFile;
}

void Base::setBaseRestaurantsFile(string restaurantsFile) {
    this->restaurantsFile=restaurantsFile;
}

void Base::setBaseWorkersFile(string workersFile) {
    this->workersFile=workersFile;
}

void Base::setBaseOrdersFile(string ordersFile) {
    this->ordersFile = ordersFile;
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

vector<Restaurant>* Base::getBaseRestaurantsAddr() {
    return &restaurants;
}

vector<Order*> Base::getBaseOrders() const {
    return orders;
}

vector<string> Base::getBaseMunicipalities() const {
    return municipalities;
}

vector<Worker*> Base::getBaseWorkers() const {
    return workers;
}

vector<Worker*>* Base::getBaseWorkersAddr() {
    return &workers;
}

string Base::getBaseClientsFile() const {
    return clientsFile;
}

string Base::getBaseRestaurantsFile() const {
    return restaurantsFile;
}

string Base::getBaseWorkersFile() const {
    return workersFile;
}

vector<Client>* Base::getBaseClientsAddr() {
    return &clients;
}

string Base::getBaseOrdersFile() const {
    return ordersFile;
}

Worker* Base::getWorker(const int &nif) {
    auto it = find_if(workers.begin(), workers.end(),[&](Worker* &w){return w->getWorkerNif() == nif;});
    if (it != workers.end())
        return *it;
    return nullptr;
}

Restaurant* Base::getRestaurant(const string &name) {
    auto it = find_if(restaurants.begin(), restaurants.end(), [&](Restaurant &r){return r.getRestaurantName() == name;});
    if (it != restaurants.end())
        return &*it;
    return nullptr;
}

//Other Methods

ostream& operator<<(ostream& out, const Base &base){
    out << "/" << endl;
    out << setw(4) << left << '|' << "Location: " << base.location <<endl;
    out << setw(4) << left << '|' << "Manager: " << base.manager->getWorkerName() <<endl;
    out << setw(4) << left << '|' << "Clients: " << base.clients.size() << endl;
    out << setw(4) << left << '|' << "Restaurants: " << base.restaurants.size() << endl;
    out << setw(4) << left << '|' << "Municipalities: ";
    for(int i=0 ; i<base.municipalities.size() ; i++){
        if (i == base.municipalities.size() - 1)
            out << base.municipalities.at(i) << endl;
        else
            out << base.municipalities.at(i) << ", ";
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

void Base::addWorkerToBase(Worker *worker){
    workers.push_back(worker);
}

void Base::addOrderToBase(Order *order) {
    orders.push_back(order);
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