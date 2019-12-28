#include "Worker.h"
//CLASS WORKER

Worker::Worker(string name, int nif, Date birthdate, double salary, Base *base) {
    this->name=name;
    this->nif=nif;
    this->birthdate=birthdate;
    this->salary=salary;
    this->base=base;
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

Admin::Admin(string name, int nif, Date birthdate, double salary,Base *base, string description):Worker(name, nif, birthdate, salary,base) {
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

Deliveryperson::Deliveryperson(string name, int nif, Date birthdate, double salary, Base* base, Vehicle vehicle):Worker(name, nif, birthdate, salary, base) {
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

vector<Delivery*> Deliveryperson::getDeliveries() const {
    vector<Order*> base_ords = base->getBaseOrders();
    vector<Delivery*> deliveries;
    for (auto ord : base_ords) {
        if (((Delivery *)ord)->getDeliveryPerson() == nif) {
            deliveries.push_back((Delivery *)ord);
        }
    }
    return deliveries;
}

double Deliveryperson::getDeliveryEarnings() const {
    double earnings = 0;
    for (int i = 0; i < this->getDeliveries().size(); i++) {
        earnings += 2;
    }
    return earnings;
}

//Other Methods
ostream &operator<<(ostream &out, const Deliveryperson &deliveryperson) {
    deliveryperson.print(out);
    out << setw(4) << left << '|' << "Vehicle: " << deliveryperson.vehicle << endl;
    out << "\\_" << endl;
    return out;
}

//CLASS REPAIRMAN
RepairMan::RepairMan(string name, int nif, Date birthdate, double salary, Base *base, Time became_unavailable, Vehicle *vehicle, int num_maintenance) {
    this->name=name;
    this->nif=nif;
    this->birthdate=birthdate;
    this->salary=salary;
    this->base=base;
    this->became_unavailable=became_unavailable;
    this->vehicle_to_repair=vehicle;
    this->num_maintenance=num_maintenance;
}

//Metodos Set
void RepairMan::setTime(Time became_unavailable) {
    this->became_unavailable=became_unavailable;
}

void RepairMan::setVehicle(Vehicle *vehicle) {
    this->vehicle_to_repair=vehicle;
}

void RepairMan::setNumMaintenance(int num_maintenance) {
    this->num_maintenance=num_maintenance;
}

//Metodos Get
Time RepairMan::getTime() const {
    return became_unavailable;
}

Vehicle *RepairMan::getVehicle() const {
    return vehicle_to_repair;
}

int RepairMan::getNumMaintenance() const {
    return num_maintenance;
}

//Other Methods
ostream &operator<<(ostream &out, const RepairMan &repairman) {
    repairman.print(out);
    out << setw(4) << left << '|' << "Time he became unavailable: " << repairman.became_unavailable << endl;
    out << setw(4) << left << '|' << "Vehicle: " << repairman.vehicle_to_repair << endl;
    out << setw(4) << left << '|' << "Number of maintenance made: " << repairman.num_maintenance << endl;
    out << "\\_" << endl;
    return out;
}
