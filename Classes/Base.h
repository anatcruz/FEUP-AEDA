#ifndef AEDA_UGHEATS_BASE_H
#define AEDA_UGHEATS_BASE_H

#include <string>
#include <vector>
#include <queue>
#include "Location.h"
#include "Vehicle.h"
#include "Worker.h"
#include "tabHWorker.h"
#include "../utils.h"
#include "bst.h"

using namespace std;

class Client;
class Restaurant;
class Admin;
class Worker;
class RepairMan;
class Order;
class Vehicle;

typedef priority_queue<RepairMan*> HEAP_REPAIRMAN;

class Base {
private:
    /** The Admin who manages the Base.
 */
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
    /** The binary search tree for the vehicles of the Base.
 */
    BST<Vehicle> baseVehicles;
    /** The priority queue containing the RepairMan of the Base.
 */
    HEAP_REPAIRMAN repairmen;
protected:
    /** Location of the Base.
 */
    Location location;
public:
    /** Default Constructor.
 */
    Base(): baseVehicles(Vehicle()) {};
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
    void setBaseWorkers(vector<Worker*> workers_v);
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
    vector<Worker*> getBaseWorkers() const;
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
    /** Search for a restaurant in a Base by the name.
        * @param name is how to search for the Restaurant.
        * @return the pointer to the Restaurant wanted or a null pointer if the Restaurant does not exist.
 */
    Restaurant* getRestaurant(const string &name);
    HEAP_REPAIRMAN getBaseRepairmen() const;
    //Other Methods

    void addVehicle(const Vehicle& v);
    bool removeVehicle(const Vehicle &v);
    BST<Vehicle> &getBaseVehicles();

    void addRepairmanToHeap(RepairMan *r);
    bool removeRepairmanFromHeap(int nif);

    bool vehicleToMaintenance();

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
    size_t removeWorker(int nif);
    /** Updates the orders of a Base.
       * @param order is what you want to add.
*/
    void addOrderToBase(Order* order);
    Worker* findWorker(int nif);
    Client* findClient(int nif);
    Vehicle findVehicle(string licenseplate);
    int assignDelivery(Time order_time, Time& delivery_time);
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
