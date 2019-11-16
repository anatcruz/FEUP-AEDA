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
    /**The types of food the Restaurant has.
*/
    vector<string> cuisine;
    /**The products the Restaurant has.
*/
    vector<Product> products;
    Base* base;
    /**The file that contains the products of the Restaurant.
*/
    string productsFile;
public:
    /**Default Constructor.
*/
    Restaurant() = default;
    /** Constructor of a Restaurant from the name, Address, cuisine, products, Base and products'file.
*/
    Restaurant(string name, Address address, vector<string> cuisine, vector<Product> products, Base* base);
    /** Creates a Restaurant in the Base.
      * The user must fill all te information fot the new Restaurant.
      * @param base is the Base you want to add the Restaurant in.
      * @return true if the Restaurant was created successfully.
*/
    bool makeRestaurant(Base* base);
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
      * @return the Restaurant's name.
*/
    string getRestaurantName() const;
    /**
      * @return the Restaurant's Address.
*/
    Address getRestaurantAddress() const;
    /**
      * @return the Restaurant's cuisine.
*/
    vector<string> getRestaurantCuisine() const;
    /**
      * @return the Restaurant's products.
*/
    vector<Product> getRestaurantProducts() const;
    /**
      * @return the pointer to the Restaurant's base.
*/
    Base* getRestaurantBase() const;
    /**
      * @return the Restaurant's products'file.
*/
    string getProductsFile() const;
    /** Gives all the orders from a restaurant.
       * @return the pointer to the orders.
*/
    vector<Order*> getRestaurantOrders() const;
    //Other Methods
    /** Displays the Restaurant in a nice format.
      * @param out is the ostream.
      * @param restaurant is the Restaurant you want to display.
     */
    friend ostream& operator<<(ostream& out, const Restaurant &restaurant);
    /** Updates the products of a Restaurant.
       * @param product is what you want to add.
*/
    void addProductsToRestaurant(const Product &product);
};


#endif //AEDA_UGHEATS_RESTAURANT_H
