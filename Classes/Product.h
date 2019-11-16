#ifndef AEDA_UGHEATS_PRODUCT_H
#define AEDA_UGHEATS_PRODUCT_H

#include <string>
#include "../utils.h"

using namespace std;

class Product {
private:
    string name;
    string cuisine;
    float price;
public:
    /**Default Constructor.
*/
    Product() = default;
    /** Constructor of a Product from the name, cuisine and price.
*/
    Product(string name, string cuisine, float price);
    /** Makes a Product once the user fills all it's parameters.
*/
    void makeProduct();
    //Metodos Set
    /** Sets the name of a Product.
       * @param name is the parameter you want the new Product to have.
*/
    void setProductName(string name);
    /** Sets the cuisine of a Product.
       * @param cuisine is the parameter you want the new Product to have.
*/
    void setCuisine(string cuisine);
    /** Sets the price of a Product.
       * @param price is the parameter you want the new Product to have.
*/
    void setPrice(float price);
    //Metodos Get
    /**
       * @return the Product's name.
*/
    string getProductName() const;
    /**
       * @return the Product's cuisine.
*/
    string getCuisine() const;
    /**
       * @return the Product's price.
*/
    float getPrice() const;
    //Other Methods
    /** Displays the Product in a nice format.
      * @param out is the ostream.
      * @param product is the Product you want to display.
     */
    friend ostream& operator<<(ostream& out, const Product &product);
};


#endif //AEDA_UGHEATS_PRODUCT_H
