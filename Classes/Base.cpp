#include "Base.h"

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


void Base::setBaseWorkers(vector<Worker *> workers_v) {
    workers.clear();
    for (auto worker : workers_v) {
        workers.insert(worker);
    }
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
    vector<Worker*> ret;
    for (auto worker : workers) {
        ret.push_back(worker);
    }
    return ret;
}

tabHWorker* Base::getBaseWorkersAddr() {
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

Restaurant* Base::getRestaurant(const string &name) {
    auto it = find_if(restaurants.begin(), restaurants.end(), [&](Restaurant &r){return r.getRestaurantName() == name;});
    if (it != restaurants.end())
        return &*it;
    return nullptr;
}

//Other Methods

void Base::addVehicle(const class Vehicle & v) {
    baseVehicles.insert(v);
}

bool Base::removeVehicle(const Vehicle &v){
    return baseVehicles.remove(v);
}

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
    workers.erase(worker);
    workers.insert(worker);
}

size_t Base::removeWorker(int nif) {
    Worker* worker = new Worker;
    worker->setWorkerNif(nif);
    return workers.erase(worker);
}

void Base::addOrderToBase(Order *order) {
    orders.push_back(order);
}

Worker* Base::findWorker(int nif) {
    Worker* worker = new Worker;
    worker->setWorkerNif(nif);
    auto it = workers.find(worker);
    if (it != workers.end()) {
        return *it;
    } else {
        return nullptr;
    }
}

Client* Base::findClient(int nif) {
    auto it = find_if(clients.begin(), clients.end(), [&](Client &c){ return c.getClientNif() == nif; });
    if (it != clients.end()) {
        return &*it;
    } else {
        return nullptr;
    }
}

int Base::assignDelivery(Time order_time, Time &delivery_time) {
    for (auto worker : workers) {
        auto d_person = dynamic_cast<Deliveryperson*>(worker);
        if (d_person != NULL && d_person->isAvailable()) {
            srand(time(NULL));
            int delta = rand() % 16 + 5;
            delivery_time = order_time.addtime(delta);
            d_person->new_delivery(0.8 * delta);
            return d_person->getWorkerNif();
        }
    }
    return -1;
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

size_t workerHash::operator() (const Worker* w) const {
    return w->getWorkerNif();
}


bool workerEq::operator() (const Worker* w1, const Worker* w2) const {
    return w1->getWorkerNif() == w2->getWorkerNif();
}
