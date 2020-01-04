#include "Company.h"

string Company::filePath = "";

Company::Company(string name, Location location, double capital, int nif, string email, string phone, vector<Base> bases) {
    this->name=name;
    this->location=location;
    this->capital=capital;
    this->nif=nif;
    this->email=email;
    this->phone=phone;
    this->bases=bases;
}

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
    getline(company_file, basesFile);

    company_file.close();


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
            getline(clients_file, str); //Base
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
            r.setRestaurantCuisine(strToVect(str, ','));    //Cuisine

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

            b.addRestaurantToBase(r);

            getline(restaurants_file, str); //Discard delimiter
        }
        restaurants_file.close();

        //Get workers
        getline(bases_file,str);
        b.setBaseWorkersFile(str);
        ifstream workers_file(filePath + str);

        if (workers_file.fail())
        {
            cerr << "Error opening file " << filePath + str << endl;
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
                getline(workers_file, str); //Working
                a->setWorking(stoi(str));
                getline(workers_file, str); //Description
                a->setWorkerDescription(str);
                b.addWorkerToBase(a);
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
                getline(workers_file, str); //Working
                d->setWorking(stoi(str));
                Vehicle v;
                getline(workers_file, str); //Vehicle Manufacturer
                v.setManufacturer(str);
                getline(workers_file, str); //Vehicle Type
                v.setType(str);
                getline(workers_file, str); //Vehicle License Plate
                v.setLicensePlate(str);
                getline(workers_file, str); //Vehicle purchaseDate
                v.setPurchaseDate(Date(str));
                getline(workers_file, str); //Vehicle Driven Kms
                v.setDrivenKms(stoi(str));
                getline(workers_file, str); //Vehicle Deliveries
                v.setNumDeliveries(stoi(str));
                d->setVehicle(v.getLicensePlate());
                if (d->getWorking()) {
                    b.addVehicle(v);
                }
                b.addWorkerToBase(d);
            }
            else if(str=="Repairman"){
                RepairMan *r = new RepairMan;
                getline(workers_file, str); //Name
                r->setWorkerName(str);
                getline(workers_file, str); //Nif
                r->setWorkerNif(stoi(str));
                getline(workers_file, str); //Birthdate
                r->setWorkerBirthdate(Date(str));
                getline(workers_file, str); //Salary
                r->setWorkerSalary(stod(str));
                getline(workers_file, str); //Working
                r->setWorking(stoi(str));
                Time lastMaintenance;
                getline(workers_file, str); //Unavailable Date
                lastMaintenance.setDate(Date(str));
                getline(workers_file, str); //Unavailable Time
                lastMaintenance.setTime(Time(str));
                r->setTime(lastMaintenance);
                getline(workers_file, str); //Number of maintenance made
                r->setNumMaintenance(stoi(str));
                getline(workers_file, str); // License plate of last maintenance
                r->setLicencePlate(str);
                b.addWorkerToBase(r);
                if(r->getWorking())
                    b.addRepairmanToHeap(r);
            }
            getline(workers_file, str); //Discard delimiter
        }
        workers_file.close();

        //Get Orders
        getline(bases_file, str);
        b.setBaseOrdersFile(str);
        ifstream orders_file(filePath + str);

        if (orders_file.fail())
        {
            cerr << "Error opening file " << filePath + str << endl;
            exit(1);
        }

        vector<Order*> base_ords;
        while (getline(orders_file, str)) {
            Delivery* ord = new Delivery;
            ord->setOrderRestaurant(str);
            getline(orders_file, str);
            ord->setOrderClient(stoi(str));
            Time orderTime;
            getline(orders_file, str);
            orderTime.setDate(Date(str));
            getline(orders_file, str);
            orderTime.setTime(Time(str));
            ord->setOrderTime(orderTime);
            getline(orders_file, str);
            ord->setOrderProducts(strToVect(str,','));
            getline(orders_file,str);
            ord->setOrderPrice(stof(str));
            getline(orders_file, str);
            ord->setDeliveryPrice(stof(str));
            getline(orders_file, str);
            ord->setDeliveryPerson(stoi(str));
            getline(orders_file, str);
            ord->setSuccess(stoi(str));
            Time deliveryTime;
            getline(orders_file, str);
            deliveryTime.setDate(Date(str));
            getline(orders_file, str);
            deliveryTime.setTime(Time(str));
            ord->setDeliveryTime(deliveryTime);
            getline(orders_file, str);
            ord->setDeliveryNotes(str);
            base_ords.push_back(ord);
            getline(orders_file,str); // delimiter
        }

        orders_file.close();

        b.setBaseOrders(base_ords);

        getline(bases_file, str);
        auto admin = b.findWorker(stoi(str)); //Get Admin for this base
        b.setBaseManager((Admin*)admin);

        getline(bases_file,str);
        b.setBaseMunicipalities(strToVect(str, ',')); //Base Municipalities

        bases.push_back(b);

        getline(bases_file,str);    //Discard delimiter
    }

    for (int i = 0; i < bases.size(); i++) {
        for (int j = 0; j < bases.at(i).getBaseClients().size(); j++) {
            bases.at(i).getBaseClientsAddr()->at(j).setBase(&bases.at(i));
        }
        for (int j = 0; j < bases.at(i).getBaseRestaurants().size(); j++) {
            bases.at(i).getBaseRestaurantsAddr()->at(j).setRestaurantBase(&bases.at(i));
        }
        vector<Worker*> workers = bases.at(i).getBaseWorkers();
        for (int j = 0; j < workers.size(); j++) {
            workers.at(j)->setWorkerBase(&bases.at(i));
        }
        bases.at(i).setBaseWorkers(workers);
    }

    bases_file.close();
}

Company::~Company() {
    for (auto base : bases) {
        for (auto worker : *base.getBaseWorkersAddr()) {
            delete worker;
        }
        for (auto order : base.getBaseOrders()) {
            delete order;
        }
    }
}


// Metodos set

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

void Company::setCompanyBases(vector<Base> bases) {
    this->bases = bases;
}

void Company::setCompanyBasesFile(string basesFile) {
    this->basesFile=basesFile;
}


// Metodos Get

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

vector<Base> Company::getCompanyBases() const {
    return bases;
}

vector<Base>* Company::getCompanyBasesAddr() {
    return &bases;
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
    int total_workers = 0;
    for (int i = 0; i < company.bases.size(); i++) {
        total_workers += company.bases.at(i).getBaseWorkers().size();
    }
    out << total_workers << endl;
    out << setw(4) << left << '|' << "Bases: " << company.bases.size() << " bases in";
    for (int i = 0; i < company.bases.size(); i++) {
        if (i != company.bases.size() - 1)
            out << " " << company.bases.at(i).getBaseLocation().getLocationAddress().getMunicipality() << ",";
        else
            out << " and " << company.bases.at(i).getBaseLocation().getLocationAddress().getMunicipality() << endl;
    }
    out << "\\_" << endl;
    return out;
}


// Useful functions

Base* selectBase(Company &company){
    int base_idx;
    vector<Base>* companyBases = company.getCompanyBasesAddr();
    Base* base;

    cout << "Select a base:" << endl;
    for (int i = 0; i < companyBases->size(); i++) {
        cout << i + 1 << ". " << companyBases->at(i).getBaseLocation().getLocationAddress().getMunicipality() << endl;
    }
    cout << "0. Go back" << endl;

    getOption(base_idx, "Base: ");
    if(base_idx==0) {
        cout << "Canceled successfully!" << endl;
        enterWait();
        return nullptr;
    }
    else if(base_idx > 0 && base_idx <= companyBases->size()) {
        base = &companyBases->at(base_idx - 1);
        return base;
    }
    else {
        cinERR("Base does not exist!");
        enterWait();
        return nullptr;
    }
}


// LogIn

Client* clientLogin(Company &company) {
    Base* base = selectBase(company);
    if (base == nullptr) {
        return nullptr;
    }

    int nif;
    if (!inputNIF(nif, "NIF (* - cancel): ")) {
        return nullptr;
    } else {
        auto it = base->findClient(nif);
        if (it != nullptr) {
            if (it->getBlack_listed()) {
                cinERR("YOU HAVE BEEN BLACKLISTED - YOU CANNOT ACCESS OUR SERVICES");
                enterWait();
                return nullptr;
            } else {
                return it;
            }
        } else {
            cinERR("Client does not exist, try again!");
            enterWait();
            return nullptr;
        }
    }
}

Worker* adminLogin(Company &company) {
    Base* base = selectBase(company);
    if (base == nullptr) {
        return nullptr;
    }

    int nif;
    if (!inputNIF(nif, "NIF (* - cancel): ")) {
        return nullptr;
    } else {
        auto it = base->findWorker(nif);
        if (it != nullptr) {
            if (dynamic_cast<Admin*>(it) == 0) {
                cout << "You are not an admin!" << endl;
                enterWait();
                return nullptr;
            } else {
                return it;
            }
        } else {
            cinERR("Worker does not exist, try again!");
            enterWait();
            return nullptr;
        }
    }
}


// File updating

void updateCompanyFile(Company &company){
    ofstream out_file(company.filePath + company.getCompanyFile());

    out_file<< company.getCompanyName()<<endl;
    out_file<< company.getCompanyLocation() << endl;
    out_file<< company.getCompanyCapital() << endl;
    out_file<< right << setw(9) << setfill('0') << company.getCompanyNif() << endl;
    out_file<< company.getCompanyEmail() << endl;
    out_file<< company.getCompanyPhone() << endl;
    out_file<<company.getCompanyBasesFile();
    out_file.close();
}

void updateBasesFile(Company &company){
    vector<Base> temp = company.getCompanyBases();
    string file = company.filePath + company.getCompanyBasesFile();
    ofstream out_file(file);

    for(int i = 0; i < temp.size(); i++){
        out_file<<temp.at(i).getBaseLocation() <<endl;
        out_file<<temp.at(i).getBaseClientsFile() <<endl;
        out_file<<temp.at(i).getBaseRestaurantsFile() << endl;
        out_file<<temp.at(i).getBaseWorkersFile() << endl;
        out_file<<temp.at(i).getBaseOrdersFile() << endl;
        out_file<<temp.at(i).getBaseManager()->getWorkerNif() <<endl;
        for(int j=0; j<temp.at(i).getBaseMunicipalities().size(); j++){
            if(j==temp.at(i).getBaseMunicipalities().size()-1)
                out_file<<temp.at(i).getBaseMunicipalities().at(j);
            else
                out_file<<temp.at(i).getBaseMunicipalities().at(j) << ",";
        }
        if(i!=temp.size()-1)
            out_file<<endl << "-----"<<endl;
    }

    out_file.close();
}

void updateWorkersFile(Base &base){
    vector<Worker*> temp = base.getBaseWorkers();
    string file = Company::filePath + base.getBaseWorkersFile();
    ofstream out_file(file);

    for(int i = 0; i < temp.size(); i++){
        if (dynamic_cast<Admin *> (temp.at(i)) != NULL){
            Admin* a = dynamic_cast<Admin *> (temp.at(i));
            out_file << "Admin" << endl;
            out_file << a->getWorkerName() << endl;
            out_file << a->getWorkerNif() << endl;
            out_file << a->getWorkerBirthdate() << endl;
            out_file << a->getWorkerSalary() << endl;
            out_file << a->getWorking() << endl;
            out_file << a->getWorkerDescription();
        }
        else if(dynamic_cast<Deliveryperson *> (temp.at(i))!=NULL){
            Deliveryperson *d = dynamic_cast<Deliveryperson *> (temp.at(i));
            out_file << "Deliveryperson" << endl;
            out_file << d->getWorkerName() << endl;
            out_file << d->getWorkerNif() << endl;
            out_file << d->getWorkerBirthdate() << endl;
            out_file << d->getWorkerSalary() << endl;
            out_file << d->getWorking() << endl;
            Vehicle v = d->getWorkerBase()->findVehicle(d->getVehicle());
            out_file << v.getManufacturer() << endl;
            out_file << v.getType() << endl;
            out_file << v.getLicensePlate() << endl;
            out_file << v.getPurchaseDate() << endl;
            out_file << v.getDrivenKms() << endl;
            out_file << v.getNumDeliveries();
        }
        else if(dynamic_cast<RepairMan *> (temp.at(i))){
            RepairMan *r = dynamic_cast<RepairMan *> (temp.at(i));
            out_file << "Repairman" << endl;
            out_file << r->getWorkerName() << endl;
            out_file << r->getWorkerNif() << endl;
            out_file << r->getWorkerBirthdate() << endl;
            out_file << r->getWorkerSalary() << endl;
            out_file << r->getWorking() << endl;
            out_file << r->getTime().getDate() << endl;
            out_file << r->getTime() << endl;
            out_file << r->getNumMaintenance() << endl;
            out_file << r->getLicencePlate();
        }
        if(i!=temp.size()-1)
            out_file<<endl << "-----"<<endl;
    }
}

void updateClientsFile(Base &base){
    vector<Client> temp = base.getBaseClients();
    string file = Company::filePath + base.getBaseClientsFile();
    ofstream out_file(file);

    for(int i = 0; i < temp.size(); i++){
        out_file<<temp.at(i).getClientName() <<endl;
        out_file<<base.getBaseLocation().getLocationAddress().getMunicipality()<<endl;
        out_file<<temp.at(i).getClientAddress()<<endl;
        out_file<<temp.at(i).getClientNif()<<endl;
        out_file<<temp.at(i).getBlack_listed();
        if(i!=temp.size()-1)
            out_file<<endl << "-----"<<endl;
    }

    out_file.close();
}

void updateRestaurantsFile(Base &base){
    vector<Restaurant> temp = base.getBaseRestaurants();
    string file = Company::filePath + base.getBaseRestaurantsFile();
    ofstream out_file(file);

    for(int i=0; i<temp.size(); i++){
        out_file<<temp.at(i).getRestaurantName() << endl;
        out_file<<temp.at(i).getRestaurantAddress() << endl;
        for (int j=0; j< temp.at(i).getRestaurantCuisine().size(); j++){
            if (j==temp.at(i).getRestaurantCuisine().size()-1)
                out_file << temp.at(i).getRestaurantCuisine().at(j) << endl;
            else
                out_file << temp.at(i).getRestaurantCuisine().at(j) + ",";
        }
        out_file<<temp.at(i).getProductsFile();
        if(i!=temp.size()-1)
            out_file << endl << "-----"<<endl;
    }
}

void updateProductsFile(Base &base) {
    for (auto rest : base.getBaseRestaurants()) {
        string file = Company::filePath + rest.getProductsFile();
        ofstream prods_file(file);
        vector<Product> prods = rest.getRestaurantProducts();
        for (int i = 0; i < prods.size(); i++) {
            prods_file << prods.at(i).getProductName() << endl;
            prods_file << prods.at(i).getCuisine() << endl;
            prods_file << prods.at(i).getPrice();
            if (i != prods.size() - 1) {
                prods_file << endl << "-----" << endl;
            }
        }
        prods_file.close();
    }
}

void updateOrdersFile(Base &base) {
    vector<Order*> orders = base.getBaseOrders();
    ofstream orders_file(Company::filePath + base.getBaseOrdersFile());
    for (int i = 0; i < orders.size(); i++) {
        Delivery delivery = *(Delivery*)orders.at(i);
        orders_file << delivery.getRestaurant() << endl;
        orders_file << delivery.getOrderClient() << endl;
        orders_file << delivery.getOrderTime().getDate() << endl;
        orders_file << delivery.getOrderTime() << endl;
        for (int j = 0; j < delivery.getOrderProducts().size(); j++) {
            if (j != delivery.getOrderProducts().size() - 1) {
                orders_file << delivery.getOrderProducts().at(j) << ",";
            } else {
                orders_file << delivery.getOrderProducts().at(j) << endl;
            }
        }
        orders_file << delivery.getOrderPrice() << endl;
        orders_file << delivery.getDeliveryPrice() << endl;
        orders_file << delivery.getDeliveryPerson() << endl;
        orders_file << delivery.getSuccess() << endl;
        orders_file << delivery.getDeliveryTime().getDate() << endl;
        orders_file << delivery.getDeliveryTime() << endl;
        orders_file << delivery.getDeliveryNotes();
        if (i != orders.size() - 1) {
            orders_file << endl << "-----" << endl;
        }
    }
    orders_file.close();
}


// Client functions

void viewClientOrdersHistory(Client &client){
    Base *base = client.getBase();
    for(int i = 0; i < base->getBaseOrders().size(); i++){
        if (base->getBaseOrders().at(i)->getOrderClient() ==client.getClientNif()) {
            cout<<*(Delivery*)(base->getBaseOrders().at(i));
        }
    }
    enterWait();
}

bool createClientAccount(Company &company){
    vector<Base> companyBases = company.getCompanyBases();
    Base* base = selectBase(company);
    if (base == nullptr) {
        return false;
    }
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

    if (searchClientbyNif(nif,base->getBaseClients())){
        cinERR("ERROR: It already exits a client with the given nif!");
        enterWait();
        return false;
    }

    new_client.setClientNif(nif);

    cout << "Name: (* - cancel): ";
    getline(cin,name);
    if(name == "*")
        return false;
    else
        new_client.setClientName(trim(name));

    address.makeAddress();
    vector<string> municipalities = base->getBaseMunicipalities();
    if (find(municipalities.begin(), municipalities.end(), address.getMunicipality()) == municipalities.end()) {
        cinERR("ERROR: You cant sign up in this base!");
        enterWait();
        return false;
    }
    new_client.setClientAddress(address);

    new_client.setBlack_listed(false);
    new_client.setBase(base);
    base->getBaseClientsAddr()->push_back(new_client);

    cout << "Account successfully created!" << endl;
    enterWait();
    return true;
}

bool editClientInfo(Company &company, Client &client){
    int opt;
    cout << "Select which information you want to modify:" << endl;
    cout << "1. Name" << endl;
    cout << "2. Address" << endl;
    cout << "0. Go back" << endl;
    getOption(opt);

    switch(opt){
        case 0:
            return false;
        case 1: {
            cout << "Current Name: " << client.getClientName() << endl;
            cout << "New name (* - cancel): ";
            string new_name;
            getline(cin, new_name);
            if (new_name == "*")
                return false;
            client.setClientName(trim(new_name));
            break;
        }
        case 2: {
            cout << "Current address: " << client.getClientAddress() << endl;
            Address new_address;
            new_address.makeAddress();
            if (!searchbyMunicipality(new_address.getMunicipality(),client.getBase()->getBaseMunicipalities())){
                cinERR("ERROR: Your municipality is not reached by this base! "
                       "You must sign up to one of our other bases if it is in their reached areas.");
                cinERR("Changes reverted!");
                enterWait();
                return false;
            }
            client.setClientAddress(new_address);
            break;
        }
        default:
            return false;
    }
    cout << "Information successfully updated!";
    enterWait();
    return true;
}

bool deleteClientAccount(Client* client, Base* base){
    string str;

    cout << "Are you sure you want to delete your account? (Y/N):";
    getline(cin, str);
    if(str == "Y" || str == "y"){
        auto it = find_if(base->getBaseClientsAddr()->begin(), base->getBaseClientsAddr()->end(),
                          [&](Client &c){return c.getClientNif() == client->getClientNif();});
        if (it == base->getBaseClientsAddr()->end()) {
            cout << "Account already deleted!" << endl;
            enterWait();
            return false;
        }
        base->getBaseClientsAddr()->erase(it);
        cout << "We're sad to see you go :( Your account will be deleted. You can still use it until you log out." << endl;
    }
    else {
        cout << "Account not deleted" << endl;
        enterWait();
        return false;
    }
    enterWait();
    return true;
}


// Worker functions

bool hireWorker(Base *base){
    string str;
    int nif, opt;

    if (!inputNIF(nif, "Enter worker's nif (* - cancel): ")) {
        return false;
    }

    Worker* wrk = base->findWorker(nif);

    bool new_hire = true;

    if (wrk != nullptr) {
        if (wrk->getWorking()) {
            cout << "The specified worker is active in the company already." << endl;
            enterWait();
            return false;
        } else {
            cout << "The specified worker is a past member of this base's team!" << endl;
            string type;
            if (dynamic_cast<Admin*>(wrk) != nullptr) {
                type = "Admin";
                opt = 1;
            } else if (dynamic_cast<Deliveryperson*>(wrk) != nullptr) {
                type = "Deliveryperson";
                opt = 2;
            } else if (dynamic_cast<RepairMan*>(wrk) != nullptr) {
                type = "Repairman";
                opt = 3;
            }
            cout << "They were a " << type << ", will they keep their category? (Y/n) ";
            getline(cin, str);
            if (str != "n") {
                new_hire = false;
            }
        }
    }

    /*while (true) {
        cout << "Enter worker's nif (* - cancel): ";
        getline(cin, str_nif);
        if (validNIF(str_nif)) {
            nif = stoi(str_nif);
            break;
        } else if (str_nif == "*") {
            cout << "Canceled successfully!" << endl;
            return false;
        }
        cinERR("ERROR: Invalid NIF, try again!");
    }
    for (int i = 0; i < base->getBaseWorkers().size(); i++) {
        if (base->getBaseWorkers().at(i)->getWorkerNif() == nif) {
            cinERR("ERROR: It already exits a worker with the given nif!");
            enterWait();
            return false;
        }
    }*/

    if (new_hire) {
        cout << "Select job qualifications:" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Deliveryperson" << endl;
        cout << "3. Repairman" << endl;
        getOption(opt);
    }

    switch (opt) {
        case 1: {
            if (!new_hire) {
                wrk->setWorking(true);
                break;
            } else {
                Admin *new_worker = new Admin();
                new_worker->setWorkerNif(nif);
                new_worker->setWorkerBase(base);
                cout << "Name: (* - cancel): ";
                getline(cin, str);
                if (str == "*")
                    return false;
                else
                    new_worker->setWorkerName(trim(str));

                cout << "Birthdate (dd/mm/yyyy): ";
                getline(cin, str);
                if (!validDate(trim(str))) {
                    cinERR("ERROR: Invalid birthdate");
                    enterWait();
                    return false;
                }
                new_worker->setWorkerBirthdate(Date(trim(str)));

                cout << "Base salary: ";
                getline(cin, str);
                if (stod(trim(str)) < 0) {
                    cinERR("ERROR: Invalid salary");
                    enterWait();
                    return false;
                }
                new_worker->setWorkerSalary(stod(trim(str)));

                cout << "Administrator's function description: ";
                getline(cin, str);
                new_worker->setWorkerDescription(trim(str));
                new_worker->setWorking(true);

                base->addWorkerToBase(new_worker);
            }
            break;
        }
        case 2: {
            string brand, type, date, plate;
            if (!new_hire) {
                wrk->setWorking(true);
                cout << "You must update the worker's vehicle." << endl;
                cout << "Deliveryperson vehicle's brand: ";
                getline(cin, brand);
                cout << "Deliveryperson vehicle's type: ";
                getline(cin, type);
                cout << "Deliveryperson vehicle's license plate: ";
                getline(cin, plate);
                if(!validLicensePlate(trim(plate))){
                    cinERR("ERROR: Invalid license plate");
                    enterWait();
                    return false;
                }
                cout << "Deliveryperson vehicle's plate date: ";
                getline(cin, date);
                if(!validDate(trim(date))){
                    cinERR("ERROR: Invalid date");
                    enterWait();
                    return false;
                }
                Vehicle v(trim(brand), trim(type), Date(trim(date)), trim(plate));
                ((Deliveryperson*)wrk)->setVehicle(v.getLicensePlate());
                base->addVehicle(v);
                break;
            }
            Deliveryperson *new_worker = new Deliveryperson();
            new_worker->setWorkerNif(nif);
            new_worker->setWorkerBase(base);
            cout << "Name: (* - cancel): ";
            getline(cin,str);
            if(str == "*")
                return false;
            new_worker->setWorkerName(trim(str));

            cout << "Birthdate (dd/mm/yyyy): ";
            getline(cin, str);
            if(!validDate(trim(str))){
                cinERR("ERROR: Invalid birthdate");
                enterWait();
                return false;
            }
            new_worker->setWorkerBirthdate(Date(trim(str)));

            cout << "Base salary: ";
            getline(cin, str);
            if(stod(trim(str)) < 0){
                cinERR("ERROR: Invalid salary");
                enterWait();
                return false;
            }
            new_worker->setWorkerSalary(stod(trim(str)));

            cout << "Deliveryperson vehicle's brand: ";
            getline(cin, brand);
            cout << "Deliveryperson vehicle's type: ";
            getline(cin, type);
            cout << "Deliveryperson vehicle's license plate: ";
            getline(cin, plate);
            if(!validLicensePlate(trim(plate))){
                cinERR("ERROR: Invalid license plate");
                enterWait();
                return false;
            }
            cout << "Deliveryperson vehicle's plate date: ";
            getline(cin, date);
            if(!validDate(trim(date))){
                cinERR("ERROR: Invalid date");
                enterWait();
                return false;
            }
            Vehicle v(trim(brand), trim(type), Date(trim(date)), trim(plate));
            new_worker->setVehicle(v.getLicensePlate());
            base->addVehicle(v);
            new_worker->setWorking(true);

            base->addWorkerToBase(new_worker);
            break;
        }
        case 3: {
            if (!new_hire) {
                wrk->setWorking(true);
                break;
            }
            RepairMan *new_worker = new RepairMan();
            new_worker->setWorkerNif(nif);
            new_worker->setWorkerBase(base);
            cout << "Name: (* - cancel): ";
            getline(cin,str);
            if(str == "*")
                return false;
            else
                new_worker->setWorkerName(trim(str));

            cout << "Birthdate (dd/mm/yyyy): ";
            getline(cin, str);
            if(!validDate(trim(str))){
                cinERR("ERROR: Invalid birthdate");
                enterWait();
                return false;
            }
            new_worker->setWorkerBirthdate(Date(trim(str)));

            cout << "Base salary: ";
            getline(cin, str);
            if(stod(trim(str)) < 0){
                cinERR("ERROR: Invalid salary");
                enterWait();
                return false;
            }
            new_worker->setWorkerSalary(stod(trim(str)));


            new_worker->setTime(Time(0,0,0));
            new_worker->setNumMaintenance(0);
            new_worker->setWorking(true);

            base->addWorkerToBase(new_worker);
            base->addRepairmanToHeap(new_worker);
            break;
        }
        default: {
            cinERR("ERROR: Invalid job option!");
            enterWait();
            return false;
        }
    }


    cout << "Worker created successfully!" << endl;
    enterWait();
    return true;
}

bool editWorkerInfo(Base *base){
    string str_nif, str;
    int nif, opt;

    while (true) {
        cout << "Enter worker's nif (* - cancel): ";
        getline(cin, str_nif);
        if (validNIF(str_nif)) {
            nif = stoi(str_nif);
            break;
        } else if (str_nif == "*") {
            cout << "Canceled successfully!" << endl;
            return false;
        }
        cinERR("ERROR: Invalid NIF, try again!");
    }
    for (int i = 0; i < base->getBaseWorkers().size(); i++) {
        if (base->getBaseWorkers().at(i)->getWorkerNif() == nif && base->getBaseWorkers().at(i)->getWorking()) {
            Worker* worker = base->getBaseWorkers().at(i);
            if (dynamic_cast<Admin *> (worker)!= NULL) {
                Admin *a = dynamic_cast<Admin *> (worker);
                cout << "Select which admin's information you want to modify:" << endl;
                cout << "1. Name" << endl;
                cout << "2. Salary" << endl;
                cout << "3. Function description" << endl;
                cout << "0. Go back" << endl;
                getOption(opt);
                switch(opt){
                    case 0:
                        return false;
                    case 1:
                        cout << "New name (* - cancel): ";
                        getline(cin,str);
                        if(str == "*")
                            return false;
                        a->setWorkerName(trim(str));
                        break;
                    case 2:
                        cout << "New base salary: ";
                        getline(cin, str);
                        if(stod(trim(str)) < 0){
                            cinERR("ERROR: Invalid salary");
                            enterWait();
                            return false;
                        }
                        a->setWorkerSalary(stod(trim(str)));
                        break;
                    case 3:
                        cout << "New function description: ";
                        getline(cin, str);
                        a->setWorkerDescription(trim(str));
                        break;
                    default:
                        return false;
                }
                cout << "\nInformation successfully updated!" << endl;
                enterWait();
                return true;
            }
            else if (dynamic_cast<Deliveryperson *> (worker)!=NULL){
                Deliveryperson *d = dynamic_cast<Deliveryperson *> (worker);
                cout << "Select which deliveryperson's information you want to modify:" << endl;
                cout << "1. Name" << endl;
                cout << "2. Salary" << endl;
                cout << "0. Go back" << endl;
                getOption(opt);
                switch(opt){
                    case 0:
                        return false;
                    case 1:
                        cout << "New name (* - cancel): ";
                        getline(cin,str);
                        if(str == "*")
                            return false;
                        d->setWorkerName(trim(str));
                        break;
                    case 2:
                        cout << "New base salary: ";
                        getline(cin, str);
                        if(stod(trim(str)) < 0){
                            cinERR("ERROR: Invalid salary");
                            enterWait();
                            return false;
                        }
                        d->setWorkerSalary(stod(trim(str)));
                        break;
                    default:
                        return false;
                    }
                cout << "\nInformation successfully updated!" << endl;
                enterWait();
                return true;
            }
            else if(dynamic_cast<RepairMan*>(worker)!=NULL){
                RepairMan* r = dynamic_cast<RepairMan*>(worker);
                cout << "Select which admin's information you want to modify:" << endl;
                cout << "1. Name" << endl;
                cout << "2. Salary" << endl;
                cout << "0. Go back" << endl;
                getOption(opt);
                switch(opt){
                    case 0:
                        return false;
                    case 1:
                        cout << "New name (* - cancel): ";
                        getline(cin,str);
                        if(str == "*")
                            return false;
                        r->setWorkerName(trim(str));
                        break;
                    case 2:
                        cout << "New base salary: ";
                        getline(cin, str);
                        if(stod(trim(str)) < 0){
                            cinERR("ERROR: Invalid salary");
                            enterWait();
                            return false;
                        }
                        r->setWorkerSalary(stod(trim(str)));
                        break;
                    default:
                        return false;
                }
                cout << "\nInformation successfully updated!" << endl;
                enterWait();
                return true;
            }
        }
    }
    cinERR("ERROR: No active worker in this base with the given nif!");
    enterWait();
    return false;

}

bool fireWorker(Base *base){
    string str_nif, str;
    int nif, opt;

    if (!inputNIF(nif, "Enter worker's nif (* - cancel): ")) {
        return false;
    }

    if (nif == base->getBaseManager()->getWorkerNif()) {
        cinERR("ERROR: Can't fire base manager");
        enterWait();
        return false;
    } else {
        if (base->removeWorker(nif)){
            cout << "Worker successfully fired" << endl;
            enterWait();
            return true;
        }
        return false;
    }
}


//Restaurant Functions

bool addRestaurant(Base* base){
    Restaurant new_rest;
    if (new_rest.makeRestaurant(base)) {
        base->getBaseRestaurantsAddr()->push_back(new_rest);
        cout << "Restaurant successfully created!" << endl;
        enterWait();
        return true;
    } else {
        return false;
    }
}

bool removeRestaurant(Base* base){
    string str,restaurant;

    cout << "Enter restaurant's name (* - cancel): " ;
    getline(cin,str);
    restaurant=trim(str);
    if(restaurant=="*"){
        cout<<"Canceled successfully!"<<endl;
        return false;
    }

    auto it = find_if(base->getBaseRestaurantsAddr()->begin(),base->getBaseRestaurantsAddr()->end(),[&](Restaurant &rest){return rest.getRestaurantName() == restaurant;});
    if (it != base->getBaseRestaurantsAddr()->end()){
        cout << "Are you sure you want to remove this restaurant? (Y/N): ";
        getline(cin, str);
        if(str == "Y" || str == "y"){
            string prods_file = Company::filePath + (*it).getProductsFile();
            remove(prods_file.c_str());
            base->getBaseRestaurantsAddr()->erase(it);
            cout << "Restaurant successfully removed" << endl;
            enterWait();
            return true;
        }
        else {
            cout << "Restaurant not removed" << endl;
            enterWait();
            return false;
        }
    }
    cinERR("ERROR: Restaurant with given name does not exist!");
    enterWait();
    return false;
}

bool addProduct(Base* base) {
    string str;

    cout << "Restaurant to add product to: ";
    getline(cin, str);
    str = trim(str);

    auto rest_it = find_if(base->getBaseRestaurantsAddr()->begin(), base->getBaseRestaurantsAddr()->end(), [&](Restaurant &r){ return r.getRestaurantName() == str;});
    if (rest_it == base->getBaseRestaurantsAddr()->end()) {
        cinERR("No restaurant with given name in this base!");
        enterWait();
        return false;
    }

    Product product;
    product.makeProduct();

    (*rest_it).addProductsToRestaurant(product);

    cout << "Product successfully added!" << endl;
    enterWait();
    return true;
}

bool removeProduct(Base* base) {
    string str;

    cout << "Restaurant to remove product from: ";
    getline(cin, str);
    str = trim(str);

    auto rest_it = find_if(base->getBaseRestaurantsAddr()->begin(), base->getBaseRestaurantsAddr()->end(), [&](Restaurant &r){ return r.getRestaurantName() == str;});
    if (rest_it == base->getBaseRestaurantsAddr()->end()) {
        cinERR("No restaurant with given name in this base!");
        enterWait();
        return false;
    }

    cout << "Product name to remove: ";
    getline(cin, str);
    str = trim(str);

    if (!rest_it->removeProduct(str)) {
        cout << "Product does not exist!" << endl;
        enterWait();
        return false;
    }

    cout << "Product removed successfully!" << endl;
    enterWait();
    return true;
}



// Order functions

bool makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base){
    int opt;
    string satisfied, notes;
    bool success;
    vector<string> products_ordered;
    float order_price = 0, delivery_price = 0;
    Delivery* new_delivery = new Delivery;
    int deliveryperson;
    Time delivery_time;

    new_delivery->setOrderTime(Time(time(NULL)));

    cout << endl << "Choose the products you want" << endl;
    cout << "Products: " << endl;
    for (int i = 0; i < restaurant->getRestaurantProducts().size(); i++){
        cout << i+1 << ". " << restaurant->getRestaurantProducts().at(i) << endl;
    }
    cout << endl << "0 - finish/cancel order" << endl;
    while (true) {
        getOption(opt);
        if (opt == 0 && products_ordered.empty()) { // Canceled order
            cout << "Canceled!" << endl;
            enterWait();
            return false;
        } else if (opt == 0) { // Finish order
            break;
        } else if(opt>0 && opt<=restaurant->getRestaurantProducts().size()){ // Add products to order
            products_ordered.push_back(restaurant->getRestaurantProducts().at(opt-1).getProductName());
            order_price += restaurant->getRestaurantProducts().at(opt-1).getPrice();
        }
        else {
            cout << "ERROR: Invalid product choice!Try again: ";
        }
    }

    cout << "Notes for delivery: ";
    getline(cin, notes);
    new_delivery->setDeliveryNotes(notes);

    cout << "...Processing your order..." << endl;

    //criar a nova encomenda
    new_delivery->setOrderPrice(order_price);
    new_delivery->setOrderProducts(products_ordered);
    new_delivery->setOrderRestaurant(restaurant->getRestaurantName());
    new_delivery->setOrderClient(client.getClientNif());

    //criar a entrega
    if(restaurant->getRestaurantAddress().getMunicipality() == client.getClientAddress().getMunicipality())
        delivery_price = order_price + 3;
    else
        delivery_price = order_price + 5;

    new_delivery->setDeliveryPrice(delivery_price);

    deliveryperson = base->assignDelivery(new_delivery->getOrderTime(), delivery_time);

    if (deliveryperson == -1) {
        cout << "We are not able to deliver your order at this time" << endl
        << "Please try again in a few moments. We apologize for the inconvenience" << endl;
        enterWait();
        return false;
    }

    new_delivery->setDeliveryPerson(deliveryperson);

    new_delivery->setDeliveryTime(delivery_time);

    cout << base->findWorker(deliveryperson)->getWorkerName() << " will deliver your order at " << delivery_time << endl;
    cout << "Are you satisfied with your order (Y/N)? ";
    getline(cin,satisfied);
    success = (satisfied == "Y" || satisfied == "y");
    new_delivery->setSuccess(success);

    //acrescentar ao vetor de orders da base
    base->addOrderToBase(new_delivery);

    cout << "Thank you for using our services!" << endl;

    return true;
}

bool makeOrderDelivery(Client &client, Restaurant *restaurant, Base *base, vector<Product> product_options){
    int opt;
    string satisfied, notes;
    bool success;
    vector<string> products_ordered;
    float order_price = 0, delivery_price = 0;
    Delivery* new_delivery = new Delivery;
    int deliveryperson;
    Time delivery_time;


    new_delivery->setOrderTime(Time(time(NULL)));

    cout << endl << "Choose the products you want" << endl;
    cout << "Products: " << endl;
    for (int i = 0; i < product_options.size(); i++){
        cout << i+1 << ". " << product_options.at(i) << endl;
    }
    cout << endl << "0 - finish/cancel order" << endl;
    while (true) {
        getOption(opt);
        if (opt == 0 && products_ordered.empty()) { // Canceled order
            cout << "Canceled!";
            enterWait();
            return false;
        } else if (opt == 0) { // Finish order
            break;
        } else if(opt>0 && opt<=product_options.size()){ // Add products to order
            products_ordered.push_back(product_options.at(opt-1).getProductName());
            order_price += product_options.at(opt-1).getPrice();
        }
        else {
            cout << "ERROR: Invalid product choice!Try again: ";
        }
    }

    cout << "Notes for delivery: ";
    getline(cin, notes);
    new_delivery->setDeliveryNotes(notes);

    cout << "...Processing your order..." << endl;

    //criar a nova encomenda
    new_delivery->setOrderPrice(order_price);
    new_delivery->setOrderProducts(products_ordered);
    new_delivery->setOrderRestaurant(restaurant->getRestaurantName());
    new_delivery->setOrderClient(client.getClientNif());

    //criar a entrega
    if(restaurant->getRestaurantAddress().getMunicipality() == client.getClientAddress().getMunicipality())
        delivery_price = order_price + 3;
    else
        delivery_price = order_price + 5;

    new_delivery->setDeliveryPrice(delivery_price);

    deliveryperson = base->assignDelivery(new_delivery->getOrderTime(), delivery_time);

    if (deliveryperson == -1) {
        cout << "We are not able to deliver your order at this time" << endl
             << "Please try again in a few moments. We apologize for the inconvenience" << endl;
        enterWait();
        return false;
    }

    new_delivery->setDeliveryPerson(deliveryperson);
    new_delivery->setDeliveryTime(delivery_time);


    cout << base->findWorker(deliveryperson)->getWorkerName() << " will deliver your order at " << delivery_time << endl;
    cout << "Are you satisfied with your order(Y/N)? ";
    getline(cin,satisfied);
    success = (satisfied == "Y" || satisfied == "y");
    new_delivery->setSuccess(success);

    //acrescentar ao vetor de orders da base
    base->addOrderToBase(new_delivery);

    cout << "Thank you for using our services!" << endl;

    return true;
}

bool makeOrderDeliveryByRestaurant(Client &client, Base *base){
    string restaurant_name;

    cout << "Enter the restaurant you want to order from: ";
    getline(cin,restaurant_name);

    Restaurant* restaurant = base->getRestaurant(restaurant_name);

    if(restaurant == nullptr){
        cinERR("ERROR: That restaurant does not exist in your base! Cant make order!");
        enterWait();
        return false;
    }
    else{
        return makeOrderDelivery(client,restaurant,base);
    }
}

bool makeOrderDeliveryByMunicipality(Client &client, Base *base){
    string str, municipality;
    int opt;

    cout << "Enter the municipality you want to order from: ";
    getline(cin, str);
    municipality = trim(str);
    if(!searchbyMunicipality(municipality,base->getBaseMunicipalities())){
        cinERR("ERROR: We don't have services for that municipality! Can't make order");
        return false;
    }
    else{
        vector<string> municipality_rest;
        for(int i=0;i<base->getBaseRestaurants().size();i++){
            if(base->getBaseRestaurants().at(i).getRestaurantAddress().getMunicipality() == municipality){
                municipality_rest.push_back(base->getBaseRestaurants().at(i).getRestaurantName());
                cout <<  municipality_rest.size() << ": " << base->getBaseRestaurants().at(i) << endl;
            }
        }
        cout << endl << "0 - cancel order" << endl;

        while(true){
            getOption(opt);
            if(opt > 0 && opt <= municipality_rest.size()){
                Restaurant* ord_rest = base->getRestaurant(municipality_rest.at(opt - 1));
                return makeOrderDelivery(client,ord_rest,base);
            }
            else if(opt==0){
                cout << "Order canceled successfully" << endl;
                return false;
            }
            else{
                cout << "ERROR: Invalid restaurant choice! Try again: ";
            }
        }
    }
}

bool makeOrderDeliveryByPrice(Client &client, Base *base)   {
    string price;
    float limit_price = 0;
    float order_price = 0;
    bool success;
    map<string, vector<Product>> select_products;
    vector<Product> product_options;
    int opt;
    Restaurant selected_restaurant;

    //preço limite dado pelo utilizador
    cout << "What is the limit price of the product?" << endl;
    cout << "Price: ";
    getline(cin,price);
    limit_price = stof(price);

    //vetor com todos os produtos de todos os restaurantes com aquele limite
    for (auto rest : base->getBaseRestaurants()){
        vector<Product> prod_vect;
        select_products[rest.getRestaurantName()] = prod_vect;
        for (auto prod : rest.getRestaurantProducts()){
            if (prod.getPrice() <= limit_price)
                select_products[rest.getRestaurantName()].push_back(prod);
        }
    }

    //escolha do restaurante
    cout << endl << "Choose the restaurant you want" << endl;

    int cnt = 1;
    vector<string> restaurant_selector;
    for (auto p_rp : select_products){
        if (!select_products[p_rp.first].empty()){
            cout << endl << cnt << ". " <<  *(base->getRestaurant(p_rp.first)) << endl;
            restaurant_selector.push_back(p_rp.first);
            for (auto prod : p_rp.second) {
                cout << "|  - " << prod << endl;
            }
            cnt++;
        }
    }

    cout << endl << "0 - cancel order" << endl;

    while (true) {
        getOption(opt);
        if (opt == 0) { // Canceled order
            cout << "Canceled!" << endl;
            enterWait();
            return false;
        } else if(opt > 0 && opt <= restaurant_selector.size()){ // Add products to order
            product_options = select_products[restaurant_selector.at(opt - 1)];
            return makeOrderDelivery(client, base->getRestaurant(restaurant_selector.at(opt - 1)), base, product_options);
        }
        else {
            cout << "ERROR: Invalid restaurant choice! Try again: ";
        }
    }
}

bool makeOrderDeliveryByCuisine(Client &client, Base *base){
    string user_cuisine;
    vector<Restaurant> restaurants_available;
    int opt;
    Restaurant choosen_restaurant;
    //vector<Product> selected_products;

    cout << "What type of food are you looking for?" << endl;
    getline(cin,user_cuisine);

    for(auto rest : base->getBaseRestaurants()){
        vector<string> cuisines = rest.getRestaurantCuisine();
        auto it = find_if(cuisines.begin(), cuisines.end(), [&](string &cus){return cus == user_cuisine;});
        if (it != cuisines.end()) {
            restaurants_available.push_back(rest);
        }
    }

    if (restaurants_available.empty()) {
        cout << "There is no restaurant with that type of food in your base!" << endl;
        enterWait();
        return false;
    }

    cout << "These are the restaurants with that type of food:" << endl;
    for (int i = 0; i < restaurants_available.size(); i++){
        cout << i+1 << ": " << restaurants_available.at(i) << endl;
    }
    cout << "0 - finish/cancel order" << endl;

    do{
        getOption(opt);
        if(opt>0 && opt<=restaurants_available.size()){
            choosen_restaurant = restaurants_available.at(opt-1);
            return makeOrderDelivery(client,base->getRestaurant(choosen_restaurant.getRestaurantName()),base);
        } else if(opt == 0){
            cout << "Your order was canceled!" << endl;
            enterWait();
            return false;
        } else {
            cout << "ERROR: Invalid restaurant choice!Try again: ";
        }
    }while(opt != 0);
    return true;
}

bool makeOrderDeliveryAll(Client &client, Base *base) {
    int opt;
    int cnt = 1;
    vector<Restaurant> restaurants = base->getBaseRestaurants();
    for (auto rest : restaurants) {
        cout <<  cnt << ": " << rest << endl;
        cnt++;
    }
    cout << endl << "0 - cancel order" << endl;

    while(true){
        getOption(opt);
        if(opt > 0 && opt <= restaurants.size()){
            Restaurant* ord_rest = base->getRestaurant(restaurants.at(opt - 1).getRestaurantName());
            return makeOrderDelivery(client,ord_rest,base);
        }
        else if(opt==0){
            cout << "Order canceled successfully" << endl;
            return false;
        }
        else{
            cout << "ERROR: Invalid restaurant choice! Try again: ";
        }
    }
}


// Show client functions

void showAllClients(Company &company){
    cout << "-----All Clients' Information-----\n"<<endl;
    for(int i=0;i<company.getCompanyBases().size();i++){
        for(int j=0; j<company.getCompanyBases().at(i).getBaseClients().size();j++){
            cout<<company.getCompanyBases().at(i).getBaseClients().at(j) << endl;
        }
    }
    enterWait();
}

void showClientsByBase(Company &company){
    Base* base = selectBase(company);
    if(base!= nullptr){
        vector<Client> clients = base->getBaseClients();
        for (int i=0; i<clients.size(); i++){
            cout << clients.at(i);
        }
    }
    enterWait();
}

void showSpecificClient(Company &company){
    string str_nif;
    int nif;
    Base* base = selectBase(company);

    if(base!= nullptr){
        vector<Client> clients = base->getBaseClients();
        while(true){
            cout << "Enter client's nif (* - cancel): ";
            getline(cin,str_nif);
            if(validNIF(str_nif)){
                nif = stoi(str_nif);
                break;
            }
            else if(str_nif == "*"){
                cout<<"Canceled successfully!"<<endl;
                return;
            }
            cinERR("ERROR: Invalid NIF, try again!");
        }
        auto it = find_if(clients.begin(),clients.end(),[&](Client client){return client.getClientNif() == nif;});
        if (it != clients.end()){
            cout << *it;
            enterWait();
            return;
        }
        cinERR("ERROR: Client with given nif does not exist!");
        enterWait();
    }
}


// Show restaurant functions

void showAllRestaurants(Company &company){
    cout << "-----All Restaurants' Information-----" << endl;
    for(int i=0;i<company.getCompanyBases().size();i++){
        for(int j=0;j<company.getCompanyBases().at(i).getBaseRestaurants().size();j++){
            cout << company.getCompanyBases().at(i).getBaseRestaurants().at(j) << endl;
        }
    }
    enterWait();
}

void showRestaurantsByBase(Company &company){
    Base* base = selectBase(company);
    if(base!= nullptr){
        vector<Restaurant> restaurants = base->getBaseRestaurants();
        for (int i=0; i<restaurants.size(); i++){
            cout << restaurants.at(i);
        }
    }
    enterWait();
}

void showSpecificRestaurant(Company &company){
    string str,restaurant;
    Base* base = selectBase(company);

    if(base!= nullptr){
        vector<Restaurant> restaurants = base->getBaseRestaurants();
        cout << "Enter restaurant's name (* - cancel): " ;
        getline(cin,restaurant);
        //restaurant=trim(str);
        if(restaurant=="*"){
            cout<<"Canceled successfully!"<<endl;
            return;
        }

        auto it = find_if(restaurants.begin(),restaurants.end(),[&](Restaurant rest){return rest.getRestaurantName() == restaurant;});
        if (it != restaurants.end()){
            cout << *it;
            enterWait();
            return;
        }
        cinERR("ERROR: Restaurant with given name does not exist!");
        enterWait();
    }
}


// Show products functions

void showAllProducts(Base* base) {
    for (auto rest : base->getBaseRestaurants()) {
        cout << endl << rest.getRestaurantName() << endl;
        for (auto prod : rest.getRestaurantProducts()) {
            cout << "-" << prod << endl;
        }
    }
    enterWait();
}

void showProductsByRestaurant(Base* base) {
    string str;

    cout << "Restaurant name: ";
    getline(cin, str);
    str = trim(str);

    auto it = find_if(base->getBaseRestaurantsAddr()->begin(), base->getBaseRestaurantsAddr()->end(), [&](Restaurant &r){ return r.getRestaurantName() == str;});
    if (it == base->getBaseRestaurantsAddr()->end()) {
        cinERR("No restaurant with given name in this base!");
        enterWait();
        return;
    }

    for (auto ord : it->getRestaurantOrders()) {
        cout << it->getRestaurantName() << endl;
        for (auto prod : it->getRestaurantProducts()) {
            cout << "-" << prod << endl;
        }
    }

    enterWait();
}

void showProductsByCuisine(Base* base) {
    string str;
    bool found = false;

    cout << "Cuisine: ";
    getline(cin,str);
    str = trim(str);

    for(auto rest : base->getBaseRestaurants()){
        vector<string> cuisines = rest.getRestaurantCuisine();
        auto it = find_if(cuisines.begin(), cuisines.end(), [&](string &cus){return cus == str;});
        if (it != cuisines.end()) {
            found = true;
            cout << rest.getRestaurantName() << endl;
            for (auto prod : rest.getRestaurantProducts()) {
                if (prod.getCuisine() == str) {
                    cout << "-" << prod << endl;
                }
            }
        }

    }

    if (!found) {
        cout << "There is no restaurant with that type of food in your base!" << endl;
        enterWait();
        return;
    }

    enterWait();
}


// Show workers functions

void showWorkers(Base* base) {
    for (auto worker : base->getBaseWorkers()) {
        if (dynamic_cast<Admin *>(worker) != 0) {
            cout << *(Admin *)(worker);
        }
        else if (dynamic_cast<Deliveryperson*>(worker) != 0){
            cout << *(Deliveryperson *)(worker);
        }
        else if(dynamic_cast<RepairMan*>(worker) != 0){
            cout << *(RepairMan *)(worker);
        }
    }
    enterWait();
}

void showAdmins(Base* base){
    for (auto worker : base->getBaseWorkers()) {
        if(worker->getWorking()){
            if (dynamic_cast<Admin *>(worker) != 0) {
                cout << *(Admin *) (worker);
            }
        }
    }
    enterWait();
}

void showDeliverypersons(Base *base){
    for (auto worker : base->getBaseWorkers()) {
        if(worker->getWorking()){
            if (dynamic_cast<Deliveryperson *>(worker) != 0){
                cout << *(Deliveryperson *)(worker);
            }
        }
    }
    enterWait();
}

void showRepairman(Base *base){
    for (auto worker : base->getBaseWorkers()) {
        if(worker->getWorking()){
            if (dynamic_cast<RepairMan *>(worker) != 0){
                cout << *(RepairMan *)(worker);
            }
        }
    }
    enterWait();
}

void showSpecificWorker(Base *base){
    string str_nif, str;
    int nif, opt;

    while (true) {
        cout << "Enter worker's nif (* - cancel): ";
        getline(cin, str_nif);
        if (validNIF(str_nif)) {
            nif = stoi(str_nif);
            break;
        } else if (str_nif == "*") {
            cout << "Canceled successfully!" << endl;
            return;
        }
        cinERR("ERROR: Invalid NIF, try again!");
    }

    for (int i = 0; i < base->getBaseWorkers().size(); i++) {
        if (base->getBaseWorkers().at(i)->getWorkerNif() == nif) {
            Worker *worker = base->getBaseWorkers().at(i);
            if (dynamic_cast<Admin *>(worker) != 0) {
                cout << *(Admin *)(worker);
                enterWait();
                return;
            }
            else if (dynamic_cast<Deliveryperson*>(worker) != 0){
                cout << *(Deliveryperson *)(worker);
                enterWait();
                return;
            }
            else if(dynamic_cast<RepairMan*>(worker) != 0){
                cout << *(RepairMan *)(worker);
                enterWait();
                return;
            }
        }
    }
    cinERR("ERROR: No worker in this base with the given nif!");
    enterWait();
}

void showActiveWorkers(Base *base){
    for (auto worker : base->getBaseWorkers()) {
        if(worker->getWorking()){
            if (dynamic_cast<Admin *>(worker) != 0) {
                cout << *(Admin *)(worker);
            }
            else if (dynamic_cast<Deliveryperson*>(worker) != 0){
                cout << *(Deliveryperson *)(worker);
            }
            else if(dynamic_cast<RepairMan*>(worker) != 0){
                cout << *(RepairMan *)(worker);
            }
        }
    }
    enterWait();
}

void showOldWorkers(Base *base){
    for (auto worker : base->getBaseWorkers()) {
        if(!worker->getWorking()){
            if (dynamic_cast<Admin *>(worker) != 0) {
                cout << *(Admin *)(worker);
            }
            else if (dynamic_cast<Deliveryperson*>(worker) != 0){
                cout << *(Deliveryperson *)(worker);
            }
            else if(dynamic_cast<RepairMan*>(worker) != 0){
                cout << *(RepairMan *)(worker);
            }
        }
    }
    enterWait();
}


// Show orders functions

void showBaseOrders(Base* base){
    if(base!= nullptr) {
        for (int i= 0; i<base->getBaseOrders().size() ; i++) {
            cout << *(Delivery *)(base->getBaseOrders().at(i)) << endl;
        }
    }
    enterWait();
}

void showSpecificRestaurantsOrders(Base* base){
    string str,restaurant;
    vector<Restaurant> restaurants = base->getBaseRestaurants();

    cout << "Enter restaurant's name (* - cancel): " ;
    getline(cin,str);
    restaurant = trim(str);
    if(restaurant=="*"){
        cout<<"Canceled successfully!"<<endl;
        return;
    }

    auto it = find_if(restaurants.begin(),restaurants.end(),[&](Restaurant &rest){return rest.getRestaurantName() == restaurant;});
    if (it != restaurants.end()){
        for(int i=0; i < base->getBaseOrders().size();i++){
            if(base->getBaseOrders().at(i)->getRestaurant() == restaurant)
                cout << *(Delivery *)(base->getBaseOrders().at(i)) << endl;
        }
        enterWait();
        return;
    }
    cinERR("ERROR: Restaurant with given name does not exist!");
    enterWait();
}

void showSpecificClientOrders(Base* base){
    string str_nif;
    int nif;
    vector<Client> clients = base->getBaseClients();

    while (true) {
        cout << "Enter client's nif (* - cancel): ";
        getline(cin, str_nif);
        if (validNIF(str_nif)) {
            nif = stoi(str_nif);
            break;
        } else if (str_nif == "*") {
            cout << "Canceled successfully!" << endl;
            return;
        }
        cinERR("ERROR: Invalid NIF, try again!");
    }

    auto it = find_if(clients.begin(), clients.end(), [&](Client client) { return client.getClientNif() == nif; });
    if (it == clients.end()) {
        cinERR("ERROR: Client with given nif does not exist!");
        enterWait();
        return;
    }

    viewClientOrdersHistory(*it);
}


//Show vehicles functions

void showBaseVehicles(Base* base) {
    BSTItrIn<Vehicle> it(base->getBaseVehicles());
    int cnt = 0;
    while(!it.isAtEnd()){
        cout << it.retrieve() << endl;
        cnt++;
        it.advance();
    }
    if (cnt == 0) {
        cout << "No vehicles in the base!" << endl;
    }
    cout << endl;
    enterWait();
}

void showVehiclesUnderMaintenance(Base* base) {
    BSTItrIn<Vehicle> it(base->getBaseVehicles());
    int cnt = 0;
    while(!it.isAtEnd()){
        if (!base->isVehicleOperational(it.retrieve())) {
            cout << it.retrieve() << endl;
            cnt++;
        }
        it.advance();
    }
    if (cnt == 0) {
        cout << "No vehicles under maintenance or fulfilling orders right now!" << endl;
    }
    cout << endl;
    enterWait();
}

void showAvailableVehicles(Base* base) {
    BSTItrIn<Vehicle> it(base->getBaseVehicles());
    int cnt = 0;
    while(!it.isAtEnd()){
        if (base->isVehicleOperational(it.retrieve())) {
            cout << it.retrieve() << endl;
            cnt++;
        }
        it.advance();
    }
    if (cnt == 0) {
        cout << "No available vehicles right now!" << endl;
    }
    cout << endl;
    enterWait();
}

void showSpecificVehicle(Base* base){
    BSTItrIn<Vehicle> it(base->getBaseVehicles());
    string plate;
    cout << "Enter vehicles's license plate (* - cancel): " ;
    getline(cin,plate);
    plate=trim(plate);
    while(!validLicensePlate(plate)){
        if(plate=="*") {
            cout << "Canceled successfully!" << endl << endl;
            return;
        }
        cinERR("ERROR: Invalid license plate! Try again: ");
        getline(cin, plate);
    }
    plate=trim(plate);
    while(!it.isAtEnd()){
        if (it.retrieve().getLicensePlate()==trim(plate)) {
            cout << it.retrieve() << endl;
            enterWait();
            return;
        }
        it.advance();
    }
    cout << "No vehicle with given license plate" << endl << endl;
    enterWait();
}

bool changeDeliveryPersonVehicle(Base* base){
    string str_nif, str;
    int nif, opt;

    while (true) {
        cout << "Enter worker's nif (* - cancel): ";
        getline(cin, str_nif);
        if (validNIF(str_nif)) {
            nif = stoi(str_nif);
            break;
        } else if (str_nif == "*") {
            cout << "Canceled successfully!" << endl;
            return false;
        }
        cinERR("ERROR: Invalid NIF, try again!");
    }
    for (int i = 0; i < base->getBaseWorkers().size(); i++) {
        if (base->getBaseWorkers().at(i)->getWorkerNif() == nif) {
            Worker *worker = base->getBaseWorkers().at(i);
            Deliveryperson *d = dynamic_cast<Deliveryperson *> (worker);
            if (d != NULL) {
                string brand, type, date, plate;
                cout << "New vehicle's brand: ";
                getline(cin, brand);
                cout << "Vehicle's type: ";
                getline(cin, type);
                cout << "Vehicle's license plate: ";
                getline(cin, plate);
                if (!validLicensePlate(trim(plate))) {
                    cinERR("ERROR: Invalid plate");
                    enterWait();
                    return false;
                }
                cout << "Vehicle's plate date: ";
                getline(cin, date);
                if (!validDate(trim(date))) {
                    cinERR("ERROR: Invalid date");
                    enterWait();
                    return false;
                }
                if (!base->removeVehicle(base->findVehicle(d->getVehicle()))) {
                    cinERR("ERROR: Couldn't remove vehicle");
                    return false;
                }
                Vehicle v(trim(brand), trim(type), Date(trim(date)), trim(plate));
                d->setVehicle(v.getLicensePlate());
                base->addVehicle(v);
                cout << "\nInformation successfully updated!" << endl;
                enterWait();
                return true;
            }
        }
    }
    cinERR("ERROR: No worker in this base with the given nif!");
    enterWait();
    return false;
}


// Finance functions

void showCompanyTotalEarnings(Company &company){
    double total_revenue = 0;
    double total_expenses = 0;
    double balance = 0;
    for(auto base : company.getCompanyBases()){
        for(auto ord : base.getBaseOrders()){
            auto d = dynamic_cast<Delivery *>(ord);
            if(d != nullptr)
                total_revenue += (d->getOrderPrice()) * 0.2 + (d->getDeliveryPrice() - d->getOrderPrice());
        }
        for (auto worker : base.getBaseWorkers()) {
            total_expenses -= worker->getWorkerSalary();
            auto deliveryperson = dynamic_cast<Deliveryperson*>(worker);
            if(deliveryperson != nullptr) {
                total_expenses -= deliveryperson->getDeliveryEarnings();
            }
        }
    }

    balance = total_revenue + total_expenses;

    cout << "/" << endl;
    cout << "|   Total company revenue: " << total_revenue << endl;
    cout << "|   Total company expenses with salaries: " << total_expenses << endl;
    cout << "|   Global balance: " << balance << endl;
    cout << "\\" << endl;

    enterWait();
}

void showEarningsByBase(Base* base){
    double total_revenue = 0;
    double total_expenses = 0;
    double balance = 0;

    for (auto ord : base->getBaseOrders()){
        auto d = dynamic_cast<Delivery *> (ord);
        if(d != nullptr)
            total_revenue += (d->getOrderPrice()) * 0.2 + (d->getDeliveryPrice() - d->getOrderPrice());
    }
    for (auto worker : base->getBaseWorkers()) {
        total_expenses -= worker->getWorkerSalary();
        auto deliveryperson = dynamic_cast<Deliveryperson*>(worker);
        if(deliveryperson != nullptr) {
            total_expenses -= deliveryperson->getDeliveryEarnings();
        }
    }

    balance = total_revenue + total_expenses;

    cout << base->getBaseLocation().getLocationAddress().getMunicipality() << endl;
    cout << "/" << endl;
    cout << "|   Total base revenue: " << total_revenue << endl;
    cout << "|   Total base expenses with salaries: " << total_expenses << endl;
    cout << "|   Global balance: " << balance << endl;
    cout << "\\" << endl << endl;

    enterWait();
}
