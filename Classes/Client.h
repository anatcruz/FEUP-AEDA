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
    /**Client's name.
*/
    string name;
    /**Pointer to the Client's Base.
*/
    Base* base;
    /**Client's Address.
*/
    Address address;
    /**Client's nif.
*/
    int nif;
    /**Indicates if the Client is in the black list of the Company.
*/
    bool black_listed;

public:
    /**Default Constructor.
*/
    Client() = default;
    /** Constructor of a Client from the name, Base, Address, nif and a bool back_listed, which indicates if the Client is in the black list of the Company, given.
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
    /** Sets the black_listed(bool which indicates if the Client is in the black list of the Company) of a Client.
       * @param black_listed is the parameter you want the new Client to have.
*/
    void setBlack_listed(bool black_listed);
    //Metodos Get
    /**
      * @return the Client's name.
*/
    string getClientName() const;
    /**
      * @return the pointer to the Client's Base.
*/
    Base* getBase();
    /**
      * @return the Client's Address.
*/
    Address getClientAddress() const;
    /**
      * @return the Client's nif.
*/
    int getClientNif() const;
    /**
      * @return the Client's black_listed.
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
/** Checks if a Client exists in a vector of Clients.
       * @param nif is the nif of the Client you want to search for.
       * @param clients is the vector where we want to look for that Client.
       * @return true if the Client exists in the vector.
*/
bool searchClientbyNif(int nif, vector<Client> clients);


#endif //AEDA_UGHEATS_CLIENT_H
