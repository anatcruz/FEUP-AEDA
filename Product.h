#ifndef AEDA_UGHEATS_PRODUCT_H
#define AEDA_UGHEATS_PRODUCT_H

#include <string>
using namespace std;

class Product {
private:
    string name;
    string cuisine;
    float price;

public:
    Product(string name, string cuisine, float price);
    //Metodos Set
    void setProductName(string name);
    void setCuisine(string cuisine);
    void setPrice(float price);
    //Metodos Get
    string getProductName() const;
    string getCuisine() const;
    float getPrice() const;
    //Other Methods
};


#endif //AEDA_UGHEATS_PRODUCT_H
