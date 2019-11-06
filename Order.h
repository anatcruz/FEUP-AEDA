#ifndef AEDA_UGHEATS_ORDER_H
#define AEDA_UGHEATS_ORDER_H

#include "Restaurant.h"
#include "Date.h
#include "Product.h"
#include "Worker.h"
#include <vector>
#include <string>


using namespace std;

class Order {
protected:
    Restaurant restaurant;
    Date date{};
    int orderTime;
    vector<Product> products;
    float orderPrice;
public:
    Order(Restaurant restaurant, Date date, int orderTime, vector<Product> products, float orderPrice);
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
    //Other Methods

};

class Delivery: Order {
private:
    float deliveryPrice;
    Deliveryperson deliveryperson;
    bool success;
    int deliveryTime;
    string notes;
public:
    Delivery(float deliveryPrice, Deliveryperson deliveryperson, bool success, int deliveryTime, string notes);
    //Metodos Set
    void setDeliveryPrice(float deliveryPrice);
    void setDeliveryPerson(float deliveryPerson);
    void setSuccess(bool success);
    void setDeliveryTime(int deliveryTime);
    void setDeliveryNotes(string notes);
    //Metodos Get
    float getDeliveryPrice() const;
    Deliveryperson getDeliveryPerson() const;
    bool getSuccess() const;
    int getDeliveryTime() const;
    string getDeliveryNotes() const;
    //Other Methods

};

#endif //AEDA_UGHEATS_ORDER_H
