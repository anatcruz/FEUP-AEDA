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
    string ordersFile;
protected:
    Location location;
public:
    /** Constructor default.
*/
    Base() = default;
    /** Constructor of a Base from the location, manager, clients, restaurants, workers, orders, municipalities, clients'file, restaurants'file and workers'file
*/
    Base(Location location, Admin* manager, vector<Client> clients, vector<Restaurant> restaurants, vector<Worker*> workers, vector<Order*> orders, vector<string> municipalities, string clientsFile, string restaurantsFile, string workersFile);
    //Metodos Set
    /** Sets the Location of a Base.
      * @param Location is the parameter you want the new Base to have.
*/
    void setBaseLocation(Location location);
    /** Sets the manager of a Base.
      * @param manager is the parameter you want the new Base to have.
*/
    void setBaseManager(Admin* manager);
    /** Sets the clients of a Base.
      * @param clients is the parameter you want the new Base to have.
*/
    void setBaseClients(vector<Client> clients);
    /** Sets the restaurants of a Base.
      * @param restaurants is the parameter you want the new Base to have.
*/
    void setBaseRestaurants(vector<Restaurant> restaurants);
    /** Sets the workers of a Base.
      * @param workers is the parameter you want the new Base to have.
*/
    void setBaseWorkers(vector<Worker*> workers);
    /** Sets the orders of a Base.
      * @param orders is the parameter you want the new Base to have.
*/
    void setBaseOrders(vector<Order*> orders);
    /** Sets the municipalities of a Base.
      * @param municipalities is the parameter you want the new Base to have.
*/
    void setBaseMunicipalities(vector<string> municipalities);
    /** Sets the workers'file of a Base.
      * @param workersFile is the parameter you want the new Base to have.
*/
    void setBaseWorkersFile(string workersFile);
    /** Sets the clients'file of a Base.
      * @param clientsFile is the parameter you want the new Base to have.
*/
    void setBaseClientsFile(string clientsFile);
    /** Sets the restaurants'file of a Base.
      * @param restaurantsFile is the parameter you want the new Base to have.
*/
    void setBaseRestaurantsFile(string restaurantsFile);
    /** Sets the orders'file of a Base.
      * @param ordersFile is the parameter you want the new Base to have.
*/
    void setBaseOrdersFile(string ordersFile);
    //Metodos Get
    /**
       * @return the Loaction.
*/
    Location getBaseLocation() const;
    /**
       * @return the manager.
*/
    Admin* getBaseManager() const;
    /**
       * @return the clients.
*/
    vector<Client> getBaseClients() const;
    /**
       * @return the clients'address for the base.
*/
    vector<Client>* getBaseClientsAddr();
    /**
       * @return the restaurants.
*/
    vector<Restaurant> getBaseRestaurants() const;
    /**
       * @return the restaurants'address.
*/
    vector<Restaurant>* getBaseRestaurantsAddr();
    /**
       * @return the workers.
*/
    vector<Worker*> getBaseWorkers() const;
    /**
       * @return the workers'address.
*/
    vector<Worker*>* getBaseWorkersAddr();
    /**
       * @return the orders.
*/
    vector<Order*> getBaseOrders() const;
    /**
       * @return the municipalities.
*/
    vector<string> getBaseMunicipalities() const;
    /**
       * @return the workers'file.
*/
    string getBaseWorkersFile() const;
    /**
      * @return the clients'file.
*/
    string getBaseClientsFile() const;
    /**
      * @return the restaurants'file.
*/
    string getBaseRestaurantsFile() const;
    /**
      * @return the orders'file.
*/
    string getBaseOrdersFile() const;
    /** Search for a Worker in a Base by the nif.
       * @param nif is how you search for the Worker.
       * @return the pointer to the Worker wanted or a null pointer if the Worker does not exist.
*/
    Worker* getWorker(const int &nif);
    /** Search for a restaurant in a Base by the name.
        * @param name is how you search for the Restaurant.
        * @return the pointer to the Restaurant wanted or a null pointer if the Restaurant does not exist.
 */
    Restaurant* getRestaurant(const string &name);
    //Other Methods
    /** Displays the Base in a nice format.
      * @param out is the ostream.
      * @param base is the Base you want to display.
     */
    friend ostream& operator<<(ostream& out, const Base &base);
    /** Updates the clients of a Base.
       * @param client is what you want to add.
*/
    void addClientToBase(const Client &client);
    /** Updates the restaurants of a Base.
       * @param restaurant is what you want to add.
*/
    void addRestaurantToBase(const Restaurant &restaurant);
    /** Updates the workers of a Base.
       * @param worker is what you want to add.
*/
    void addWorkerToBase(Worker *worker);
    /** Updates the orders of a Base.
       * @param order is what you want to add.
*/
    void addOrderToBase(Order* order);
};


/** Checks if a municipality exists in a vector of municipalities.
       * @param municipality is the municipality you want to search for.
       * @param municipalities is the vector where we want to look for the municipality.
       * @return true if the municipality exists in the vector.
*/
bool searchbyMunicipality(string municipality, vector<string> municipalities);

/** Checks if a municipality exists in one of our bases.
       * @param bases is the vector where we want to look for the municipality.
       * @param municipality is the municipality you want to search for.
       * @return true if exists a Base.
*/
bool exitsBase(vector<Base> bases, string municipality);

#endif //AEDA_UGHEATS_BASE_H
