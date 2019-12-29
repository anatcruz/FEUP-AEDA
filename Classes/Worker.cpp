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
    out << "/" << endl;
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
    admin.print(out);
    out << setw(4) << left << '|' << "Description: " << admin.description << endl;
    out << "\\_" << endl;
    return out;
}


//CLASS DELIVERYPERSON

Deliveryperson::Deliveryperson(string name, int nif, Date birthdate, double salary, Base* base, bool working,  Vehicle vehicle):Worker(name, nif, birthdate, salary, base, working) {
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
    out << setw(4) << left << '|' << "Number of deliveries: " << deliveryperson.getDeliveries().size() << endl;
    out << setw(4) << left << '|' << "Vehicle: " << deliveryperson.vehicle << endl;
    out << "\\_" << endl;
    return out;
}

//CLASS REPAIRMAN
RepairMan::RepairMan(string name, int nif, Date birthdate, double salary, Base *base, bool working, Time became_unavailable_t, Vehicle *vehicle, int num_maintenance, Date became_unavailable_d):Worker(name, nif, birthdate, salary, base, working) {
    this->became_unavailable_t=became_unavailable_t;
    this->vehicle_to_repair=vehicle;
    this->num_maintenance=num_maintenance;
    this->became_unavailable_d=became_unavailable_d;
}

//Metodos Set
void RepairMan::setTime(Time became_unavailable_t) {
    this->became_unavailable_t=became_unavailable_t;
}

void RepairMan::setVehicle(Vehicle *vehicle) {
    this->vehicle_to_repair=vehicle;
}

void RepairMan::setNumMaintenance(int num_maintenance) {
    this->num_maintenance=num_maintenance;
}

void RepairMan::setDate(Date became_unavailable_d) {
    this->became_unavailable_d=became_unavailable_d;
}

//Metodos Get
Time RepairMan::getTime() const {
    return became_unavailable_t;
}

Vehicle *RepairMan::getVehicle() const {
    return vehicle_to_repair;
}

int RepairMan::getNumMaintenance() const {
    return num_maintenance;
}

Date RepairMan::getDate() const {
    return became_unavailable_d;
}

//Other Methods
ostream &operator<<(ostream &out, const RepairMan &repairman) {
    repairman.print(out);
    out << setw(4) << left << '|' << "Date he became unavailable: " << repairman.became_unavailable_d << endl;
    out << setw(4) << left << '|' << "Time he became unavailable: " << repairman.became_unavailable_t << endl;
    out << setw(4) << left << '|' << "Vehicle: " << repairman.vehicle_to_repair << endl;
    out << setw(4) << left << '|' << "Number of maintenance made: " << repairman.num_maintenance << endl;
    out << "\\_" << endl;
    return out;
}

bool RepairMan::isAvailable() {
    time_t now;
    time(&now);
    struct tm* current = localtime(&now);
    Time current_t = Time(current->tm_hour,current->tm_min,current->tm_sec);
    Date current_d = Date(current->tm_mday,current->tm_mon + 1,current->tm_year + 1900);
    Time nedded_time = Time(became_unavailable_t.addtime(240));
    if(became_unavailable_t.getHour() + 4 < 24 ){
        if(current_t > nedded_time || current_t == nedded_time){
            return true;
        }
    }
    else{
        Date nedded_date = Date(became_unavailable_d.addDay());
        if((current_d < nedded_date || current_d == nedded_date) && (current_t > nedded_time || current_t == nedded_time)){
            return true;
        }
    }
    return false;
}

bool RepairMan::operator<(RepairMan &repairman) {
    if(became_unavailable_d == repairman.getDate()){
        return became_unavailable_t < repairman.getTime();
    }
    return became_unavailable_d < repairman.getDate();
}


