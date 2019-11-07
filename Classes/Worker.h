#ifndef AEDA_UGHEATS_WORKER_H
#define AEDA_UGHEATS_WORKER_H

#include <string>
#include <vector>
#include "Order.h"
#include "Date.h"
#include "Vehicle.h"
#include "../utils.h"

class Order;

using namespace std;

class Worker {
protected:
    string name;
    int nif;
    Date birthdate;
    double salary;
public:
    Worker() = default;
    Worker(string name, int nif, Date birthdate, double salary);
    //Metodos Set
    void setWorkerName(string name);
    void setWorkerNif(int nif);
    void setWorkerBirthdate(Date birthdate);
    void setWorkerSalary(double salary);
    //Metodos Get
    string getWorkerName() const;
    int getWorkerNif() const;
    Date getWorkerBirthdate() const;
    double getWorkerSalary() const;
};

class Admin: Worker {
protected:
    string description;
public:
    Admin() = default;
    Admin(string description);
    //Metodos Set
    void setWorkerDescription(string description);
    //Metodos Get
    string getWorkerDescription() const;
};

class Deliveryperson: Worker {
protected:
    Vehicle vehicle;
    vector<Order*> orders;
public:
    Deliveryperson() = default;
    Deliveryperson(Vehicle vehicle, vector<Order*> orders);
    //Metodos Set
    void setVehicle(Vehicle vehicle);
    void setDeliverypersonOrders(vector<Order*> orders);
    //Metodos Get
    Vehicle getVehicle() const;
    vector<Order*> getDeliverypersonOrders() const;
};


#endif //AEDA_UGHEATS_WORKER_H
