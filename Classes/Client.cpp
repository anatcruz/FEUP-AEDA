#include "Client.h"

Client::Client(string name, Base* base, Address address, int nif, bool black_listed) {
    this->name=name;
    this->base=base;
    this->address=address;
    this->nif=nif;
    this->black_listed=black_listed;
}

//Metodos Set
void Client::setClientName(string name) {
    this->name = name;
}

void Client::setBase(Base* base) {
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

Base* Client::getBase() const {
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

//Other Methods

ostream& operator<<(ostream& out, const Client &client){
    out << "/" << endl;
    out << setw(4) << left << '|' << "Name: " << client.name << endl;
    out << setw(4) << left << '|' << "Base: "<< client.base->getBaseLocation() << endl;
    out << setw(4) << left << '|' << "Address: " << client.address << endl;
    out << setw(4) << left << '|' << "NIF: " << right << setfill('0') << setw(9) << client.nif << setfill(' ') <<endl;
    out << setw(4) << left << '|' << "Blacklisted: " << client.black_listed << endl;
    out << "\\_" << endl;
    return out;
}

bool searchClientbyNif(int nif, vector<Client> clients){
    for(int i = 0; i < clients.size(); i++){
        if (clients.at(i).getClientNif() == nif)
            return true;

    }
    return false;
}

bool Client::operator==(Client &c2) {
    return nif == c2.getClientNif();
}
