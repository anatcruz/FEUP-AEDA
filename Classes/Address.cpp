#include "Address.h"

Address::Address(string street, string door, string floor, string postcode, string municipality) {
    this->street=street;
    this->door=door;
    this->floor=floor;
    this->postcode=postcode;
    this->municipality=municipality;
}

Address::Address(string fullAddress) {
    vector<string> temp;
    temp = strToVect(fullAddress, ',');
    street = temp.at(0);
    door = temp.at(1);
    floor = temp.at(2);
    postcode = temp.at(3);
    municipality = temp.at(4);
}

void Address::makeAddress() {
    string str;
    cout << "Address: " << endl;
    cout << "-Street name: ";
    getline(cin,str);
    street = trim(str);
    cout << "-Door number: ";
    getline(cin,str);
    door = trim(str);
    cout << "-Floor number (- none): ";
    getline(cin,str);
    floor = trim(str);
    while(true){
        cout << "-Postcode: ";
        getline(cin,str);

        if(validPostcode(trim(str)))
            break;

        cinERR("ERROR: Invalid Postcode, try again!");
    }
    postcode = trim(str);
    cout << "-Municipality: ";
    getline(cin,str);
    municipality = trim(str);
}

//Metodos Set
void Address::setStreet(string street) {
    this->street=street;
}

void Address::setDoor(string door) {
    this->door=door;
}

void Address::setFloor(string floor) {
    this->floor=floor;
}

void Address::setPostCode(string postcode) {
    this->postcode=postcode;
}

void Address::setMunicipality(string municipality) {
    this->municipality=municipality;
}

//Metodos Get
string Address::getStreet() const {
    return street;
}

string Address::getDoor() const {
    return door;
}

string Address::getFloor() const {
    return floor;
}

string Address::getPostCode() const {
    return postcode;
}

string Address::getMunicipality() const {
    return municipality;
}

//Other Methods

ostream& operator<<(ostream& out, const Address &address){
    out << address.street + "," + address.door + "," + address.floor + "," + address.postcode + "," + address.municipality;
    return out;
}
