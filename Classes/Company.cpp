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

void Company::setCompanyWorkersFile(string workersFile) {
    this->workersFile=workersFile;
}

void Company::setCompanyBasesFile(string basesFile) {
    this->basesFile=basesFile;
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

string Company::getCompanyWorkersFile() const {
    return workersFile;
}

string Company::getCompanyBasesFile() const {
    return basesFile;
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

/*bool editClientInfo(Client &client){
    int opt;
    string str;
    bool infoChanged=false;
    do{
        cout << "Select which information you want to modify:" << endl;
        cout << "1: Name" << endl;
        cout << "2: Address" << endl;
        cout << "0: Return" << endl;
        getOption(opt);

        switch(opt){
            case 0:
                break;
            case 1:
                cout << "Current Name: " << client.getClientName() << endl;
                cout << "New name (* - cancel): ";
                getline(cin,str);
                if(str=="*")
                    break;
                client.setClientName(trim(str));
                infoChanged=true;
                break;
            case 2:
                cout << "Current address: " << client.getClientAddress();
                cout << "New address (* - cancel): ";
                getline(cin,str);
                if(str=="*")
                    break;
                Address address = Address(trim(str));
        }

    }while(opt!=0);



}*/

bool deleteClientAccount(Client &client){
    string str;
    Base *base = client.getBase();

    cout << "Are you sure you want to delete your account? (Y/N): ";
    while(true){
        try{
            getline(cin, str);
            if(trim(str)=="Y"){
                for (int i=0; i<base->getBaseClients().size(); i++){
                    if(base->getBaseClients().at(i).getClientNif()==client.getClientNif()){
                        base->getBaseClients().erase(base->getBaseClients().begin()+i);
                        break;
                    }
                }
                break;
            }
            else if(trim(str)=="N"){
                cout<<"Account not deleted"<<endl;
                return false;
            }
        }
        catch (invalid_argument){
            cinERR("ERROR: Invalid input, try again! ");
        }
    }


    return true;
}

void updateClientsFile(Base &base){
    vector<Client> temp = base.getBaseClients();
    string file = base.getBaseClientsFile();
    ofstream out_file;

    out_file.open(file);

    for(int i = 0; i < temp.size(); i++){
        out_file<<temp.at(i).getClientName();
        out_file<<temp.at(i).getBase()->getBaseLocation();
        out_file<<temp.at(i).getClientAddress();
        out_file<<temp.at(i).getClientNif();
        out_file<<temp.at(i).getBlack_listed();
        if(i!=temp.size()-1)
            out_file<<"-----"<<endl;
    }
    
    out_file.close();
}

Company::Company(string fileName){

    //Read from company.txt
    ifstream company_file;
    company_file.open(fileName);

    Address address;
    pair<float,float> coords;
    string str;

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
        Base b;

        address = Address(str);
        getline(bases_file, str);
        coords = makeCoords(str);
        b.setBaseLocation(Location(address,coords));   //Base Location
        getline(bases_file, str);
        auto it = find_if(workers.begin(),workers.end(), [=](Worker* w){return w->getWorkerNif() == stoi(str);}); //Get Admin for this base
        b.setBaseManager((Admin*)*(it));

        //Get Clients
        getline(bases_file, str);
        b.setBaseClientsFile(str);
        ifstream clients_file(str);
        while(getline(clients_file, str)){
            Client c;
            c.setClientName(str);   //Client Name
            getline(clients_file, str);
            c.setBase(&b);   //Base
            getline(clients_file, str);
            c.setClientAddress(Address(str));   //Address
            getline(clients_file, str);
            c.setClientNif(stoi(str));  //Nif
            getline(clients_file, str);
            c.setBlack_listed(stoi(str));   //BlackListed

            b.addClientToBase(c);

            getline(clients_file, str); //Discard delimiter
        }
        clients_file.close();

        //Get Restaurants
        getline(bases_file,str);
        b.setBaseRestaurantsFile(str);
        ifstream restaurants_file(str);
        while(getline(restaurants_file, str)){
            Restaurant r;
            r.setRestaurantName(str);   //Name
            getline(restaurants_file, str);
            r.setRestaurantAddress(Address(str));   //Address
            getline(restaurants_file, str);
            r.setRestaurantCuisine(strToVect(str));    //Cuisine
            
            //Get Products
            getline(restaurants_file, str);
            ifstream products_file(str);
            while(getline(products_file, str)){
                Product p;
                p.setProductName(str);
                getline(products_file, str);
                p.setCuisine(str);
                getline(products_file, str);
                p.setPrice(stof(str));
                r.addProductsToRestaurant(p);

                getline(restaurants_file, str); //Discard delimiter
            }
            products_file.close();

            getline(restaurants_file, str);
            r.setRestaurantBase(&b); //Restaurant Base

            b.addRestaurantToBase(r);

            getline(restaurants_file, str); //Discard delimiter
        }
        restaurants_file.close();

        getline(bases_file,str);
        b.setBaseMunicipalities(strToVect(str)); //Base Municipalities

        bases.push_back(b);

        getline(bases_file,str);    //Discard delimiter
    }


    bases_file.close();
}