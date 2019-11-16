#include <iostream>
#include <string>
#include "Classes/Menu.h"
#include "Classes/Company.h"

#include <time.h>
using namespace std;

void faznada() {};

void fazalgo() {
    cout << "eu faço algo" << endl;
}


int main() {
    Company ugh("../Data/");
    Client* openClient;
    Worker* openWorker;
    Base* openBase;

    // Start program message
    line(35);
    cout << setw(35) << setfill (' ') << "Ugh-Eats v1.0" << endl;
    cout << setw(35) << setfill (' ') << "~The future of food~" << endl;

    // Menu creation
    Menu startMenu("Welcome!");
    Menu clientMenu("Ugh-Eats");
    Menu restaurantsMenu("Restaurants");
    Menu clientAccountManagementMenu("Account management");
    Menu adminMenu("Ugh-Eats - Admin");
    Menu adminClientManagementMenu("Client management");
    Menu adminWorkerManagementMenu("Worker management");
    Menu adminRestaurantManagementMenu("Restaurant management");

    // startMenu creation
    startMenu.addOption("Exit", faznada);
    startMenu.addOption("Log-in", [&](){openClient = clientLogin(ugh); if (openClient!= nullptr) {openBase = openClient->getBase(); clientMenu.start();}});
    startMenu.addOption("Sign-up", [&](){createClientAccount(ugh);});
    startMenu.addOption("Admin", [&](){openWorker = workerLogin(ugh); if (openWorker!= nullptr) {openBase = openWorker->getWorkerBase(); adminMenu.start();}});


    // clientMenu creation
    clientMenu.addOption("Log-out", faznada);
    clientMenu.addOption("Restaurants", [&](){restaurantsMenu.start();});
    clientMenu.addOption("Order history", [&](){viewClientOrdersHistory(*openClient);});
    clientMenu.addOption("Account management", [&](){clientAccountManagementMenu.start();});

    // restaurantsMenu
    // TODO message: search by
    restaurantsMenu.addOption("Go back", faznada);
    restaurantsMenu.addOption("By name", [&](){makeOrderDeliveryByRestaurant(*openClient,openBase);});
    restaurantsMenu.addOption("By municipality", [&](){makeOrderDeliveryByMunicipality(*openClient,openBase);});
    restaurantsMenu.addOption("By price range", [&](){makeOrderDeliveryByPrice(*openClient,openBase);});
    restaurantsMenu.addOption("By cuisine", [&](){makeOrderDeliveryByCuisine(*openClient,openBase);});

    // clientAccountManagementMenu creation
    clientAccountManagementMenu.addOption("Go back", faznada);
    clientAccountManagementMenu.addOption("View info", [&](){cout << *openClient; enterWait();});
    clientAccountManagementMenu.addOption("Edit info", [&](){editClientInfo(ugh,*openClient);});
    clientAccountManagementMenu.addOption("Delete account", [&](){deleteClientAccount(openClient,openBase);});



    // adminMenu creation
    adminMenu.addOption("Log-out", faznada);
    adminMenu.addOption("Client management", [&](){adminClientManagementMenu.start();});
    adminMenu.addOption("Worker management", [&](){adminWorkerManagementMenu.start();});
    adminMenu.addOption("Restaurant management", [&](){adminRestaurantManagementMenu.start();});
    adminMenu.addOption("Finance", faznada);

    // adminClientManagementMenu creation
    adminClientManagementMenu.addOption("Go back", faznada);
    adminClientManagementMenu.addOption("View all clients", [&](){showAllClients(ugh);});
    adminClientManagementMenu.addOption("View clients by base", [&](){showClientsByBase(ugh);});
    adminClientManagementMenu.addOption("View specific client", [&](){showSpecificClient(ugh);});

    // adminWorkerManagementMenu creation
    adminWorkerManagementMenu.addOption("Go back", faznada);
    adminWorkerManagementMenu.addOption("View base workers", [&](){showWorkers(openBase);});
    adminWorkerManagementMenu.addOption("Hire worker", [&](){hireWorker(openBase);});
    adminWorkerManagementMenu.addOption("Edit worker info", [&](){editWorkerInfo(openBase);});
    adminWorkerManagementMenu.addOption("Fire worker", [&](){fireWorker(openBase);});

    // adminRestaurantManagementMenu creation
    adminRestaurantManagementMenu.addOption("Go back", faznada);
    adminRestaurantManagementMenu.addOption("Add new restaurant", [&](){addRestaurant(openBase);});
    adminRestaurantManagementMenu.addOption("Remove restaurant", [&](){removeRestaurant(openBase);});
    adminRestaurantManagementMenu.addOption("View all restaurants", [&](){showAllRestaurants(ugh);});
    adminRestaurantManagementMenu.addOption("View restaurants by base", [&](){showRestaurantsByBase(ugh);});
    adminRestaurantManagementMenu.addOption("View specific restaurant", [&](){showSpecificRestaurant(ugh);});


    // Start!
    startMenu.start();

//    updateBasesFile(ugh);
//    updateCompanyFile(ugh);
//    for (int i = 0; i<ugh.getCompanyBases().size(); i++) {
//        updateClientsFile(ugh.getCompanyBases().at(i));
//        updateWorkersFile(ugh.getCompanyBases().at(i));
//        updateRestaurantsFile(ugh.getCompanyBases().at(i));
//        updateProductsFile(ugh.getCompanyBases().at(i));
//        updateOrdersFile(ugh.getCompanyBases().at(i));
//    }
//    cout << *openClient;
//    openWorker->print(cout);
//    cout << *openBase;
//    viewClientOrdersHistory(*openClient);
//    showAllClients(ugh);
    return 0;
}