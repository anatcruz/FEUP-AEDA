#include "Worker.h"
//CLASS WORKER

Worker::Worker() {
    name = "";
    nif = 0;
    salary = 0;
    base = nullptr;
}

Worker::Worker(string name, int nif, Date birthdate, double salary, Base *base, bool working) {
    this->name = name;
    this->nif = nif;
    this->birthdate = birthdate;
    this->salary = salary;
    this->base = base;
    this->working = working;
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

void Worker::setWorking(bool working) {
    this->working=working;
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

bool Worker::getWorking() const {
    return working;
}

//Other Methods

void Worker::print(ostream &out) const {
    out << "|" << endl;
    out << setw(4) << left << '|' << "Name: " << name << endl;
    out << setw(4) << left << '|' << "NIF: " << right << setfill('0') << setw(9) << nif << setfill(' ') << endl;
    out << setw(4) << left << '|' << "Birthdate: " << birthdate << endl;
    out << setw(4) << left << '|' << "Salary: " << salary << endl;
    out << setw(4) << left << '|' << "Base: " << base->getBaseLocation() << endl;
    out << setw(4) << left << '|' << "Currently working: " << working << endl;
}

//CLASS ADMIN

Admin::Admin(string name, int nif, Date birthdate, double salary,Base *base, bool working, string description):Worker(name, nif, birthdate, salary,base,working) {
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
    out << setw(4) << left << '/' << "Admin" << endl;
    admin.print(out);
    out << setw(4) << left << '|' << "Description: " << admin.description << endl;
    out << "\\_" << endl;
    return out;
}


//CLASS DELIVERYPERSON

Deliveryperson::Deliveryperson(string name, int nif, Date birthdate, double salary, Base* base, bool working,  string vehicle):Worker(name, nif, birthdate, salary, base, working) {
    this->vehicle=vehicle;
}

//Metodos Set
void Deliveryperson::setVehicle(string vehicle) {
    this->vehicle = vehicle;
}

//Metodos Get
string Deliveryperson::getVehicle() const {
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

bool Deliveryperson::isAvailable() const {
    if (!working) {
        return false;
    }
    vector<Delivery*> deliveries = this->getDeliveries();
    if (deliveries.empty()) {
        return true;
    }
    Time last_delivery = deliveries.back()->getDeliveryTime();
    Time now(time(NULL));
    return (now > last_delivery) && base->isVehicleOperational(vehicle);
}


//Other Methods
ostream &operator<<(ostream &out, const Deliveryperson &deliveryperson) {
    out << setw(4) << left << '/' << "Deliveryperson" << endl;
    deliveryperson.print(out);
    out << setw(4) << left << '|' << "Number of deliveries: " << deliveryperson.getDeliveries().size() << endl;
    out << setw(4) << left << '|' << "Vehicle: " << deliveryperson.vehicle << endl;
    out << setw(4) << left << '|' << "Currently available: " << deliveryperson.isAvailable() << endl;
    out << "\\_" << endl;
    return out;
}

//CLASS REPAIRMAN
RepairMan::RepairMan(string name, int nif, Date birthdate, double salary, Base *base, bool working, Time lastMaintenance, string licence_plate, int num_maintenance):Worker(name, nif, birthdate, salary, base, working) {
    this->lastMaintenance = lastMaintenance;
    this->licence_plate=licence_plate;
    this->num_maintenance=num_maintenance;
}

//Metodos Set
void RepairMan::setTime(Time lastMaintenance) {
    this->lastMaintenance = lastMaintenance;
}

void RepairMan::setLicencePlate(string licence_plate) {
    this->licence_plate=licence_plate;
}

void RepairMan::setNumMaintenance(int num_maintenance) {
    this->num_maintenance=num_maintenance;
}


//Metodos Get
Time RepairMan::getTime() const {
    return lastMaintenance;
}

string RepairMan::getLicencePlate() const {
    return licence_plate;
}

int RepairMan::getNumMaintenance() const {
    return num_maintenance;
}


//Other Methods
ostream &operator<<(ostream &out, const RepairMan &repairman) {
    out << setw(4) << left << '/' << "Repairman" << endl;
    repairman.print(out);
    out << setw(4) << left << '|' << "Last maintenance: " << repairman.lastMaintenance << " - " << repairman.lastMaintenance.getDate() << endl;
    out << setw(4) << left << '|' << "Licence plate of the Vehicle: " << repairman.licence_plate << endl;
    out << setw(4) << left << '|' << "Number of maintenance made: " << repairman.num_maintenance << endl;
    out << "\\_" << endl;
    return out;
}

bool RepairMan::isAvailable() {
    Time maintenance = lastMaintenance;
    return Time(time(NULL)) > maintenance.addtime(240);
}

bool RepairMan::operator<(RepairMan* repairman) {
    if(lastMaintenance == repairman->lastMaintenance){
        return num_maintenance < repairman->num_maintenance;
    }
    return lastMaintenance < repairman->lastMaintenance;
}


