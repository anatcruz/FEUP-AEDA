#include "Restaurant.h"

Restaurant::Restaurant(Address address, vector<string> cuisine, vector<Product> products, vector<Order*> orders,
                       Base* base) {
    this->address=address;
    this->cuisine=cuisine;
    this->products=products;
    this->orders=orders;
    this->base=base;
}


//Metodos Set
void Restaurant::setRestaurantAddress(Address address) {
    this->address=address;
}

void Restaurant::setRestaurantCuisine(vector<string> cuisine) {
    this->cuisine=cuisine;
}

void Restaurant::setRestaurantProducts(vector<Product> products) {
    this->products=products;
}

void Restaurant::setRestaurantOrders(vector<Order*> orders) {
    this->orders=orders;
}

void Restaurant::setRestaurantBase(Base* base) {
    this->base=base;
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

vector<Order*> Restaurant::getRestaurantOrders() const {
    return orders;
}

Base* Restaurant::getRestaurantBase() const {
    return base;
}


