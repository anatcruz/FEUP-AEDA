#ifndef AEDA_UGHEATS_COMPANY_H
#define AEDA_UGHEATS_COMPANY_H

#include <string>
#include <vector>
#include "Location.h"
#include "Worker.h"
#include "Base.h"

using namespace std;

class Company {
private:
    string name;
    Location location;
    double capital;
    int nif;
    string email;
    string phone;
    vector<Worker> workers;
    vector<Base> bases;
};

#endif //AEDA_UGHEATS_COMPANY_H
