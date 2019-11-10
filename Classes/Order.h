#ifndef AEDA_UGHEATS_ORDER_H
#define AEDA_UGHEATS_ORDER_H

#include <vector>
#include <string>
#include "Restaurant.h"
#include "Date.h"
#include "Product.h"
#include "Worker.h"
#include "Client.h"
#include "../utils.h"

using namespace std;

class Restaurant;
class Deliveryperson;
class Client;

class Order {
protected:
    Restaurant* restaurant;
    Client* client;
    Date date;
    int orderTime;
    vector<Product> products;
    float orderPrice;
public:
    Order() = default;
    Order(Restaurant* restaurant, Date date, int orderTime, vector<Product> products, float orderPrice, Client* client);
    //Metodos Set
    void setOrderRestaurant(Restaurant* restaurant);
    void setOrderDate(Date date);
    void setOrderTime(int orderTime);
    void setOrderProducts(vector<Product> products);
    void setOrderPrice(float orderPrice);
    void setOrderClient(Client* client);
    //Metodos Get
    Restaurant* getRestaurant() const;
    Date getOrderDate() const;
    int getOrderTime() const;
    vector<Product> getOrderProducts() const;
    float getOrderPrice() const;
    Client* getOrderClient() const;
    //Other Methods
    virtual void print(ostream &out) const;

};

class Delivery: public Order {
private:
    float deliveryPrice;
    Deliveryperson* deliveryperson;
    bool success;
    int deliveryTime;
    string notes;
public:
    Delivery() = default;
    Delivery(Restaurant* restaurant, Client* client, Date date, int orderTime, vector<Product> products, float orderPrice, float deliveryPrice, Deliveryperson* deliveryperson, bool success, int deliveryTime, string notes);
    //Metodos Set
    void setDeliveryPrice(float deliveryPrice);
    void setDeliveryPerson(Deliveryperson* deliveryperson);
    void setSuccess(bool success);
    void setDeliveryTime(int deliveryTime);
    void setDeliveryNotes(string notes);
    //Metodos Get
    float getDeliveryPrice() const;
    Deliveryperson* getDeliveryPerson() const;
    bool getSuccess() const;
    int getDeliveryTime() const;
    string getDeliveryNotes() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Delivery &delivery);

};

#endif //AEDA_UGHEATS_ORDER_H
