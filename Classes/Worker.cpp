#include "Worker.h"
//CLASS WORKER

Worker::Worker(string name, int nif, Date birthdate, double salary) {
    this->name=name;
    this->nif=nif;
    this->birthdate=birthdate;
    this->salary=salary;
}


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

void Worker::setWorkerBase(Base *base) {
    this->base = base;
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

Base* Worker::getWorkerBase() const {
    return base;
}


//Other Methods

void Worker::print(ostream &out) const {
    out << "/" << endl;
    out << setw(4) << left << '|' << "Name: " << name << endl;
    out << setw(4) << left << '|' << "NIF: " << right << setfill('0') << setw(9) << nif << setfill(' ') << endl;
    out << setw(4) << left << '|' << "Birthdate: " << birthdate << endl;
    out << setw(4) << left << '|' << "Salary: " << salary << endl;
}

//CLASS ADMIN

Admin::Admin(string name, int nif, Date birthdate, double salary, string description):Worker(name, nif, birthdate, salary) {
    this->description=description;
}

//Metodos Set
void Admin::setWorkerDescription(string description) {
    this->description = description;
}

//Metodos Get
string Admin::getWorkerDescription() const {
    return description;
}

//Other Methods
ostream &operator<<(ostream &out, const Admin &admin) {
    admin.print(out);
    out << setw(4) << left << '|' << "Description: " << admin.description << endl;
    out << "\\_" << endl;
    return out;
}


//CLASS DELIVERYPERSON

Deliveryperson::Deliveryperson(string name, int nif, Date birthdate, double salary, Vehicle vehicle):Worker(name, nif, birthdate, salary) {
    this->vehicle=vehicle;
}

//Metodos Set
void Deliveryperson::setVehicle(Vehicle vehicle) {
    this->vehicle = vehicle;
}

//Metodos Get
Vehicle Deliveryperson::getVehicle() const {
    return vehicle;
}

//Other Methods
ostream &operator<<(ostream &out, const Deliveryperson &deliveryperson) {
    deliveryperson.print(out);
    out << setw(4) << left << '|' << "Vehicle: " << deliveryperson.vehicle << endl;
    out << "\\_" << endl;
    return out;
}

