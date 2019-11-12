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


//Funçoes de clientes
Client* clientLogin(Company &company);
void updateCompanyFile(Company &company);
void updateBasesFile(Company &company);
void updateClientsFile(Base &base);
void viewClientOrdersHistory(Client &client);
bool createClientAccount(Company &company);
bool editClientInfo(Company &company, Client &client);
bool deleteClientAccount(Client &client);

//Funçoes de fazer encomendas
bool makeOrderDelivery(Client &client, Restaurant *restaurant);
bool makeOrderDeliveryByRestaurant(Client &client, Base &base);
bool makeOrderDeliveryByMunicipality(Client &client, Base &base);
bool makeOrderDeliveryByPrice(Client &client);
bool makeOrderDeliveryByCuisine(Client &client);
#endif //AEDA_UGHEATS_COMPANY_H
