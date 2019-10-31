#ifndef AEDA_UGHEATS_RESTAURANT_H
#define AEDA_UGHEATS_RESTAURANT_H

#include <string>
#include <vector>
#include "Base.h"
#include "Order.h"
#include "Product.h"
#include "Address.h"

using namespace std;

class Restaurant{
private:
    Address adress;
    vector<string> cuisine;
    vector<Product> products;
    vector<Order> orders;
    Base base;
};


#endif //AEDA_UGHEATS_RESTAURANT_H
