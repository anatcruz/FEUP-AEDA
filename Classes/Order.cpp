#include "Order.h"

//CLASS ORDER

Order::Order(Restaurant* restaurant,Client* client, Date date, Time orderTime, vector<Product> products, float orderPrice) {
    this->restaurant=restaurant;
    this->client = client;
    this->date=date;
    this->orderTime=orderTime;
    this->products=products;
    this->orderPrice=orderPrice;

}

//Metodos Set
void Order::setOrderRestaurant(Restaurant* restaurant) {
    this->restaurant = restaurant;
}

void Order::setOrderDate(Date date) {
    this->date = date;
}

void Order::setOrderTime(Time orderTime) {
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

Time Order::getOrderTime() const {
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
void Order::print(ostream &out) const {
    out << "/" << endl;
    out << setw(4) << left << '|' << "Restaurant: " << restaurant << endl;
    out << setw(4) << left << '|' << "Client: "<< client << endl;
    out << setw(4) << left << '|' << "Date: " << date << endl;
    out << setw(4) << left << '|' << "Order time: " << orderTime << endl;
    out << setw(4) << left << '|' << "Products: ";
    for(int i=0 ; i< products.size() ; i++){
        if (i == products.size() - 1)
            out << products.at(i);
        else
            out << products.at(i);
    }
    out << setw(4) << left << '|' << "Order price: " << orderPrice << endl;
    out << "\\_" << endl;
}

//CLASE DELIVERY


Delivery::Delivery(Restaurant* restaurant,Client* client, Date date, Time orderTime, vector<Product> products, float orderPrice, float deliveryPrice, Deliveryperson* deliveryperson, bool success, Time deliveryTime, string notes):Order(restaurant, client, date, orderTime, products, orderPrice){
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

void Delivery::setDeliveryTime(Time deliveryTime) {
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

Time Delivery::getDeliveryTime() const {
    return deliveryTime;
}

string Delivery::getDeliveryNotes() const {
    return notes;
}

//Other Methods
ostream &operator<<(ostream &out, const Delivery &delivery) {
    delivery.print(out);
    out << setw(4) << left << '|' << "Delivery price: "<< delivery.deliveryPrice << endl;
    out << setw(4) << left << '|' << "Delivery person: " << delivery.deliveryperson << endl;
    out << setw(4) << left << '|' << "Sucess: " << delivery.success << endl;
    out << setw(4) << left << '|' << "Delivery time: " << delivery.deliveryTime << endl;
    out << setw(4) << left << '|' << "Notes: " << delivery.notes << endl;
    out << "\\_" << endl;
    return out;
}

