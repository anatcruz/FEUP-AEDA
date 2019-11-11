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

string Company::getCompanyFile() const {
    return companyFile;
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

string Company::filePath = "";

Company::Company(const string &filesPath){
    filePath = filesPath;
    //Read from company.txt
    ifstream company_file;
    company_file.open(filePath + "company.txt");

    companyFile = "company.txt";

    Address address;
    pair<float,float> coords;
    string str;

    if (!company_file.is_open())
    {
        cerr << "Error opening file " << companyFile << endl;
        exit(1);
    }

    getline(company_file, name);
    getline(company_file, str);
    location = Location(str);
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
    workers_file.open(filePath + workersFile);

    if (workers_file.fail())
    {
        cerr << "Error opening file " << filePath + workersFile << endl;
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
    bases_file.open(filePath + basesFile);

    if(!bases_file.is_open())
    {
        cerr << "Error opening file " << filePath + basesFile << endl;
        exit(1);
    }

    while(getline(bases_file, str)){
        Base b;

        b.setBaseLocation(Location(str));   //Base Location
        getline(bases_file, str);
        auto it = find_if(workers.begin(),workers.end(), [=](Worker* w){return w->getWorkerNif() == stoi(str);}); //Get Admin for this base
        b.setBaseManager((Admin*)*(it));

        //Get Clients
        getline(bases_file, str);
        b.setBaseClientsFile(str);
        ifstream clients_file(filePath + str);

        if(!clients_file.is_open())
        {
            cerr << "Error opening file " << filePath + str << endl;
            exit(1);
        }

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
        ifstream restaurants_file(filePath + str);

        if(!restaurants_file.is_open())
        {
            cerr << "Error opening file " << filePath + str << endl;
            exit(1);
        }

        while(getline(restaurants_file, str)){
            Restaurant r;
            r.setRestaurantName(str);   //Name
            getline(restaurants_file, str);
            r.setRestaurantAddress(Address(str));   //Address
            getline(restaurants_file, str);
            r.setRestaurantCuisine(strToVect(str));    //Cuisine
            
            //Get Products
            getline(restaurants_file, str);
            r.setProductsFile(str);
            ifstream products_file(filePath + str);

            if(!products_file.is_open())
            {
                cerr << "Error opening file " << filePath + str << endl;
                exit(1);
            }

            while(getline(products_file, str)){
                Product p;
                p.setProductName(str);
                getline(products_file, str);
                p.setCuisine(str);
                getline(products_file, str);
                p.setPrice(stof(str));
                r.addProductsToRestaurant(p);

                getline(products_file, str); //Discard delimiter
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

Company::~Company() {
    for (int i = 0; i < workers.size(); i++) {
        delete workers.at(i);
    }
}

void updateCompanyFile(Company &company){
    ofstream out_file(company.filePath + company.getCompanyFile());

    out_file<< company.getCompanyName()<<endl;
    out_file<< company.getCompanyLocation() << endl;
    out_file<< company.getCompanyCapital() << endl;
    out_file<< right << setw(9) << setfill('0') << company.getCompanyNif() << endl;
    out_file<< company.getCompanyEmail() << endl;
    out_file<< company.getCompanyPhone() << endl;
    out_file<< company.getCompanyWorkersFile() << endl;
    out_file<<company.getCompanyBasesFile();
    out_file.close();
}

void updateBasesFile(Company &company){
    vector<Base> temp = company.getCompanyBases();
    string file = company.filePath + company.getCompanyBasesFile();
    ofstream out_file(file);

    for(int i = 0; i < temp.size(); i++){
        out_file<<temp.at(i).getBaseLocation() <<endl;
        out_file<<temp.at(i).getBaseManager()->getWorkerNif() <<endl;
        out_file<<temp.at(i).getBaseClientsFile() <<endl;
        out_file<<temp.at(i).getBaseRestaurantsFile() << endl;
        for(int j=0; j<temp.at(i).getBaseMunicipalities().size(); j++){
            if(j==temp.at(i).getBaseMunicipalities().size()-1)
                out_file<<temp.at(i).getBaseMunicipalities().at(j) << endl;
            else
                out_file<<temp.at(i).getBaseMunicipalities().at(j) << ",";
        }
        if(i!=temp.size()-1)
            out_file<<"-----"<<endl;
    }

    out_file.close();
}

/*void updateWorkersFile(Company &company){
    vector<Worker*> temp = company.getCompanyWorkers();
    string file = company.getCompanyWorkersFile();
    ofstream out_file(file);

    for(int i = 0; i < temp.size(); i++){
        out_file<<temp.at(i).get
    }
}*/

void updateClientsFile(Base &base){
    vector<Client> temp = base.getBaseClients();
    string file = Company::filePath + base.getBaseClientsFile();
    ofstream out_file(file);

    for(int i = 0; i < temp.size(); i++){
        out_file<<temp.at(i).getClientName() <<endl;
        out_file<<temp.at(i).getBase()->getBaseLocation()<<endl;
        out_file<<temp.at(i).getClientAddress()<<endl;
        out_file<<temp.at(i).getClientNif()<<endl;
        out_file<<temp.at(i).getBlack_listed()<<endl;
        if(i!=temp.size()-1)
            out_file<<"-----"<<endl;
    }

    out_file.close();
}

void viewClientOrdersHistory(Client &client){
    Base *base = client.getBase();
    for(int i=0;i<base->getBaseRestaurants().size();i++){
        Restaurant r = base->getBaseRestaurants().at(i);
        for(int j=0;j<r.getRestaurantOrders().size();j++){
            Order* o = r.getRestaurantOrders().at(j);
            if(o->getOrderClient()->getClientNif()==client.getClientNif()){
                cout<<o;
            }
        }
    }
}

bool createClientAccount(Company &company, Base &base){
    vector<Client> temp_clients = base.getBaseClients();
    Client new_client;
    string name, str_nif,street_name,door,floor,postcode,municipality;
    Address address;
    unsigned nif;
    bool black_listed;

    while(true){
        cout << "Nif (* - cancel): ";
        getline(cin,str_nif);

        if(validNIF(str_nif)){
            nif = stoi(str_nif);
            break;
        }
        else if(str_nif == "*")
            return false;
        cinERR("ERROR: Invalid NIF, try again!");
    }

    if (searchClientbyNif(nif,temp_clients)){
        cinERR("ERROR: It already exits a client with the given nif!");
        return false;
    }

    new_client.setClientNif(nif);

    cout << "Municipality: ";
    getline(cin,municipality);
    if (find(base.getBaseMunicipalities().begin(), base.getBaseMunicipalities().end(), municipality) !=
        base.getBaseMunicipalities().end()) {
        address.setMunicipality(municipality);
    } else{
        cinERR("ERROR: You cant sign up in this base!");
        return false;
    }

    cout << "Name: (* - cancel): ";
    getline(cin,name);
    if(name == "*")
        return false;
    else
        new_client.setClientName(trim(name));

    cout << "Address: " << endl;
    cout << "-Street name: ";
    getline(cin,street_name);
    address.setStreet(trim(street_name));
    cout << "-Door number: ";
    getline(cin,door);
    address.setDoor(trim(door));
    cout << "-Floor number (- none): ";
    getline(cin,floor);
    address.setFloor(trim(floor));
    while(true){
        cout << "Postcode: ";
        getline(cin,postcode);

        if(validPostcode(trim(postcode)))
            break;

        cinERR("ERROR: Invalid Postcode, try again!");
    }
    address.setPostCode(trim(postcode));
    new_client.setClientAddress(address);
    new_client.setBlack_listed(false);
    temp_clients.push_back(new_client);
    base.setBaseClients(temp_clients);
    return true;
}

bool editClientInfo(Company &company, Client &client){
    Base *current_base = client.getBase();
    Base new_base;
    int opt;
    string new_name,street_name,door,floor,postcode,municipality;
    bool infoChanged=false,changedBase=false;
    Address new_address;
    auto it_client = current_base->getBaseClients().begin();

    for (auto it = current_base->getBaseClients().begin(); it != current_base->getBaseClients().end(); it++ ){
        if((*it) == client)
            it_client = it;
    }

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
                getline(cin,new_name);
                if(new_name == "*")
                    break;
                client.setClientName(trim(new_name));
                infoChanged=true;
                break;
            case 2:
                cout << "Current address: " << client.getClientAddress();
                cout << "New address: " << endl;
                cout << "-Municipality: ";
                getline(cin,municipality);
                if (searchbyMunicipality(municipality,client.getBase()->getBaseMunicipalities())){
                    new_address.setMunicipality(municipality);
                }
                else{
                    cinERR("ERROR: You cant stay in this base!");
                    if (!exitsBase(company.getCompanyBases(),municipality)){
                        cinERR("ERROR: We dont have services for that municipality!");
                        cout << "Changes were undone!";
                        return false;
                    }
                    else{
                        for(int i = 0; i < company.getCompanyBases().size(); i++){
                            if(searchbyMunicipality(municipality, company.getCompanyBases().at(i).getBaseMunicipalities())) {
                                client.setBase(&company.getCompanyBases().at(i));
                                new_address.setMunicipality(municipality);
                                changedBase = true;
                                new_base = company.getCompanyBases().at(i);
                                cout << "You changed for the base: " << new_base.getBaseLocation();
                            }
                        }
                    }
                }
                cout << "-Street name: ";
                getline(cin,street_name);
                new_address.setStreet(trim(street_name));
                cout << "-Door number: ";
                getline(cin,door);
                new_address.setDoor(trim(door));
                cout << "-Floor number (- none): ";
                getline(cin,floor);
                new_address.setFloor(trim(floor));
                while(true){
                    cout << "Postcode: ";
                    getline(cin,postcode);

                    if(validPostcode(trim(postcode)))
                        break;

                    cinERR("ERROR: Invalid Postcode, try again!");
                }
                new_address.setPostCode(trim(postcode));
                infoChanged=true;
                break;

        }

    }while(opt!=0);

    if(changedBase){
        new_base.getBaseClients().push_back(client);
        current_base->getBaseClients().erase(it_client);
    }

    return true;
}

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
