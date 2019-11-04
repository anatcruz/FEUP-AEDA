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
public:
    //Metodos Set
    void setOrderRestaurant(Restaurant restaurant);
    void setOrderDate(Date date);
    void setOrderTime(int orderTime);
    void setOrderProducts(vector<Product> products);
    void setOrderPrice(float orderPrice);
    //Metodos Get
    Restaurant getRestaurant() const;
    Date getOrderDate() const;
    int getOrderTime() const;
    vector<Product> getOrderProducts() const;
    float getOrderPrice() const;
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
