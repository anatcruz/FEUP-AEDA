#include <iostream>
#include <string>
#include "Classes/Menu.h"

using namespace std;

void faznada() {};

void fazalgo() {
    cout << "eu faço algo" << endl;
}

Menu* wrapper;


int main() {
    // Start program message
    line(35);
    cout << setw(35) << setfill (' ') << "Ugh-Eats v1.0" << endl;
    cout << setw(35) << setfill (' ') << "~The future of food~" << endl;

    // Menu creation
    Menu startMenu("Welcome!");
    Menu clientLoginMenu("Log-in");
    Menu signupMenu("Sign-up");
    Menu adminLoginMenu("Admin log-in");

    // startMenu creation
    startMenu.addOption("Exit", faznada);
    startMenu.addOption("Log-in", [&](){clientLoginMenu.start();});
    startMenu.addOption("Sign-up", faznada);
    startMenu.addOption("Admin", faznada);

    // clientLoginMenu creation
    clientLoginMenu.addOption("Meow?", faznada);

    // Start!
    startMenu.start();
    return 0;
}