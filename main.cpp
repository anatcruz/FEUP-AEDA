#include <iostream>
#include <string>
#include "Classes/Menu.h"
#include "Classes/Company.h"

#include <time.h>
using namespace std;

void faznada() {};

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
    Menu adminWorkerViewMenu("View workers");
    Menu adminRestaurantManagementMenu("Restaurant management");
    Menu adminRestaurantViewMenu("View restaurants");
    Menu adminRestaurantOrdersMenu("View orders");
    Menu adminFinanceMenu("Finance");

    // startMenu creation
    startMenu.addOption("Exit", faznada);
    startMenu.addOption("Log-in", [&](){openClient = clientLogin(ugh); if (openClient!= nullptr) {openBase = openClient->getBase(); clientMenu.start();}});
    startMenu.addOption("Sign-up", [&](){createClientAccount(ugh);});
    startMenu.addOption("Admin", [&](){openWorker = adminLogin(ugh); if (openWorker!= nullptr) {openBase = openWorker->getWorkerBase(); adminMenu.start();}});


    // clientMenu creation
    clientMenu.addOption("Log-out", faznada);
    clientMenu.addOption("Restaurants", [&](){restaurantsMenu.start();});
    clientMenu.addOption("Order history", [&](){viewClientOrdersHistory(*openClient);});
    clientMenu.addOption("Account management", [&](){clientAccountManagementMenu.start();});

    // restaurantsMenu
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
    adminMenu.addOption("Finance", [&](){adminFinanceMenu.start();});

    // adminClientManagementMenu creation
    adminClientManagementMenu.addOption("Go back", faznada);
    adminClientManagementMenu.addOption("View all clients", [&](){showAllClients(ugh);});
    adminClientManagementMenu.addOption("View clients by base", [&](){showClientsByBase(ugh);});
    adminClientManagementMenu.addOption("View specific client", [&](){showSpecificClient(ugh);});

    // adminWorkerManagementMenu creation
    adminWorkerManagementMenu.addOption("Go back", faznada);
    adminWorkerManagementMenu.addOption("View base workers", [&](){adminWorkerViewMenu.start();});
    adminWorkerManagementMenu.addOption("Hire worker", [&](){hireWorker(openBase);});
    adminWorkerManagementMenu.addOption("Edit worker info", [&](){editWorkerInfo(openBase);});
    adminWorkerManagementMenu.addOption("Fire worker", [&](){fireWorker(openBase);});

    // adminWorkerViewMenu creation
    adminWorkerViewMenu.addOption("Go back", faznada);
    adminWorkerViewMenu.addOption("View all base workers", [&](){showWorkers(openBase);});
    adminWorkerViewMenu.addOption("View base Administrators", [&](){showAdmins(openBase);});
    adminWorkerViewMenu.addOption("View base Deliverypersons", [&](){showDeliverypersons(openBase);});
    adminWorkerViewMenu.addOption("View specific worker", [&](){showSpecificWorker(openBase);});

    // adminRestaurantManagementMenu creation
    adminRestaurantManagementMenu.addOption("Go back", faznada);
    adminRestaurantManagementMenu.addOption("View restaurants", [&](){adminRestaurantViewMenu.start();});
    adminRestaurantManagementMenu.addOption("View orders", [&](){adminRestaurantOrdersMenu.start();});
    adminRestaurantManagementMenu.addOption("Add new restaurant", [&](){addRestaurant(openBase);});
    adminRestaurantManagementMenu.addOption("Remove restaurant", [&](){removeRestaurant(openBase);});

    // adminRestaurantViewMenu creation
    adminRestaurantViewMenu.addOption("Go back", faznada);
    adminRestaurantViewMenu.addOption("View all restaurants", [&](){showAllRestaurants(ugh);});
    adminRestaurantViewMenu.addOption("View restaurants by base", [&](){showRestaurantsByBase(ugh);});
    adminRestaurantViewMenu.addOption("View specific restaurant", [&](){showSpecificRestaurant(ugh);});

    // adminRestaurantOrdersMenu creation
    adminRestaurantOrdersMenu.addOption("Go back", faznada);
    adminRestaurantOrdersMenu.addOption("View all orders", [&](){showBaseOrders(openBase);});
    adminRestaurantOrdersMenu.addOption("View orders by restaurant", [&](){showSpecificRestaurantsOrders(openBase);});
    adminRestaurantOrdersMenu.addOption("View orders by client", [&](){showSpecificClientOrders(openBase);});

    // adminFinanceMenu creation
    adminFinanceMenu.addOption("Go back", faznada);
    adminFinanceMenu.addOption("Company earnings", [&](){showCompanyTotalEarnings(ugh);});
    adminFinanceMenu.addOption("Base earnings", [&](){showEarningsByBase(ugh);});
    adminFinanceMenu.addOption("Deliveryperson earnings", [&](){showDeliveypersonEarnings(openBase);});

    // Start!
    startMenu.start();

    string str;
    cout << "Do you want to save changes to file (Y/N): ";
    getline(cin, str);
    if (str == "Y" || str == "y") {
        updateBasesFile(ugh);
        updateCompanyFile(ugh);
        for (int i = 0; i < ugh.getCompanyBases().size(); i++) {
            updateClientsFile(ugh.getCompanyBases().at(i));
            updateWorkersFile(ugh.getCompanyBases().at(i));
            updateRestaurantsFile(ugh.getCompanyBases().at(i));
            updateProductsFile(ugh.getCompanyBases().at(i));
            updateOrdersFile(ugh.getCompanyBases().at(i));
        }
        cout << "Files saved successfully!" << endl;
    } else {
        cout << "Files not saved" << endl;
    }
    return 0;
}