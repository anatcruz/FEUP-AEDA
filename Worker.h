#ifndef AEDA_UGHEATS_WORKER_H
#define AEDA_UGHEATS_WORKER_H

#include <string>
#include <vector>
#include "Date.h"
#include "Order.h"
#include "Vehicle.h"

using namespace std;

class Worker {
protected:
    string name;
    int nif;
    Date birthdate;
    double salary;
};

class Admin: Worker {
protected:
    string description;
};

class Deliveryperson: Worker {
protected:
    Vehicle vehicle;
    vector<Order> orders;
};


#endif //AEDA_UGHEATS_WORKER_H
