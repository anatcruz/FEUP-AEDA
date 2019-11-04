#include "Worker.h"

//Metodos Set
void Worker::setWorkerName(string name) {
    this->name = name;
}

void Worker::setWorkerNif(int nif) {
    this->nif = nif;
}

void Worker::setWorkerBirthdate(Date birthdate) {
    this->birthdate = birthdate;
}

void Worker::setWorkerSalary(double salary) {
    this->salary = salary;
}

//Metodos Get
string Worker::getWorkerName() const {
    return name;
}

int Worker::getWorkerNif() const {
    return nif;
}

Date Worker::getWorkerBirthdate() const {
    return birthdate;
}

double Worker::getWorkerSalary() const {
    return salary;
}

//Metodos Set
void Admin::setWorkerDescription(string description) {
    this->description = description;
}

//Metodos Get
string Admin::getWorkerDescription() const {
    return description;
}

//Metodos Set
void Deliveryperson::setVehicle(Vehicle vehicle) {
    this->vehicle = vehicle;
}

void Deliveryperson::setDeliverypersonOrders(vector<Order> orders) {
    this->orders = orders;
}

//Metodos Get
Vehicle Deliveryperson::getVehicle() const {
    return vehicle;
}

vector<Order> Deliveryperson::getDeliverypersonOrders() const {
    return orders;
}
