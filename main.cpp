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

Menu* wrapper;


int main() {
    Company ugh("/home/antonio/FEUP/2_ano/1_sem/AEDA/AEDA-UghEats/Data/");

    // Start program message
    line(35);
    cout << setw(35) << setfill (' ') << "Ugh-Eats v1.0" << endl;
    cout << setw(35) << setfill (' ') << "~The future of food~" << endl;

    // Menu creation
    Menu startMenu("Welcome!");
    Menu clientLoginMenu("Log-in");
    Menu clientMenu("Ugh-Eats");
    Menu adminLoginMenu("Admin log-in");
    Menu adminMenu("Ugh-Eats - Admin");

    // startMenu creation
    startMenu.addOption("Exit", faznada);
    startMenu.addOption("Log-in", [&](){clientLoginMenu.start();});
    startMenu.addOption("Sign-up", [&](){createClientAccount(ugh);});
    startMenu.addOption("Admin", [&](){adminLoginMenu.start();});

    // clientLoginMenu creation
    clientLoginMenu.addOption("Go back", faznada);
    clientLoginMenu.addOption("Meow?", [&](){clientMenu.start();});

    // clientMenu creation
    clientMenu.addOption("Log-out", faznada);
    clientMenu.addOption("Restaurants", faznada);
    clientMenu.addOption("Order history", faznada);
    clientMenu.addOption("Account management", faznada);

    // adminLoginMenu creation
    adminLoginMenu.addOption("Go back", faznada);
    adminLoginMenu.addOption("Woof!", [&](){adminMenu.start();});


    // adminMenu creation
    adminMenu.addOption("Log-out", faznada);
    adminMenu.addOption("Client management", faznada);
    adminMenu.addOption("Worker management", faznada);
    adminMenu.addOption("Restaurant management", faznada);
    adminMenu.addOption("Finance", faznada);

    // Start!
    startMenu.start();

    return 0;
}