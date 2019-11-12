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
class Worker;

class Base {
private:
    Admin* manager;
    vector<Client> clients;
    vector<Restaurant> restaurants;
    vector<Worker*> workers;
    vector<Order*> orders;
    vector<string> municipalities;
    string clientsFile;
    string restaurantsFile;
    string workersFile;
protected:
    Location location;
public:
    Base() = default;
    Base(Location location, Admin* manager, vector<Client> clients, vector<Restaurant> restaurants, vector<Worker*> workers, vector<Order*> orders, vector<string> municipalities, string clientsFile, string restaurantsFile, string workersFile);
    //Metodos Set
    void setBaseLocation(Location location);
    void setBaseManager(Admin* manager);
    void setBaseClients(vector<Client> clients);
    void setBaseRestaurants(vector<Restaurant> restaurants);
    void setBaseWorkers(vector<Worker*> workers);
    void setBaseOrders(vector<Order*> orders);
    void setBaseMunicipalities(vector<string> municipalities);
    void setBaseWorkersFile(string workersFile);
    void setBaseClientsFile(string clientsFile);
    void setBaseRestaurantsFile(string restaurantsFile);
    //Metodos Get
    Location getBaseLocation() const;
    Admin* getBaseManager() const;
    vector<Client> getBaseClients() const;
    vector<Client>* getBaseClientsAddr();
    vector<Restaurant> getBaseRestaurants() const;
    vector<Restaurant>* getBaseRestaurantsAddr();
    vector<Worker*> getBaseWorkers() const;
    vector<Worker*>* getBaseWorkersAddr();
    vector<Order*> getBaseOrders() const;
    vector<string> getBaseMunicipalities() const;
    string getBaseWorkersFile() const;
    string getBaseClientsFile() const;
    string getBaseRestaurantsFile() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Base &base);
    void addClientToBase(const Client &client);
    void addRestaurantToBase(const Restaurant &restaurant);
    void addWorkerToBase(Worker *worker);
};

//Verifica se o municipio esta entre o vetor de municipios
bool searchbyMunicipality(string municipality, vector<string> municipalities);
//Dado um munipio diz se existe uma base com esse municipio
bool exitsBase(vector<Base> bases, string municipality);

#endif //AEDA_UGHEATS_BASE_H
