#ifndef AEDA_UGHEATS_ORDER_H
#define AEDA_UGHEATS_ORDER_H

#include <vector>
#include <string>
#include "Restaurant.h"
#include "Date.h"
#include "Product.h"
#include "Worker.h"
#include "Client.h"
#include "Time.h"
#include "../utils.h"

using namespace std;

class Time;

class Order {
protected:
    string restaurant;
    int client;
    Date date;
    Time orderTime;
    vector<string> products;
    float orderPrice;
public:
    Order() = default;
    Order(string restaurant, int client, Date date, Time orderTime, vector<string> products, float orderPrice);
    //Metodos Set
    void setOrderRestaurant(string restaurant);
    void setOrderDate(Date date);
    void setOrderTime(Time orderTime);
    void setOrderProducts(vector<string> products);
    void setOrderPrice(float orderPrice);
    void setOrderClient(int client);
    //Metodos Get
    string getRestaurant() const;
    Date getOrderDate() const;
    Time getOrderTime() const;
    vector<string> getOrderProducts() const;
    float getOrderPrice() const;
    int getOrderClient() const;
    //Other Methods
    virtual void print(ostream &out) const;

};

class Delivery: public Order {
private:
    float deliveryPrice;
    int deliveryperson;
    bool success;
    Time deliveryTime;
    string notes;
public:
    Delivery() = default;
    Delivery(string restaurant, int client, Date date, Time orderTime, vector<string> products, float orderPrice, float deliveryPrice, int deliveryperson, bool success, Time deliveryTime, string notes);
    //Metodos Set
    void setDeliveryPrice(float deliveryPrice);
    void setDeliveryPerson(int deliveryperson);
    void setSuccess(bool success);
    void setDeliveryTime(Time deliveryTime);
    void setDeliveryNotes(string notes);
    //Metodos Get
    float getDeliveryPrice() const;
    int getDeliveryPerson() const;
    bool getSuccess() const;
    Time getDeliveryTime() const;
    string getDeliveryNotes() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Delivery &delivery);

};

#endif //AEDA_UGHEATS_ORDER_H
