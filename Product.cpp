#include "Product.h"

Product::Product(string name, string cuisine, float price) {
    this->name=name;
    this->cuisine=cuisine;
    this->price=price;
}

//Metodos Set
void Product::setProductName(string name) {
    this->name = name;
}

void Product::setCuisine(string cuisine) {
    this->cuisine = cuisine;
}

void Product::setPrice(float price) {
    this->price = price;
}

//Metodos Get
string Product::getProductName() const {
    return name;
}

string Product::getCuisine() const {
    return cuisine;
}

float Product::getPrice() const {
    return price;
}

//Other Methods

