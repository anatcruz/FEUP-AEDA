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
