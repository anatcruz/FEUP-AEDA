#ifndef AEDA_UGHEATS_RESTAURANT_H
#define AEDA_UGHEATS_RESTAURANT_H

#include <string>
#include <vector>
#include "Base.h"
#include "Order.h"
#include "Product.h"
#include "Address.h"
#include "../utils.h"

using namespace std;

class Order;
class Base;

class Restaurant{
private:
    string name;
    Address address;
    vector<string> cuisine;
    vector<Product> products;
    Base* base;
    string productsFile;
public:
    /** Constructor default.
*/
    Restaurant() = default;
    /** Constructor of a Restaurant from the name, Address, cuisine, products, Base and products'file.
*/
    Restaurant(string name, Address address, vector<string> cuisine, vector<Product> products, Base* base);
    //Metodos Set
    /** Sets the name of a Restaurant.
      * @param name is the parameter you want the new Restaurant to have.
*/
    void setRestaurantName(string name);
    /** Sets the Address of a Restaurant.
      * @param address is the parameter you want the new Restaurant to have.
*/
    void setRestaurantAddress(Address address);
    /** Sets the types of food of a Restaurant.
      * @param cuisine is the parameter you want the new Restaurant to have.
*/
    void setRestaurantCuisine(vector<string> cuisine);
    /** Sets the types of food but first has to transform the string into a vector, of a Restaurant.
      * @param cuisine is the parameter you want the new Restaurant to have.
*/
    void setRestaurantCuisine(string cuisine);
    /** Sets the products of a Restaurant.
      * @param products is the parameter you want the new Restaurant to have.
*/
    void setRestaurantProducts(vector<Product> products);
    /** Sets the Base of a Restaurant.
      * @param base is the parameter you want the new Restaurant to have.
*/
    void setRestaurantBase(Base* base);
    /** Sets the products'file of a Restaurant.
      * @param productsFile is the parameter you want the new Restaurant to have.
*/
    void setProductsFile(string productsFile);
    //Metodos Get
    /**
      * @return the name.
*/
    string getRestaurantName() const;
    /**
      * @return the Address.
*/
    Address getRestaurantAddress() const;
    /**
      * @return the cuisine.
*/
    vector<string> getRestaurantCuisine() const;
    /**
      * @return the products.
*/
    vector<Product> getRestaurantProducts() const;
    /**
      * @return the pointer to the base.
*/
    Base* getRestaurantBase() const;
    /**
      * @return the products'file.
*/
    string getProductsFile() const;
    /** Gives all the orders from a restaurant.
       * @return the pointer to the orders.
*/
    vector<Order*> getRestaurantOrders() const;
    //Other Methods
    /** Displays the Date in a nice format.
      * @param out is the ostream.
      * @param date is the Date you want to display.
     */
    friend ostream& operator<<(ostream& out, const Restaurant &restaurant);
    /** Updates the orders of a restaurant.
       * @param product is the product you want to add.
*/
    void addProductsToRestaurant(const Product &product);
};


#endif //AEDA_UGHEATS_RESTAURANT_H
