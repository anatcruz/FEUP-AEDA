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
    vector<Worker*> workers;
    vector<Base> bases;
public:
    Company() = default;
    Company(string name, Location location, double capital, int nif, string email, string phone, vector<Worker*> workers, vector<Base> bases);
    Company(string fileName);
    //Metodos Set
    void setCompanyName(string name);
    void setCompanyLocation(Location location);
    void setCompanyCapital(double capital);
    void setCompanyNif(int nif);
    void setCompanyEmail(string email);
    void setCompanyPhone(string phone);
    void setCompanyWorkers(vector<Worker*> workers);
    void setCompanyBases(vector<Base> bases);
    //Metodos Get
    string getCompanyName() const;
    Location getCompanyLocation() const;
    double getCompanyCapital() const;
    int getCompanyNif() const;
    string getCompanyEmail() const;
    string getCompanyPhone() const;
    vector<Worker*> getCompanyWorkers() const;
    vector<Base> getCompanyBases() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Company &company);
};

#endif //AEDA_UGHEATS_COMPANY_H
