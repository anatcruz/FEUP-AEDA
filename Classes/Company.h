#ifndef AEDA_UGHEATS_COMPANY_H
#define AEDA_UGHEATS_COMPANY_H

#include <string>
#include <vector>
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

Client* clientLogin(Company &company);
Worker* workerLogin(Company &company);


// File updating

void updateCompanyFile(Company &company);
void updateBasesFile(Company &company);
void updateClientsFile(Base &base);
void updateWorkersFile(Base &base);


// Client functions

void viewClientOrdersHistory(Client &client);
bool createClientAccount(Company &company);
bool editClientInfo(Company &company, Client &client);
bool deleteClientAccount(Client* client, Base* base);


// Order functions

bool makeOrderDelivery(Client &client, Restaurant *restaurant); //TODO finished needs TESTING
bool makeOrderDeliveryByRestaurant(Client &client, Base &base); //TODO finished needs TESTING
bool makeOrderDeliveryByMunicipality(Client &client, Base &base); //TODO finished needs TESTING
bool makeOrderDeliveryByPrice(Client &client, Base &base); //TODO finished needs TESTING
bool makeOrderDeliveryByCuisine(Client &client, Base &base); //TODO finished needs TESTING


// Show functions

void showAllClients(Company &company);
void showClientsByBase(Company &company);
void showSpecificClient(Company &company);
void showAllRestaurants(Company &company);
void showRestaurantsByBase(Company &company);
void showSpecificRestaurant(Company &company);
void showCompanyTotalEarnings(Company &company);
void showEarningByBase(Company &company);

#endif //AEDA_UGHEATS_COMPANY_H
