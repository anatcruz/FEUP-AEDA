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

Company::Company(string fileName){
    ifstream company_file;
    company_file.open(fileName);
    string address;
    string coords;
    string str;
    string workersFile;
    string basesFile;

    if (company_file.fail())
    {
        cerr << "Error opening file " << fileName << endl;
        exit(1);
    }

    getline(company_file, name);
    getline(company_file, address);
    getline(company_file, coords);
    location = Location(Address(address),makeCoords(coords));
    getline(company_file, str);
    capital = stod(str);
    getline(company_file,str);
    nif=stoi(str);
    getline(company_file, email);
    getline(company_file, phone);
    getline(company_file, workersFile);
    getline(company_file, basesFile);


}