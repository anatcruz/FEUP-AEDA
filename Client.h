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

public:
    //Metodos Set
    void setClientName(string name);
    void setBase(Base base);
    void setClientAddress(Address address);
    void setClientNif(int nif);
    void setBlack_listed(bool black_listed);
    //Metodos Get
    string getClientName() const;
    Base getBase() const;
    Address getClientAddress() const;
    int getClientNif() const;
    bool getBlack_listed();



};


#endif //AEDA_UGHEATS_CLIENT_H