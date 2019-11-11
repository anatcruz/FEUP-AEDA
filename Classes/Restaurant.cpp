#include "Restaurant.h"

Restaurant::Restaurant(string name, Address address, vector<string> cuisine, vector<Product> products, Base* base) {
    this->name=name;
    this->address=address;
    this->cuisine=cuisine;
    this->products=products;
    this->base=base;
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

//Other Methods

ostream &operator<<(ostream &out, const Restaurant &restaurant){
    out << setw(2) << ' ' << restaurant.name << endl;
    out << "/" << endl;
    out << setw(4) << left << '|' << "Address: " << restaurant.address << endl;
    out << setw(4) << left << '|' << "Cuisine type: ";
    for(int i=0 ; i< restaurant.cuisine.size() ; i++){
        if (i == restaurant.cuisine.size() - 1)
            out << restaurant.cuisine.at(i);
        else
            out << restaurant.cuisine.at(i);
    }
    out << setw(4) << left << '|' << "Products: ";
    for(int i=0 ; i< restaurant.products.size() ; i++){
        if (i == restaurant.products.size() - 1)
            out << restaurant.products.at(i);
        else
            out << restaurant.products.at(i);
    }
    out << setw(4) << left << '|' << "Orders: ";
    for(int i=0 ; i< restaurant.base->getBaseOrders().size() ; i++){
        if (i == restaurant.base->getBaseOrders().size() - 1)
            out << restaurant.base->getBaseOrders().at(i);
        else
            out << restaurant.base->getBaseOrders().at(i);
    }
    out << setw(4) << left << '|' << "Base: " << restaurant.base->getBaseLocation() <<endl;
    return out;
}

void Restaurant::addProductsToRestaurant(const Product &product) {
    products.push_back(product);
}




