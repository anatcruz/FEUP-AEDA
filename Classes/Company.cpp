#include "Company.h"

Company::Company(string name, Location location, double capital, int nif, string email, string phone, vector<Base> bases) {
    this->name=name;
    this->location=location;
    this->capital=capital;
    this->nif=nif;
    this->email=email;
    this->phone=phone;
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

void Company::setCompanyBases(vector<Base> bases) {
    this->bases = bases;
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

vector<Base> Company::getCompanyBases() const {
    return bases;
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

        //Get workers
        getline(cin,str);
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
                Vehicle v;
                getline(workers_file, str); //Vehicle Manufacturer
                v.setManufacturer(str);
                getline(workers_file, str); //Vehicle Type
                v.setType(str);
                getline(workers_file, str); //Vehicle purchaseDate
                v.setPurchaseDate(Date(str));
                d->setVehicle(v);
                b.addWorkerToBase(d);
            }
            getline(workers_file, str); //Discard delimiter
        }
        workers_file.close();

        getline(bases_file, str);
        auto it = find_if(b.getBaseWorkers().begin(),b.getBaseWorkers().end(), [=](Worker* w){return w->getWorkerNif() == stoi(str);}); //Get Admin for this base
        b.setBaseManager((Admin*)*(it));

        getline(bases_file,str);
        b.setBaseMunicipalities(strToVect(str, ',')); //Base Municipalities

        bases.push_back(b);

        getline(bases_file,str);    //Discard delimiter
    }


    bases_file.close();
}

Company::~Company() {
}//TODO change destructor

Client* clientLogin(Company &company) {
    vector<Base>* companyBases = company.getCompanyBasesAddr();
    Base* base;
    cout << "Select a base:" << endl;
    for (int i = 0; i < companyBases->size(); i++) {
        cout << i + 1 << ". " << companyBases->at(i).getBaseLocation().getLocationAddress().getMunicipality() << endl;
    }
    int base_idx;
    getOption(base_idx, "Base: ");
    if (base_idx > 0 && base_idx <= companyBases->size()) {
        base = &companyBases->at(base_idx - 1);
    } else {
        cinERR("Base does not exist!");
        cout << "ENTER to go back";
        string str;
        getline(cin, str);
        return nullptr;
    }
    base_idx--;
    string nif_str;
    while (true) {
        cout << "NIF: ";
        getline(cin, nif_str);
        if (validNIF(nif_str)) {
            auto it = find_if(base->getBaseClientsAddr()->begin(), base->getBaseClientsAddr()->end(),
                    [&](Client &c){return c.getClientNif() == stoi(nif_str);});
            if (it != base->getBaseClientsAddr()->end()) {
                return &*it;
            } else {
                cinERR("Client does not exist, try again!"); //TODO add cancel
            }
        } else {
            cinERR("Invalid NIF, try again!");
        }
    }
}

vector<Base>* Company::getCompanyBasesAddr() {
    return &bases;
}

//Funçoes para dar update a ficheiros
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
    string file = base.getBaseWorkersFile();
    ofstream out_file(file);

    for(int i = 0; i < temp.size(); i++){
        Admin *a = dynamic_cast<Admin *> (temp.at(i));
        if (a!= NULL){
            out_file << "Admin" << endl;
            out_file << a->getWorkerName() << endl;
            out_file << a->getWorkerNif() << endl;
            out_file << a->getWorkerBirthdate() << endl;
            out_file << a->getWorkerSalary() << endl;
            out_file << a->getWorkerDescription();
        }
        else{
            Deliveryperson *d = dynamic_cast<Deliveryperson *> (temp.at(i));
            if(d!=NULL){
                out_file << "Deliveryperson" << endl;
                out_file << d->getWorkerName() << endl;
                out_file << d->getWorkerNif() << endl;
                out_file << d->getWorkerBirthdate() << endl;
                out_file << d->getVehicle().getManufacturer() << endl;
                out_file << d->getVehicle().getType() << endl;
                out_file << d->getVehicle().getPurchaseDate();
            }
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

//Funçoes para clientes
void viewClientOrdersHistory(Client &client){
    Base *base = client.getBase();
    for(int i=0;i<base->getBaseOrders().size();i++){
        if(base->getBaseOrders().at(i)->getOrderClient()->getClientNif()==client.getClientNif()){
            cout<<base->getBaseOrders().at(i);
        }
    }
}

bool createClientAccount(Company &company){
    vector<Base> companyBases = company.getCompanyBases();
    Base base;
    cout << "Select a base:" << endl;
    for (int i = 0; i < companyBases.size(); i++) {
        cout << i + 1 << ". " << companyBases.at(i).getBaseLocation().getLocationAddress().getMunicipality() << endl;
    }
    int base_idx;
    getOption(base_idx, "Base: ");
    if (base_idx > 0 && base_idx <= companyBases.size()) {
        base = companyBases.at(base_idx - 1);
    } else {
        cinERR("Base does not exist!");
        cout << "ENTER to go back";
        string str;
        getline(cin, str);
        return false;
    }
    base_idx--;
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
        cout << "ENTER to go back";
        string str;
        getline(cin, str);
        return false;
    }

    new_client.setClientNif(nif);

    cout << "Municipality: ";
    getline(cin,municipality);
    vector<string> municipalities = base.getBaseMunicipalities();
    if (find(municipalities.begin(), municipalities.end(), municipality) != municipalities.end()) {
        address.setMunicipality(municipality);
    } else{
        cinERR("ERROR: You cant sign up in this base!");
        cout << "ENTER to go back";
        string str;
        getline(cin, str);
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
    companyBases.at(base_idx) = static_cast<Base &&>(base);
    company.setCompanyBases(companyBases);
    return true;
} // TODO see if it still works

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
                                new_base = static_cast<Base &&>(company.getCompanyBases().at(i));
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
                    vector<Client> temp = base->getBaseClients();
                    if(temp.at(i).getClientNif()==client.getClientNif()){
                        temp.erase(base->getBaseClients().begin()+i);
                        base->setBaseClients(temp);
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

//Funçoes de fazer encomendas
//TODO still unfinished, falta deliverymen!
bool makeOrderDelivery(Client &client, Restaurant *restaurant){
    int opt;
    string satisfied, notes = "";
    bool success;
    vector<Product> products_ordered={};
    float order_price=0, delivery_price=0;
    Order new_order;
    Delivery new_delivery;

    time_t now;
    time(&now);
    struct tm* current_t = localtime(&now);
    new_order.setOrderTime(Time(current_t->tm_hour,current_t->tm_min,current_t->tm_sec));
    new_order.setOrderDate(Date(current_t->tm_mday,current_t->tm_mon,current_t->tm_year));

    cout << "Choose the product you want" << endl;
    cout << "Products: " << endl;
    for (int i = 0; i < restaurant->getRestaurantProducts().size(); i++){
        cout << i+1 << ": " << restaurant->getRestaurantProducts().at(i) << endl;
    }
    cout << "0 - finish/cancel order" << endl;
    cout << "Option: ";

    do{
        getOption(opt);
        if(opt>0 && opt<=restaurant->getRestaurantProducts().size()){
            products_ordered.push_back(restaurant->getRestaurantProducts().at(opt-1));
        }
        else {
            cout << "ERROR: Invalid product choice!Try again: ";
        }

    }while(opt != 0);

    //se o vetor esta vazio quer dizer que o utilizador nao selecionou nenhum produto e a opçao foi 0
    if(products_ordered.empty()){
        cout << "Your order was canceled!" << endl;
        return false;
    }

    for (int i = 0; i < products_ordered.size(); i++){
        order_price += products_ordered.at(i).getPrice();
        }

    //criar a nova encomenda
    new_order.setOrderPrice(order_price);
    new_order.setOrderProducts(products_ordered);
    new_order.setOrderRestaurant(restaurant);
    new_order.setOrderClient(&client);

    //criar a entrega
    if(restaurant->getRestaurantAddress().getMunicipality() == client.getClientAddress().getMunicipality())
        delivery_price = order_price + 3;
    else
        delivery_price = order_price + 5;


    cout << "Are you satisfied with your order(YES/NO)?" << endl;
    cout << "Option: ";
    getline(cin,satisfied);
    success = (satisfied == "YES");
    //new_delivery(new_order,delivery_price,)

}

bool makeOrderDeliveryByRestaurant(Client &client, Base &base){
    string restaurant_name;

    cout << "Enter the restaurant you want to order from: ";
    getline(cin,restaurant_name);

    auto it = find_if(base.getBaseRestaurants().begin(),base.getBaseRestaurants().end(),[&](Restaurant rest){return rest.getRestaurantName() == restaurant_name;});

    if(it == base.getBaseRestaurants().end()){
        cinERR("ERROR: That restaurant does not exist in your base! Cant make order!");
        return false;
    }
    else{
        makeOrderDelivery(client,&(*it));
    }
}

bool makeOrderDeliveryByMunicipality(Client &client, Base &base){
    string str, municipality;
    int opt;

    cout << "Enter the municipality you want to order from: ";
    getline(cin, str);
    municipality = trim(str);
    if(!searchbyMunicipality(municipality,base.getBaseMunicipalities())){
        cinERR("ERROR: We don't have services for that municipality! Can't make order");
        return false;
    }
    else{
        for(int i=0;i<base.getBaseRestaurants().size();i++){
            if(base.getBaseRestaurants().at(i).getRestaurantAddress().getMunicipality()==municipality){
                cout <<  i+1 << ": " << base.getBaseRestaurants().at(i) << endl;
            }
        }
        cout << "0 - cancel order" << endl;
        cout << "Option: ";

        while(true){
            getOption(opt);
            if(opt>0 && opt<=base.getBaseRestaurants().size()){
                string rest_name = base.getBaseRestaurants().at(opt-1).getRestaurantName();
                auto it = find_if(base.getBaseRestaurants().begin(), base.getBaseRestaurants().end(),[&](Restaurant rest){return rest.getRestaurantName() == rest_name;});
                makeOrderDelivery(client,&(*it));

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
}//TODO juntar com a função da teté

void showAllClients(Company &company){
    cout << "-----All Clients' Information-----\n"<<endl;
    for(int i=0;i<company.getCompanyBases().size();i++){
        for(int j=0; j<company.getCompanyBases().at(i).getBaseClients().size();j++){
            cout<<company.getCompanyBases().at(i).getBaseClients().at(j) << endl;
        }
    }
}

void showClientsByBase(Company &company){
    int opt;
    cout << "Select from which base you want to see clients' information:" << endl;
    cout << "1: Porto" << endl;
    cout << "2: Lisboa" << endl;
    cout << "3: Faro" << endl;
    cout << "0 - cancel" << endl;
    cout << "Option: ";
    getOption(opt);
    while(opt<0 || opt > 3) {
        cinERR("ERROR: Invalid input, try again! ");
        cout << "Option: ";
        getOption(opt);
    }
    if(opt==0) {
        cout << "Canceled successfully!" << endl;
    }
    else{
        for(int i=0; i<company.getCompanyBases().at(opt-1).getBaseClients().size();i++){
            cout << company.getCompanyBases().at(opt-1).getBaseClients().at(i) << endl;
        }
    }
}

void showSpecificClient(Company &company){
    string str_nif;
    int nif;

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

    for(int i=0; i<company.getCompanyBases().size(); i++){
        auto it = find_if(company.getCompanyBases().at(i).getBaseClients().begin(),company.getCompanyBases().at(i).getBaseClients().end(),[&](Client client){return client.getClientNif() == nif;});
        if (it != company.getCompanyBases().at(i).getBaseClients().end()){
            cout << *it;
            return;
        }
    }
    cinERR("ERROR: Client with given nif does not exist!");
}

void showAllRestaurants(Company &company){
    cout << "-----All Restaurants' Information-----" << endl;
    for(int i=0;i<company.getCompanyBases().size();i++){
        for(int j=0;j<company.getCompanyBases().at(i).getBaseRestaurants().size();j++){
            cout << company.getCompanyBases().at(i).getBaseRestaurants().at(j) << endl;
        }
    }
}

void showRestaurantsByBase(Company &company){
    int opt;
    cout << "Select from which base you want to see restaurants' information:" << endl;
    cout << "1: Porto" << endl;
    cout << "2: Lisboa" << endl;
    cout << "3: Faro" << endl;
    cout << "0 - cancel" << endl;
    cout << "Option: ";
    getOption(opt);
    while(opt<0 || opt > 3) {
        cinERR("ERROR: Invalid input, try again! ");
        cout << "Option: ";
        getOption(opt);
    }
    if(opt==0) {
        cout << "Canceled successfully!" << endl;
    }
    else{
        for(int i=0; i<company.getCompanyBases().at(opt-1).getBaseRestaurants().size();i++){
            cout << company.getCompanyBases().at(opt-1).getBaseRestaurants().at(i) << endl;
        }
    }
}

void showSpecificRestaurant(Company &company){
    string str,restaurant;
    cout << "Enter restaurant's name (* - cancel): " ;
    getline(cin,str);
    restaurant=trim(str);
    if(restaurant=="*"){
        cout<<"Canceled successfully!"<<endl;
        return;
    }
    for(int i=0; i<company.getCompanyBases().size(); i++){
        auto it = find_if(company.getCompanyBases().at(i).getBaseRestaurants().begin(),company.getCompanyBases().at(i).getBaseRestaurants().end(),[&](Restaurant rest){return rest.getRestaurantName() == restaurant;});
        if (it != company.getCompanyBases().at(i).getBaseRestaurants().end()){
            cout << *it;
            return;
        }
    }
    cinERR("ERROR: Restaurant with given name does not exist!");
}