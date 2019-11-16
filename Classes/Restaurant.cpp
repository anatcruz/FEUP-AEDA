#include "Restaurant.h"

Restaurant::Restaurant(string name, Address address, vector<string> cuisine, vector<Product> products, Base* base) {
    this->name=name;
    this->address=address;
    this->cuisine=cuisine;
    this->products=products;
    this->base=base;
}

bool Restaurant::makeRestaurant(Base* base) {
    string str;
    Address address;
    vector<string> cuisine;

    this->base = base;

    cout << "Name: (* - cancel): ";
    getline(cin,str);
    if(str == "*") {
        return false;
    } else if (find_if(base->getBaseRestaurantsAddr()->begin(), base->getBaseRestaurantsAddr()->end(), [&](Restaurant &r){return r.getRestaurantName() == trim(str);}) != base->getBaseRestaurantsAddr()->end()) {
        cinERR("Restaurant with the same name already exists!");
        enterWait();
        return false;
    }
    name = trim(str);

    productsFile = "products" + removeSpaces(str) + ".txt";

    address.makeAddress();
    vector<string> municipalities = base->getBaseMunicipalities();
    if (find(municipalities.begin(), municipalities.end(), address.getMunicipality()) != municipalities.end()) {
        this->address = address;
    } else {
        cinERR("This restaurant cannot be assigned to this base!");
        enterWait();
        return false;
    }

    while(true){
        cout << "Add food type: ";
        getline(cin,str);
        str = trim(str);
        if (!str.empty()) {
            cuisine.push_back(trim(str));
        }
        cout << "Add more? (Y/N): ";
        getline(cin, str);
        if(str != "Y" && str != "y"){
            break;
        }
    }
    this->cuisine = cuisine;

    while(true){
        Product p;
        cout << "Add product to menu: " << endl;
        p.makeProduct();
        auto prd = find_if(products.begin(), products.end(), [&](Product &pp){ return pp.getProductName() == p.getProductName();});
        if (prd == this->products.end()) {
            this->addProductsToRestaurant(p);
        } else {
            cout << "Product with same name already exists! Not added!" << endl;
        }
        cout << "Add more? (Y/N): ";
        getline(cin, str);
        if(str != "Y" && str != "y"){
            break;
        }
    }

    return true;
}


//Metodos Set

void Restaurant::setRestaurantName(string name) {
    this->name=name;
}

void Restaurant::setRestaurantAddress(Address address) {
    this->address=address;
}

void Restaurant::setRestaurantCuisine(vector<string> cuisine) {
    this->cuisine=cuisine;
}

void Restaurant::setRestaurantCuisine(string cuisine){
    this->cuisine=strToVect(cuisine,',');
}

void Restaurant::setRestaurantProducts(vector<Product> products) {
    this->products=products;
}

void Restaurant::setRestaurantBase(Base* base) {
    this->base=base;
}

void Restaurant::setProductsFile(string productsFile) {
    this->productsFile = productsFile;
}


//Metodos Get

string Restaurant::getRestaurantName() const {
    return name;
}

Address Restaurant::getRestaurantAddress() const {
    return address;
}

vector<string> Restaurant::getRestaurantCuisine() const {
    return cuisine;
}

vector<Product> Restaurant::getRestaurantProducts() const {
    return products;
}

Base* Restaurant::getRestaurantBase() const {
    return base;
}

string Restaurant::getProductsFile() const {
    return productsFile;
}

vector<Order*> Restaurant::getRestaurantOrders() const {
    vector<Order*> rest_ords;
    for (auto ord : this->getRestaurantBase()->getBaseOrders()) {
        if (ord->getRestaurant() == this->name) {
            rest_ords.push_back(ord);
        }
    }
    return rest_ords;
}


//Other Methods

ostream &operator<<(ostream &out, const Restaurant &restaurant){
    out << setw(2) << ' ' << restaurant.name << endl;
    out << "/" << endl;
    out << setw(4) << left << '|' << "Address: " << restaurant.address << endl;
    out << setw(4) << left << '|' << "Cuisine type: ";
    for(int i=0 ; i< restaurant.cuisine.size() ; i++){
        if (i == restaurant.cuisine.size() - 1)
            out << restaurant.cuisine.at(i) << endl;
        else
            out << restaurant.cuisine.at(i) << ", ";
    }
    out << setw(4) << left << '|' << "Products: " << restaurant.products.size() << endl;
    /*for(int i=0 ; i< restaurant.products.size() ; i++){
        if (i == restaurant.products.size() - 1)
            out << restaurant.products.at(i) << endl;
        else
            out << restaurant.products.at(i) << ", ";
    }*/
    out << setw(4) << left << '|' << "Orders: " << restaurant.getRestaurantOrders().size() << endl;
    out << setw(4) << left << '|' << "Base: " << restaurant.base->getBaseLocation() <<endl;
    out << "\\_" << endl;
    return out;
}

void Restaurant::addProductsToRestaurant(const Product &product) {
    auto it = find_if(cuisine.begin(), cuisine.end(), [&](string &c){ return product.getCuisine() == c;});
    if (it == cuisine.end()) {
        cuisine.push_back(product.getCuisine());
    }
    products.push_back(product);
}

bool Restaurant::removeProduct(const string &product) {
    auto it = find_if(products.begin(), products.end(), [&](Product &p){return p.getProductName() == product;});

    if (it == products.end()) {
        return false;
    }

    products.erase(it);

    return true;
}




