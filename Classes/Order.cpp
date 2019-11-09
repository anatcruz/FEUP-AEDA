#include "Order.h"

//CLASS ORDER

Order::Order(Restaurant* restaurant, Date date, int orderTime, vector<Product> products, float orderPrice, Client* client) {
    this->restaurant=restaurant;
    this->date=date;
    this->orderTime=orderTime;
    this->products=products;
    this->orderPrice=orderPrice;
    this->client = client;
}

//Metodos Set
void Order::setOrderRestaurant(Restaurant* restaurant) {
    this->restaurant = restaurant;
}

void Order::setOrderDate(Date date) {
    this->date = date;
}

void Order::setOrderTime(int orderTime) {
    this->orderTime = orderTime;
}

void Order::setOrderProducts(vector<Product> products) {
    this->products = products;
}

void Order::setOrderPrice(float orderPrice) {
    this->orderPrice = orderPrice;
}

void Order::setOrderClient(Client* client) {
    this->client = client;
}

//Metodos Get
Restaurant* Order::getRestaurant() const {
    return restaurant;
}

Date Order::getOrderDate() const {
    return date;
}

int Order::getOrderTime() const {
    return orderTime;
}

vector<Product> Order::getOrderProducts() const {
    return products;
}

float Order::getOrderPrice() const {
    return orderPrice;
}

Client *Order::getOrderClient() const {
    return client;
}

//Other Methods


//CLASE DELIVERY

Delivery::Delivery(float deliveryPrice, Deliveryperson* deliveryperson, bool success, int deliveryTime, string notes):Order(restaurant, date, orderTime, products, orderPrice){
    this->deliveryPrice=deliveryPrice;
    this->deliveryperson=deliveryperson;
    this->success=success;
    this->deliveryTime=deliveryTime;
    this->notes=notes;
}

//Metodos Set
void Delivery::setDeliveryPrice(float deliveryPrice) {
    this->deliveryPrice = deliveryPrice;
}

void Delivery::setDeliveryPerson(Deliveryperson* deliveryperson) {
    this->deliveryperson = deliveryperson;
}

void Delivery::setSuccess(bool success) {
    this->success = success;
}

void Delivery::setDeliveryTime(int deliveryTime) {
    this->deliveryTime = deliveryTime;
}

void Delivery::setDeliveryNotes(string notes) {
    this->notes = notes;
}

//Metodos Get
float Delivery::getDeliveryPrice() const {
    return deliveryPrice;
}

Deliveryperson* Delivery::getDeliveryPerson() const {
    return deliveryperson;
}

bool Delivery::getSuccess() const {
    return success;
}

int Delivery::getDeliveryTime() const {
    return deliveryTime;
}

string Delivery::getDeliveryNotes() const {
    return notes;
}

