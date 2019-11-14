#ifndef AEDA_UGHEATS_COMPANY_H
#define AEDA_UGHEATS_COMPANY_H

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Location.h"
#include "Worker.h"
#include "Base.h"
#include "../utils.h"

using namespace std;

class Company {
private:
    string name;
    Location location;
    double capital;
    int nif;
    string email;
    string phone;
    vector<Base> bases;
    string companyFile;
    string basesFile;
public:
    static string filePath;
    Company() = default;
    Company(string name, Location location, double capital, int nif, string email, string phone, vector<Base> bases);
    Company(const string &filesPath);
    ~Company();
    //Metodos Set
    void setCompanyName(string name);
    void setCompanyLocation(Location location);
    void setCompanyCapital(double capital);
    void setCompanyNif(int nif);
    void setCompanyEmail(string email);
    void setCompanyPhone(string phone);
    void setCompanyBases(vector<Base> bases);
    void setCompanyBasesFile(string basesFile);
    //Metodos Get
    string getCompanyName() const;
    Location getCompanyLocation() const;
    double getCompanyCapital() const;
    int getCompanyNif() const;
    string getCompanyEmail() const;
    string getCompanyPhone() const;
    vector<Base> getCompanyBases() const;
    vector<Base>* getCompanyBasesAddr();
    string getCompanyBasesFile() const;
    string getCompanyFile() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Company &company);
};

// LogIn

/** Log-in function for clients: allows the clients to log-in the app.
       * The user will select the base he is in and then has to insert his nif as password.
       * @param company is our Company.
*/
Client* clientLogin(Company &company);
/** Log-in function for workers: allows the workers to log-in the app.
       * The user will select the base he is in and then has to insert his nif as password.
       * @param company is our Company.
*/
Worker* workerLogin(Company &company);


// File updating

/** Function to update the company's file.
       * Write the updated informations on the file of the company.
       * @param company is our Company.
*/
void updateCompanyFile(Company &company);
/** Function to update the bases's file.
       * Write the updated informations on the file of the bases.
       * @param company is our Company.
*/
void updateBasesFile(Company &company);
/** Function to update the clients' file
       * Write the updated informations on the file of clients for each base.
       * @param base is the base existing.
*/
void updateClientsFile(Base &base);
/** Function to update the workers' file
       * Write the updated informations on the file of workers for each base.
       * @param base is the base existing.
*/
void updateWorkersFile(Base &base);


// Client functions
/** Allows the client to see his order history.
       * The user will see all his past orders with its descriptions.
       * @param client is the User Client
*/
void viewClientOrdersHistory(Client &client);
/** Sign up function: allows a client to create an account in our app.
       * The user first selects the base in which he wants to sign up and then fills all the other parameters
       * @param company is our Company Ugh-Eats.
       * @return true if the client was able to sign up
*/
bool createClientAccount(Company &company);
/** Allows the client to change his account.
       * Its allows the client to change the name and address. If the client changes to another municipality which is not reached by the previous base the user must creat another account.
       * @param company is our Company Ugh-Eats.
       * @param client is the User Client.
       * @return true if the client was able to change its account.
*/
bool editClientInfo(Company &company, Client &client);
/** Allows the client to eliminate his account.
       * After making sure the user really wants to delete his account, the account is deleted.
       * @param company is our Company Ugh-Eats.
       * @param client is the User Client.
       * @return true if the client was able to eliminate his account.
*/
bool deleteClientAccount(Client* client, Base* base);


// Order functions

bool makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base); //TODO finished needs TESTING
bool makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base, vector<Product> products_ordered);
bool makeOrderDeliveryByRestaurant(Client &client, Base *base); //TODO finished needs TESTING
bool makeOrderDeliveryByMunicipality(Client &client, Base *base); //TODO finished needs TESTING
bool makeOrderDeliveryByPrice(Client &client, Base *base); //TODO finished needs TESTING
bool makeOrderDeliveryByCuisine(Client &client, Base &base); //TODO finished needs TESTING


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
/** Allows an admin to see the total earnings of the Company.
       * @param company is our Company Ugh-Eats.
*/
void showCompanyTotalEarnings(Company &company);
/** Allows an admin to see the total earnings of the Company of a specific Base.
       * The user must select the base he wants to see the earnings from.
       * @param company is our Company Ugh-Eats.
*/
void showEarningByBase(Company &company);

#endif //AEDA_UGHEATS_COMPANY_H
