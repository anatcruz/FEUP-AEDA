#include "Company.h"

Company::Company(string name, Location location, double capital, int nif, string email, string phone,
                 vector<Worker*> workers, vector<Base> bases) {
    this->name=name;
    this->location=location;
    this->capital=capital;
    this->nif=nif;
    this->email=email;
    this->phone=phone;
    this->workers=workers;
    this->bases=bases;
}

void Company::setCompanyName(string name) {
    this->name=name;
}

void Company::setCompanyLocation(Location location) {
    this->location = location;
}

void Company::setCompanyCapital(double capital) {
    this->capital = capital;
}

void Company::setCompanyNif(int nif) {
    this->nif = nif;
}

void Company::setCompanyEmail(string email) {
    this->email = email;
}

void Company::setCompanyPhone(string phone) {
    this->phone = phone;
}

void Company::setCompanyWorkers(vector<Worker*> workers) {
    this->workers = workers;
}

void Company::setCompanyBases(vector<Base> bases) {
    this->bases = bases;
}

//Metodos Get
string Company::getCompanyName() const {
    return name;
}

Location Company::getCompanyLocation() const {
    return location;
}

double Company::getCompanyCapital() const {
    return capital;
}

int Company::getCompanyNif() const {
    return nif;
}

string Company::getCompanyEmail() const {
    return email;
}

string Company::getCompanyPhone() const {
    return phone;
}

vector<Worker*> Company::getCompanyWorkers() const {
    return workers;
}

vector<Base> Company::getCompanyBases() const {
    return bases;
}

//Other Methods

ostream& operator<<(ostream& out, const Company &company){
    out << setw(2) << ' ' << company.name << endl;
    out << "/" << endl;
    out << setw(4) << left << '|' << "Location: " << company.location << endl;
    out << setw(4) << left << '|' << "Capital: " << company.capital << endl;
    out << setw(4) << left << '|' << "NIF: " << company.nif << endl;
    out << setw(4) << left << '|' << "Email: " << company.email << endl;
    out << setw(4) << left << '|' << "Phone Number: " << company.phone << endl;
    out << setw(4) << left << '|' << "Workers: ";
    /*for(int i=0 ; i< company.workers.size() ; i++){
        if (i == company.workers.size() - 1)
            out << company.workers.at(i);
        else
            out << company.workers.at(i);
    }*/
    out << setw(4) << left << '|' << "Bases: ";
    for(int i=0 ; i<company.bases.size() ; i++){
        if (i == company.bases.size() - 1)
            out << company.bases.at(i);
        else
            out << company.bases.at(i);
    }
    out << "\\_" << endl;
    return out;
}

Company::Company(const string fileName){

    //Read from company.txt
    ifstream company_file;
    company_file.open(fileName);

    Address address;
    pair<float,float> coords;
    string str;
    string workersFile;
    string basesFile;

    if (company_file.fail())
    {
        cerr << "Error opening file " << fileName << endl;
        exit(1);
    }

    getline(company_file, name);
    getline(company_file, str);
    address = Address(str);
    getline(company_file, str);
    coords = makeCoords(str);
    location = Location(address, coords);
    getline(company_file, str);
    capital = stod(str);
    getline(company_file,str);
    nif=stoi(str);
    getline(company_file, email);
    getline(company_file, phone);
    getline(company_file, workersFile);
    getline(company_file, basesFile);

    company_file.close();


    //Read from workers.txt
    ifstream workers_file;
    workers_file.open(workersFile);

    if (workers_file.fail())
    {
        cerr << "Error opening file " << fileName << endl;
        exit(1);
    }

    while(getline(workers_file, str)){
        if(str == "Admin"){
            Admin *a = new Admin;
            getline(workers_file, str); //Name
            a->setWorkerName(str);
            getline(workers_file, str); //Nif
            a->setWorkerNif(stoi(str));
            getline(workers_file, str); //Birthdate
            a->setWorkerBirthdate(Date(str));
            getline(workers_file, str); //Salary
            a->setWorkerSalary(stod(str));
            getline(workers_file, str); //Description
            a->setWorkerDescription(str);
            workers.push_back(a);
        }
        else if(str == "Deliveryperson"){
            Deliveryperson *d = new Deliveryperson;
            getline(workers_file, str); //Name
            d->setWorkerName(str);
            getline(workers_file, str); //Nif
            d->setWorkerNif(stoi(str));
            getline(workers_file, str); //Birthdate
            d->setWorkerBirthdate(Date(str));
            getline(workers_file, str); //Salary
            d->setWorkerSalary(stod(str));
            Vehicle v;
            getline(workers_file, str); //Vehicle Manufacturer
            v.setManufacturer(str);
            getline(workers_file, str); //Vehicle Type
            v.setType(str);
            getline(workers_file, str); //Vehicle purchaseDate
            v.setPurchaseDate(Date(str));
            d->setVehicle(v);
            workers.push_back(d);
        }
        getline(workers_file, str); //Discard delimiter
    }

    workers_file.close();


    //Read from bases.txt
    ifstream bases_file;
    bases_file.open(basesFile);

    if(bases_file.fail())
    {
        cerr << "Error opening file " << fileName << endl;
        exit(1);
    }

    while(getline(bases_file, str)){
        Base *b = new Base;
        address = Address(str);
        getline(bases_file, str);
        coords = makeCoords(str);
        b->setBaseLocation(Location(address,coords));
    }
}
