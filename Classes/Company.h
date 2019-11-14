#ifndef AEDA_UGHEATS_COMPANY_H
#define AEDA_UGHEATS_COMPANY_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
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
    /** Constructor default.
*/
    Company() = default;
    /** Constructor of the Company from the name, location, capital, nif, email, phone and bases given.
*/
    Company(string name, Location location, double capital, int nif, string email, string phone, vector<Base> bases);
    /** Constructor of the Company from a given file path.
       * @param filesPath is what you want to transform in the Company.
*/
    Company(const string &filesPath);
    /** Destructor default.
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
       * @return the name.
*/
    string getCompanyName() const;
    /**
       * @return the location.
*/
    Location getCompanyLocation() const;
    /**
       * @return the capital.
*/
    double getCompanyCapital() const;
    /**
       * @return the nif.
*/
    int getCompanyNif() const;
    /**
       * @return the email.
*/
    string getCompanyEmail() const;
    /**
       * @return the phone.
*/
    string getCompanyPhone() const;
    /**
       * @return the bases.
*/
    vector<Base> getCompanyBases() const;
    /**
       * @return the bases'address.
*/
    vector<Base>* getCompanyBasesAddr();
    /**
       * @return the bases'file.
*/
    string getCompanyBasesFile() const;
    /**
       * @return the company's file.
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

bool makeOrderDelivery(Client &client, Restaurant *restaurant); //TODO finished needs TESTING
bool makeOrderDeliveryByRestaurant(Client &client, Base &base); //TODO finished needs TESTING
bool makeOrderDeliveryByMunicipality(Client &client, Base &base); //TODO finished needs TESTING
bool makeOrderDeliveryByPrice(Client &client, Base &base); //TODO finished needs TESTING
bool makeOrderDeliveryByCuisine(Client &client, Base &base); //TODO finished needs TESTING

//Worker functions: only allowed to admins.
/** Allows an Admin to hire workers.
       * After selecting a Base and the job qualification(Admin or Deliveryperson) the admin fills all the parameters.
       * @param company is our Company Ugh-Eats.
       * @return true if the new worker was hired.
*/
bool hireWorker(Company &company);
/** Allows an Admin to edit a worker's account.
       * After selecting the Base and the job qualification(Admin or Deliveryperson) the admin can change the name, salary and function description of the worker.
       * @param company is our Company Ugh-Eats.
       * @return true if the information of the worker was changed successfully.
*/
bool editWorkerInfo(Company &company);
bool fireWorker(Company &company);
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


//Useful functions:
/** Useful function that allows the user to choose a base.
       * @param company is our Company Ugh-Eats.
*/
Base* selectBase(Company &company);

#endif //AEDA_UGHEATS_COMPANY_H
