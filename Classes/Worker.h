#ifndef AEDA_UGHEATS_WORKER_H
#define AEDA_UGHEATS_WORKER_H

#include <string>
#include <vector>
#include "Order.h"
#include "Date.h"
#include "Vehicle.h"
#include "../utils.h"

class Order;
class Base;

using namespace std;

class Worker {
protected:
    string name;
    int nif;
    Date birthdate;
    double salary;
    Base* base;
public:
    Worker() = default;
    Worker(string name, int nif, Date birthdate, double salary);
    //Metodos Set
    void setWorkerName(string name);
    void setWorkerNif(int nif);
    void setWorkerBirthdate(Date birthdate);
    void setWorkerSalary(double salary);
    void setWorkerBase(Base* base);
    //Metodos Get
    string getWorkerName() const;
    int getWorkerNif() const;
    Date getWorkerBirthdate() const;
    double getWorkerSalary() const;
    Base* getWorkerBase() const;
    //Other Methods
    virtual void print(ostream &out) const;
};

class Admin: public Worker {
protected:
    string description;
public:
    Admin() = default;
    Admin(string name, int nif, Date birthdate, double salary, string description);
    //Metodos Set
    void setWorkerDescription(string description);
    //Metodos Get
    string getWorkerDescription() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Admin &admin);
};

class Deliveryperson: public Worker {
protected:
    Vehicle vehicle;
public:
    Deliveryperson() = default;
    Deliveryperson(string name, int nif, Date birthdate, double salary, Vehicle vehicle);
    //Metodos Set
    void setVehicle(Vehicle vehicle);
    //Metodos Get
    Vehicle getVehicle() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Deliveryperson &deliveryperson);
};


#endif //AEDA_UGHEATS_WORKER_H
