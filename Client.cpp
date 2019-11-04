#include "Client.h"

//Metodos Set
void Client::setClientName(string name) {
    this->name = name;
}

void Client::setBase(Base base) {
    this->base = base;
}

void Client::setClientAddress(Address address) {
    this->address = address;
}

void Client::setClientNif(int nif) {
    this->nif =  nif;
}

void Client::setBlack_listed(bool black_listed) {
    this->black_listed = black_listed;
}

//Metodos Get
string Client::getClientName() const {
    return name;
}

Base Client::getBase() const {
    return base;
}

Address Client::getClientAddress() const {
    return address;
}

int Client::getClientNif() const {
    return nif;
}

bool Client::getBlack_listed() {
    return black_listed;
}




