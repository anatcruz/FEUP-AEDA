//
// Created by antonio on 31/10/19.
//

#ifndef AEDA_UGHEATS_CLIENT_H
#define AEDA_UGHEATS_CLIENT_H

#include <string>
#include "Base.h"
#include "Address.h"

using namespace std;

class Client {
private:
    string name;
    Base base;
    Address address;
    int nif;
    bool black_listed;
};


#endif //AEDA_UGHEATS_CLIENT_H
