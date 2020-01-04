#ifndef AEDA_UGHEATS_COMPANY_H
#define AEDA_UGHEATS_COMPANY_H

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "Base.h"
#include <unordered_set>
#include "../utils.h"

using namespace std;

class Company {
private:
    string name;
    Location location;
    double capital;
    int nif;
    /**Contact information.
*/
    string email;
    /**Contact information.
*/
    string phone;
    /**The bases where the Company works at.
*/
    vector<Base> bases;
    /**The file which contains the information of the Company.
*/
    string companyFile;
    /**The file which contains the information of the bases.
*/
    string basesFile;
public:
    /** The file path where all the data is.
*/
    static string filePath;
    /**Default Constructor.
*/
    Company() = default;
    /** Constructor of the Company from the name, Location, capital, nif, email, phone and bases given.
*/
    Company(string name, Location location, double capital, int nif, string email, string phone, vector<Base> bases);
    /** Constructor of the Company from a given file path.
       * @param filesPath is what you want to transform in the Company.
*/
    Company(const string &filesPath);
    /** Default destructor.
*/
    ~Company();
    //Metodos Set
    /** Sets the name of the Company.
       * @param name is the parameter you want the Company to have.
*/
    void setCompanyName(string name);
    /** Sets the Location of the Company.
      * @param location is the parameter you want the Company to have.
*/
    void setCompanyLocation(Location location);
    /** Sets the capital of the Company.
      * @param capital is the parameter you want the Company to have.
*/
    void setCompanyCapital(double capital);
    /** Sets the nif of the Company.
      * @param nif is the parameter you want the Company to have.
*/
    void setCompanyNif(int nif);
    /** Sets the email of the Company.
      * @param email is the parameter you want the Company to have.
*/
    void setCompanyEmail(string email);
    /** Sets the phone of the Company.
      * @param phone is the parameter you want the Company to have.
*/
    void setCompanyPhone(string phone);
    /** Sets the bases of the Company.
      * @param bases is the parameter you want the Company to have.
*/
    void setCompanyBases(vector<Base> bases);
    /** Sets the bases'file of the Company.
      * @param basesFile is the parameter you want the Company to have.
*/
    void setCompanyBasesFile(string basesFile);
    //Metodos Get
    /**
       * @return the Company's name.
*/
    string getCompanyName() const;
    /**
       * @return the Company's Location.
*/
    Location getCompanyLocation() const;
    /**
       * @return the Company's capital.
*/
    double getCompanyCapital() const;
    /**
       * @return the Company's nif.
*/
    int getCompanyNif() const;
    /**
       * @return the Company's email.
*/
    string getCompanyEmail() const;
    /**
       * @return the Company's phone.
*/
    string getCompanyPhone() const;
    /**
       * @return the Company's bases.
*/
    vector<Base> getCompanyBases() const;
    /**
       * @return the Company's bases'address.
*/
    vector<Base>* getCompanyBasesAddr();
    /**
       * @return the Company's bases'file.
*/
    string getCompanyBasesFile() const;
    /**
       * @return the Company's file.
*/
    string getCompanyFile() const;
    //Other Methods
    /** Displays the Company in a nice format.
      * @param out is the ostream.
      * @param company is the Company you want to display.
     */
    friend ostream& operator<<(ostream& out, const Company &company);
};

// LogIn

/** Log-in function for clients: allows the clients to log-in the app.
       * The user will select the base he's in and then has to insert his nif as password.
       * @param company is our Company.
*/
Client* clientLogin(Company &company);
/** Log-in function for admins: allows the admins to log-in the app.
       * The user will select the base he's in and then has to insert his nif as password.
       * @param company is our Company.
*/
Worker* adminLogin(Company &company);


// File updating

/** Updates the Company's file.
       * Writes the updated information on the file of the Company.
       * @param company is our Company.
*/
void updateCompanyFile(Company &company);
/** Updates the bases's file.
       * Writes the updated information on the file of the bases.
       * @param company is our Company.
*/
void updateBasesFile(Company &company);
/** Updates the clients' file.
       * Writes the updated information on the file of clients for each base.
       * @param base is the base existing.
*/
void updateClientsFile(Base &base);
/** Updates the workers' file.
       * Writes the updated information on the file of workers for each base.
       * @param base is the base existing.
*/
void updateWorkersFile(Base &base);
/** Updates the restaurants' file.
       * Writes the updated information on the file of restaurants for each base.
       * @param base is the base existing.
*/
void updateRestaurantsFile(Base &base);
/** Updates the products' file.
       * Writes the updated information on the file of products for each restaurant of the base.
       * @param base is the base existing.
*/
void updateProductsFile(Base &base);
/** Updates the orders' file.
       * Writes the updated information on the file of orders of the base.
       * @param base is the base existing.
*/
void updateOrdersFile(Base &base);


// Client functions
/** Allows the client to see his order history.
       * The user will see all his past orders with it's descriptions.
       * @param client is the User Client.
*/
void viewClientOrdersHistory(Client &client);

/** Sign up function: allows a client to create an account in our app.
       * The user first selects the base in which he wants to sign up and then fills all the other parameters.
       * @param company is our Company Ugh-Eats.
       * @return true if the client was able to sign up.
*/
bool createClientAccount(Company &company);

/** Allows the client to edit his account.
       * Its allows the client to change the name and address. If the client changes to another municipality which is not reached by the previous base the user must creat another account.
       * @param company is our Company Ugh-Eats.
       * @param client is the User Client.
       * @return true if the client was able to change the account.
*/
bool editClientInfo(Company &company, Client &client);

/** Allows the client to eliminate his account.
       * After making sure the user really wants to delete his account, the account is deleted.
       * @param company is our Company Ugh-Eats.
       * @param client is the user Client.
       * @return true if the client was able to eliminate the account.
*/
bool deleteClientAccount(Client* client, Base* base);

//Restaurant functions
/** Allows an admin to add a restaurant to his base.
       * It calls the auxiliary function makeRestaurant(Base* base) to create the restaurant.
       * @param base is the Base the admin works in.
       * @return true if the restaurant was added successfully.
*/
bool addRestaurant(Base* base);
/** Allows an admin to remove a restaurant from his base.
       * @param base is the Base the admin works in.
       * @return true if the restaurant was eliminated successfully.
*/
bool removeRestaurant(Base* base);
/** Allows an admin to add a product to a specific restaurant to his base.
       * The admin must first choose the restaurant and then it calls the auxiliary function addProductsToRestaurant(const Product &product) to add the product.
       * @param base is the Base the admin works in.
       * @return true if the product was added successfully.
*/
bool addProduct(Base* base);
/** Allows an admin to remove a product from a specific restaurant from his base.
       * The admin must first choose the restaurant.
       * @param base is the Base the admin works in.
       * @return true if the product was eliminated successfully.
*/
bool removeProduct(Base* base);

// Order functions
/** Allows a Client to make an Order and the Delivery associated.This is a function that its called in other functions.
       * Already having the Restaurant the Client wants to Order from, its displayed the products of that Restaurant for the Client to choose.The Client can also give some notes for the delivery and the success of the delivery is decided upon the satisfaction of the Client.
       * @param client is the Client who wants to make an order.
       * @param restaurant is the Restaurant the Client wants to make an Order from.
       * @param base is the Base of the Client.
       * @return true if the Client made an order successfully.
*/
bool makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base);
/** Allows a Client to make an Order and the Delivery associated.This is a function that its called in other functions.
       * Already having the Restaurant the Client wants to Order from, its displayed the products selected by some condition(price or cuisine) of that Restaurant for the Client to choose.The Client can also give some notes for the delivery and the success of the delivery is decided upon the satisfaction of the Client.
       * @param client is the Client who wants to make an order.
       * @param restaurant is the Restaurant the Client wants to make an Order from.
       * @param base is the Base of the Client.
       * @param product_options is all the products the Client can choose from.
       * @return true if the Client made an order successfully.
*/
bool makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base, vector<Product> product_options);
/** Allows a Client to make an order and the delivery associated.
       * The Client starts his search by choosing the restaurant he wants to order from for and this function calls makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base) to finish the process.The Client can cancel his order at any moment.
       * @param client is the Client who wants to make an order.
       * @param base is the Base of the Client.
       * @return true if the Client made an order successfully.
*/
bool makeOrderDeliveryByRestaurant(Client &client, Base *base);
/** Allows a Client to make an order and the delivery associated.
       * The Client starts his search by choosing the municipality he wants to order from for and this function calls makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base) to finish the process.The Client can cancel his order at any moment.
       * @param client is the Client who wants to make an order.
       * @param base is the Base of the Client.
       * @return true if the Client made an order successfully.
*/
bool makeOrderDeliveryByMunicipality(Client &client, Base *base);
/** Allows a Client to make an order and the delivery associated.
       * The Client starts his search by choosing the limit price he wants to pay and and this function calls makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base, vector<Product> product_options) to finish the process.The Client can cancel his order at any moment.
       * @param client is the Client who wants to make an order.
       * @param base is the Base of the Client.
       * @return true if the Client made an order successfully.
*/
bool makeOrderDeliveryByPrice(Client &client, Base *base);
/** Allows a Client to make an order and the delivery associated.
       * The Client starts his search by choosing the type of food he is looking and for and this function calls makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base) to finish the process.The Client can cancel his order at any moment.
       * @param client is the Client who wants to make an order.
       * @param base is the Base of the Client.
       * @return true if the Client made an order successfully.
*/
bool makeOrderDeliveryByCuisine(Client &client, Base *base);
/** Allows a Client to make an order and the delivery associated.
       * The Client can order from any restaurant in the base and this function calls makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base) to finish the process.The Client can cancel his order at any moment.
       * @param client is the Client who wants to make an order.
       * @param base is the Base of the Client.
       * @return true if the Client made an order successfully.
*/
bool makeOrderDeliveryAll(Client &client, Base *base);

//Worker functions: only allowed to admins.
/** Allows an Admin to hire a Worker and create his account.
       * After selecting a Base and the job qualification(Admin or Deliveryperson) the admin fills all the parameters.
       * @param company is our Company Ugh-Eats.
       * @return true if the new Worker was hired and the account was created.
*/
bool hireWorker(Base *base);
/** Allows an Admin to edit a worker's account.
       * After selecting the Base and the job qualification(Admin or Deliveryperson) the admin can change the name, salary and function description of the Worker.
       * @param company is our Company Ugh-Eats.
       * @return true if the information of the Worker was changed successfully.
*/
bool editWorkerInfo(Base *base);
/** Allows an Admin to fire a Worker and eliminate his account.
       * After selecting the Base the Admin inserts the nif of the Worker he wants to fire.It's not allowed to fire the manager of the Base.
       * @param company is our Company Ugh-Eats.
       * @return true the Worker was fired and the account eliminated.
*/
bool fireWorker(Base *base);

// Show functions

/** Allows an admin to see all the clients in the Company.
       * @param company is our Company Ugh-Eats.
*/
void showAllClients(Company &company);

/** Allows an admin to see all the clients in the Company of a specific Base.
       * The user must select the base he wants to see the clients from.
       * @param company is our Company Ugh-Eats.
*/
void showClientsByBase(Company &company);

/** Allows an admin to see a specific client in the Company.
       * The user must search the client by nif.
       * @param company is our Company Ugh-Eats.
*/
void showSpecificClient(Company &company);

/** Allows an admin to see all the restaurants in the Company.
       * @param company is our Company Ugh-Eats.
*/
void showAllRestaurants(Company &company);

/** Allows an admin to see all the restaurants in the Company of a specific Base.
       * The user must select the base he wants to see the restaurants from.
       * @param company is our Company Ugh-Eats.
*/
void showRestaurantsByBase(Company &company);

/** Allows an admin to see a specific restaurant in the Company.
       * The user must search the restaurant by it's name.
       * @param company is our Company Ugh-Eats.
*/
void showSpecificRestaurant(Company &company);
/** Allows an admin to see all the products from all the restaurants in the Base.
       * @param base is the Base the admin wants to see the products from.
*/
void showAllProducts(Base* base);
/** Allows an admin to see all the products in a specific restaurant in the Base.
       * The user must search the restaurant by it's name.
       * @param base is the Base the admin wants to see the products from.
*/
void showProductsByRestaurant(Base* base);
/** Allows an admin to see all the products that are a specific type of food in the Base.
       * The user must search the products by the type of food.
       * @param base is the Base the admin wants to see the products from.
*/
void showProductsByCuisine(Base* base);

/** Allows an admin to see the workers from a Base.
       * @param base is the Base you want to see the workers from.
*/
void showWorkers(Base* base);
/** Allows an admin to see the admins from a Base.
       * @param base is the Base you want to see the admins from.
*/
void showAdmins(Base* base);
/** Allows an admin to see the deliverypersons from a Base.
       * @param base is the Base you want to see the deliverypersons from.
*/
void showDeliverypersons(Base *base);

void showRepairman(Base *base);

/** Allows an admin to see a specific worker from a Base.
       * @param base is the Base you want to see the worker from.
*/
void showSpecificWorker(Base *base);

void showActiveWorkers(Base *base);

void showOldWorkers(Base *base);

void showBaseVehicles(Base* base);

void showVehiclesUnderMaintenance(Base* base);

void showAvailableVehicles(Base* base);

void showSpecificVehicle(Base* base);

bool changeDeliveryPersonVehicle(Base* base);

/** Allows an admin to see the orders from a Base.
       * @param base is the Base you want to see the orders from.
*/
void showBaseOrders(Base* base);
/** Allows an admin to see a specific restaurant's orders from a Base.
       * @param base is the Base you want to see the orders from.
*/
void showSpecificRestaurantsOrders(Base* base);
/** Allows an admin to see a specific client's orders from a Base.
       * @param base is the Base you want to see the orders from.
*/
void showSpecificClientOrders(Base* base);

/** Allows an admin to see the total earnings of the Company.
       * @param company is our Company Ugh-Eats.
*/
void showCompanyTotalEarnings(Company &company);

/** Allows an admin to see the total earnings of a base.
       * @param base is the Base you want to see the earnings from.
*/
void showEarningsByBase(Base* base);



//Useful functions:
/** Useful function that allows the user to choose a base.
       * @param company is our Company Ugh-Eats.
*/
Base* selectBase(Company &company);

#endif //AEDA_UGHEATS_COMPANY_H
