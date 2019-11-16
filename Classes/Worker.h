#ifndef AEDA_UGHEATS_WORKER_H
#define AEDA_UGHEATS_WORKER_H

#include <string>
#include <vector>
#include "Order.h"
#include "Date.h"
#include "Vehicle.h"
#include "../utils.h"

class Order;
class Delivery;
class Base;

using namespace std;

class Worker {
protected:
    /** Worker's name.
*/
    string name;
    /** Worker's nif.
*/
    int nif;
    /** Worker's date of birth.
*/
    Date birthdate;
    /** Worker's salary.
*/
    double salary;
    /** The Base the Worker works in.
*/
    Base* base;
public:
    /** Default Constructor.
*/
    Worker() = default;
    /** Constructor of a Worker from the name, nif, date of birth and salary given.
*/
    Worker(string name, int nif, Date birthdate, double salary);
    //Metodos Set
    /** Sets the name of a Worker.
       * @param name is the parameter you want the new Worker to have.
*/
    void setWorkerName(string name);
    /** Sets the nif of a Worker.
       * @param nif is the parameter you want the new Worker to have.
*/
    void setWorkerNif(int nif);
    /** Sets the date of birth of a Worker.
       * @param birthdate is the parameter you want the new Worker to have.
*/
    void setWorkerBirthdate(Date birthdate);
    /** Sets the salary of a Worker.
       * @param salary is the parameter you want the new Worker to have.
*/
    void setWorkerSalary(double salary);
    /** Sets the base of a Worker.
       * @param base is the parameter you want the new Worker to have.
*/
    void setWorkerBase(Base* base);
    //Metodos Get
    /**
      * @return the name.
*/
    string getWorkerName() const;
    /**
      * @return the nif.
*/
    int getWorkerNif() const;
    /**
      * @return the date of birth.
*/
    Date getWorkerBirthdate() const;
    /**
      * @return the salary.
*/
    double getWorkerSalary() const;
    /**
      * @return the pointer to the worker's Base.
*/
    Base* getWorkerBase() const;
    //Other Methods
    /** Displays the Worker in a nice format.
      * @param out is the ostream.
     */
    virtual void print(ostream &out) const;
};

class Admin: public Worker {
protected:
    /** The job description of the Admin.
*/
    string description;
public:
    /** Default Constructor.
*/
    Admin() = default;
    /** Constructor of an Admin from the name, nif, birthdate, salary and description given.
*/
    Admin(string name, int nif, Date birthdate, double salary, string description);
    //Metodos Set
    /** Sets the description of an Admin.
       * @param description is the parameter you want the new Admin to have.
*/
    void setWorkerDescription(string description);
    //Metodos Get
    /**
      * @return the Admin's description.
*/
    string getWorkerDescription() const;
    //Other Methods
    /** Displays the Admin in a nice format.
      * @param out is the ostream.
      * @param admin is the Admin you want to display.
     */
    friend ostream& operator<<(ostream& out, const Admin &admin);
};

class Deliveryperson: public Worker {
protected:
    /** Each Deliveryperson is assigned a Vehicle for the deliveries.
*/
    Vehicle vehicle;
public:
    /** Default Constructor.
*/
    Deliveryperson() = default;
    /** Constructor of a Deliveryperson from the name, nif, birthdate, salary and Vehicle given.
 */
    Deliveryperson(string name, int nif, Date birthdate, double salary, Vehicle vehicle);
    //Metodos Set
    /** Sets the Vehicle of a Deliveryperson.
       * @param vehicle is the parameter you want the new Deliveryperson to have.
*/
    void setVehicle(Vehicle vehicle);
    //Metodos Get
    /**
      * @return the Vehicle.
*/
    Vehicle getVehicle() const;
    /**
      * @return all the deliveries done by a Deliveryperson.
*/
    vector<Delivery*> getDeliveries() const;
    /**
      * @return the money the Deliveryperson should receive depending on the his deliveries.
*/
    double getDeliveryEarnings() const;
    //Other Methods
    /** Displays the Deliveryperson in a nice format.
      * @param out is the ostream.
      * @param deliveryperson is the Deliveryperson you want to display.
     */
    friend ostream& operator<<(ostream& out, const Deliveryperson &deliveryperson);
};


#endif //AEDA_UGHEATS_WORKER_H
