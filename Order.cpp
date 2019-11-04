#include "Order.h"

//Metodos Set
void Order::setOrderRestaurant(Restaurant restaurant) {
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

//Metodos Get
Restaurant Order::getRestaurant() const {
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

//Metodos Set
void Delivery::setDeliveryPrice(float deliveryPrice) {
    this->deliveryPrice = deliveryPrice;
}

void Delivery::setDeliveryPerson(float deliveryPerson) {
    this->deliveryperson = deliveryPerson;
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

Deliveryperson Delivery::getDeliveryPerson() const {
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
