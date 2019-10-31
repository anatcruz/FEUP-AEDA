#ifndef AEDA_UGHEATS_ORDER_H
#define AEDA_UGHEATS_ORDER_H

#include "Restaurant.h"
#include "Date.h
#include "Product.h"
#include <vector>
#include <string>

using namespace std;

class Order {
protected:
    Restaurant restaurant;
    Date date;
    int orderTime;
    vector<Product> products;
    float orderPrice;
};

class Delivery: Order {
private:
    float deliveryPrice;
    Deliveryperson deliveryperson;
    bool sucess;
    int deliveryTime;
    string notes;
};

#endif //AEDA_UGHEATS_ORDER_H
