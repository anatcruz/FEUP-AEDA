#ifndef AEDA_UGHEATS_RESTAURANT_H
#define AEDA_UGHEATS_RESTAURANT_H

#include <string>
#include <vector>
#include "Base.h"
#include "Order.h"
#include "Product.h"
#include "Address.h"
#include "../utils.h"

using namespace std;

class Order;
class Base;

class Restaurant{
private:
    string name;
    Address address;
    vector<string> cuisine;
    vector<Product> products;
    vector<Order*> orders;
    Base* base;
public:
    Restaurant() = default;
    Restaurant(string name, Address address, vector<string> cuisine, vector<Product> products, vector<Order*> orders, Base* base);
    //Metodos Set
    void setRestaurantName(string name);
    void setRestaurantAddress(Address address);
    void setRestaurantCuisine(vector<string> cuisine);
    void setRestaurantCuisine(string cuisine);
    void setRestaurantProducts(vector<Product> products);
    void setRestaurantOrders(vector<Order*> orders);
    void setRestaurantBase(Base* base);
    //Metodos Get
    string getRestaurantName() const;
    Address getRestaurantAddress() const;
    vector<string> getRestaurantCuisine() const;
    vector<Product> getRestaurantProducts() const;
    vector<Order*> getRestaurantOrders() const;
    Base* getRestaurantBase() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Restaurant &restaurant);
    void addProductsToRestaurant(const Product &product);
};


#endif //AEDA_UGHEATS_RESTAURANT_H
