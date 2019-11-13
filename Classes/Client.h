#ifndef AEDA_UGHEATS_CLIENT_H
#define AEDA_UGHEATS_CLIENT_H

#include <string>
#include <vector>
#include "Base.h"
#include "Address.h"
#include "Order.h"
#include "../utils.h"

using namespace std;

class Base;
class Order;

class Client {
private:
    string name;
    Base* base;
    Address address;
    int nif;
    bool black_listed;

public:
    /** Constructor default.
*/
    Client() = default;
    /** Constructor of a Client from the name, Base, Address, nif and black_listed given.
*/
    Client(string name, Base* base, Address address, int nif, bool black_listed);
    //Metodos Set
    /** Sets the name of a Client.
       * @param name is the parameter you want the new Client to have.
*/
    void setClientName(string name);
    /** Sets the Base of a Client.
       * @param base is the parameter you want the new Client to have.
*/
    void setBase(Base* base);
    /** Sets the Address of a Client.
       * @param address is the parameter you want the new Client to have.
*/
    void setClientAddress(Address address);
    /** Sets the nif of a Client.
       * @param nif is the parameter you want the new Client to have.
*/
    void setClientNif(int nif);
    /** Sets the black_listed(bool that says if the client is in the black_list of the Company) of a Client.
       * @param black_listed is the parameter you want the new Client to have.
*/
    void setBlack_listed(bool black_listed);
    //Metodos Get
    /**
      * @return the name.
*/
    string getClientName() const;
    /**
      * @return the pointer to the base.
*/
    Base* getBase();
    /**
      * @return the address.
*/
    Address getClientAddress() const;
    /**
      * @return the nif.
*/
    int getClientNif() const;
    /**
      * @return the black_listed.
*/
    bool getBlack_listed();
    //Other Methods
    /** Displays the Client in a nice format.
      * @param out is the ostream.
      * @param client is the Client you want to display.
     */
    friend ostream& operator<<(ostream& out, const Client & client);
    /** Compare clients: overload of the operator == .
       * @param c2 is the client you want to compare too.
       * @return true if the clients are equal: have the same nif.
*/
    bool operator==(Client& c2);
};

//Verifica se um cliente existe no vetor
/** Check if a client exists in a vector of Clients.
       * @param nif is the nif of the client you want to search for.
       * @param clients is the vector where we want to look for the client.
       * @return true if the clients exists in the vector.
*/
bool searchClientbyNif(int nif, vector<Client> clients);


#endif //AEDA_UGHEATS_CLIENT_H
