#ifndef AEDA_UGHEATS_ORDER_H
#define AEDA_UGHEATS_ORDER_H

#include <vector>
#include <string>
#include "Restaurant.h"
#include "Date.h"
#include "Worker.h"
#include "Client.h"
#include "../utils.h"

using namespace std;

class Time;

class Order {
protected:
    /** The name of the Restaurant the Order was made.
*/
    string restaurant;
    /** The Client's nif who made the Order.
*/
    int client;
    /** The Date the Order was made.
*/
    Date date;
    /** The Time the Order was made.
*/
    Time orderTime;
    /**All the products the Client wants to order.
*/
    vector<string> products;
    /** The price of the Order.
*/
    float orderPrice;
public:
    /** Default Constructor.
*/
    Order() = default;
    /** Constructor of an Order from the restaurant, nif of the client who made the order, date, order time, products and order price.
*/
    Order(string restaurant, int client, Date date, Time orderTime, vector<string> products, float orderPrice);
    //Metodos Set
    /** Sets the restaurant of an Order.
       * @param restaurant is the parameter you want the new Order to have.
*/
    void setOrderRestaurant(string restaurant);
    /** Sets the Date of an Order.
       * @param date is the parameter you want the new Order to have.
*/
    void setOrderDate(Date date);
    /** Sets the Time of an Order.
       * @param orderTime is the parameter you want the new Order to have.
*/
    void setOrderTime(Time orderTime);
    /** Sets the products of an Order.
       * @param products is the parameter you want the new Order to have.
*/
    void setOrderProducts(vector<string> products);
    /** Sets the price of an Order.
       * @param orderPrice is the parameter you want the new Order to have.
*/
    void setOrderPrice(float orderPrice);
    /** Sets the nif of the client of an Order.
       * @param restaurant is the parameter you want the new Order to have.
*/
    void setOrderClient(int client);
    //Metodos Get
    /**
       * @return the Order's restaurant name.
*/
    string getRestaurant() const;
    /**
       * @return the Order's Date.
*/
    Date getOrderDate() const;
    /**
       * @return the Order's Time.
*/
    Time getOrderTime() const;
    /**
       * @return the Order's products.
*/
    vector<string> getOrderProducts() const;
    /**
       * @return the Order's price.
*/
    float getOrderPrice() const;
    /**
       * @return the nif of the client that made the Order.
*/
    int getOrderClient() const;
    //Other Methods
    /** Displays the Order in a nice format.
      * @param out is the ostream.
     */
    virtual void print(ostream &out) const;

};

class Delivery: public Order {
private:
    /**The price of the delivery: whether the restaurant from which the Order was made is the base municipality or border comparing with the Client's municipality, the price increase is 3 or 5 euros respectively.
*/
    float deliveryPrice;
    /**The nif of the Deliveryperson who was assigned the Delivery.
*/
    int deliveryperson;
    /**The success of the Delivery depends on the satisfaction of the Client.
*/
    bool success;
    /**The Time the delivery is made.
*/
    Time deliveryTime;
    /**Some requests the Client can make.
*/
    string notes;
public:
    /**Default Constructor.
*/
    Delivery() = default;
    /** Constructor of a Delivery from the restaurant, nif of the client, date, order time, products, order price, delivery price, nif of the deliveryperson, success, delivery time and notes given.
*/
    Delivery(string restaurant, int client, Date date, Time orderTime, vector<string> products, float orderPrice, float deliveryPrice, int deliveryperson, bool success, Time deliveryTime, string notes);
    //Metodos Set
    /** Sets the price of a Delivery.
       * @param deliveryPrice is the parameter you want the new Delivery to have.
*/
    void setDeliveryPrice(float deliveryPrice);
    /** Sets the nif of the deliveryperson of a Delivery.
       * @param deliveryperson is the parameter you want the new Delivery to have.
*/
    void setDeliveryPerson(int deliveryperson);
    /** Sets if the delivery was successful.
       * @param success is the parameter you want the new Delivery to have.
*/
    void setSuccess(bool success);
    /** Sets the delivery time of a Delivery.
       * @param deliveryTime is the parameter you want the new Delivery to have.
*/
    void setDeliveryTime(Time deliveryTime);
    /** Sets the notes of a Delivery.
       * @param notes is the parameter you want the new Delivery to have.
*/
    void setDeliveryNotes(string notes);
    //Metodos Get
    /**
       * @return the Delivery's price.
*/
    float getDeliveryPrice() const;
    /**
       * @return the nif of the Deliveryperson assigned to the Delivery.
*/
    int getDeliveryPerson() const;
    /**
       * @return if the Delivery was successful.
*/
    bool getSuccess() const;
    /**
       * @return the Delivery's Time.
*/
    Time getDeliveryTime() const;
    /**
       * @return the Delivery's notes.
*/
    string getDeliveryNotes() const;
    //Other Methods
    /** Displays the Delivery in a nice format.
      * @param out is the ostream.
      * @param delivery is the Delivery you want to display.
     */
    friend ostream& operator<<(ostream& out, const Delivery &delivery);

};

#endif //AEDA_UGHEATS_ORDER_H
