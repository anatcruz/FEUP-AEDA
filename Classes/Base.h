#ifndef AEDA_UGHEATS_BASE_H
#define AEDA_UGHEATS_BASE_H

#include <string>
#include <vector>
#include <unordered_set>
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

struct workerHash
{
    int operator() (const Worker* &w) const
    {
        string s1=w->getWorkerName();
        int v = 0;
        for ( unsigned int i=0; i< s1.size(); i++ )
            v = 37*v + s1[i];
        return v;
    }

    bool operator() (const Worker* &w1, const Worker* &w2) const
    {
        return w1->getWorkerNif()==w2->getWorkerNif();
    }
};

typedef unordered_set<Worker*, workerHash, workerHash> tabHWorker;

class Base {
private:
    Admin* manager;
    /** The clients that live in that Base.
 */
    vector<Client> clients;
    /** The restaurants that are located in that Base.
 */
    vector<Restaurant> restaurants;
    /** The workers that work in that Base.
 */
    tabHWorker workers;
    /** All the orders that were made from restaurants located in that Base.
 */
    vector<Order*> orders;
    /** All the municipalities included by that Base: base and border municipalities.
 */
    vector<string> municipalities;
    /** The file that contains the clients of the Base.
 */
    string clientsFile;
    /** The file that contains the restaurants of the Base.
 */
    string restaurantsFile;
    /** The file that contains the workers of the Base.
 */
    string workersFile;
    /** The file that contains the orders of the Base.
 */
    string ordersFile;
protected:
    /** Location of the Base.
 */
    Location location;
public:
    /** Default Constructor.
 */
    Base() = default;
    /** Constructor of a Base from the Location, manager, clients, restaurants, workers, orders, municipalities, clients'file, restaurants'file and workers'file.
*/
    Base(Location location, Admin* manager, vector<Client> clients, vector<Restaurant> restaurants, tabHWorker workers, vector<Order*> orders, vector<string> municipalities, string clientsFile, string restaurantsFile, string workersFile);
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
    void setBaseWorkers(tabHWorker workers);
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
       * @return the Base's Location.
*/
    Location getBaseLocation() const;
    /**
       * @return the Base's manager.
*/
    Admin* getBaseManager() const;
    /**
       * @return the Base's clients.
*/
    vector<Client> getBaseClients() const;
    /**
       * @return the Base's clients'address.
*/
    vector<Client>* getBaseClientsAddr();
    /**
       * @return the Base's restaurants.
*/
    vector<Restaurant> getBaseRestaurants() const;
    /**
       * @return the Base's restaurants'address.
*/
    vector<Restaurant>* getBaseRestaurantsAddr();
    /**
       * @return the Base's workers.
*/
    tabHWorker getBaseWorkers() const;
    /**
       * @return the Base's workers'address.
*/
    tabHWorker* getBaseWorkersAddr();
    /**
       * @return the Base's orders.
*/
    vector<Order*> getBaseOrders() const;
    /**
       * @return the Base's municipalities.
*/
    vector<string> getBaseMunicipalities() const;
    /**
       * @return the Base's workers'file.
*/
    string getBaseWorkersFile() const;
    /**
      * @return the Base's clients'file.
*/
    string getBaseClientsFile() const;
    /**
      * @return the Base's restaurants'file.
*/
    string getBaseRestaurantsFile() const;
    /**
      * @return the Base's orders'file.
*/
    string getBaseOrdersFile() const;
    /** Search for a Worker in a Base by the nif.
       * @param nif is how to search for the Worker.
       * @return the pointer to the Worker wanted or a null pointer if the Worker does not exist.
*/
    Worker* getWorker(const int &nif);
    /** Search for a restaurant in a Base by the name.
        * @param name is how to search for the Restaurant.
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
       * @param municipality is the municipality to want to search for.
       * @param municipalities is the vector where we want to look for the municipality.
       * @return true if the municipality exists in the vector.
*/
bool searchbyMunicipality(string municipality, vector<string> municipalities);

/** Checks if a municipality exists in one of the Company's bases.
       * @param bases is the vector where we want to look for the municipality.
       * @param municipality is the municipality you want to search for.
       * @return true if exists a Base.
*/
bool exitsBase(vector<Base> bases, string municipality);

#endif //AEDA_UGHEATS_BASE_H
