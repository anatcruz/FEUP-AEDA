//
// Created by antonio on 31/10/19.
//

#ifndef AEDA_UGHEATS_BASE_H
#define AEDA_UGHEATS_BASE_H

#include <string>
#include <vector>
#include "Location.h"
#include "Admin.h"
#include "Client.h"
#include "Restaurant.h"

using namespace std;

class Base {
private:
    Location location;
    Admin manager;
    vector<Client> clients;
    vector<Restaurant> restaurants;
    vector<string> municipalities;
};


#endif //AEDA_UGHEATS_BASE_H
