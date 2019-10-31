#ifndef AEDA_UGHEATS_DELIVERY_H
#define AEDA_UGHEATS_DELIVERY_H

#include "Deliveryperson.h"
#include <string>

using namespace std;

class Delivery {
private:
    float deliveryPrice;
    Deliveryperson deliveryperson;
    bool sucess;
    int deliveryTime;
    string notes;
};


#endif //AEDA_UGHEATS_DELIVERY_H
