#include <iostream>
#include <string>
#include "Classes/Menu.h"

using namespace std;

void faznada() {};

void fazalgo() {
    cout << "eu faço algo" << endl;
}

int main() {
    /*while (true) {
        std::cout << "Hello, World!";
        string a;
        getline(cin, a);
        break;
    }*/
    line(35);
    cout << setw(35) << setfill (' ') << "Ugh-Eats v1.0" << endl;
    cout << setw(35) << setfill (' ') << "~The future of food~" << endl;
    Menu loginMenu("Welcome!");
    loginMenu.addOption("Exit", faznada);
    loginMenu.addOption("Log-in", fazalgo);
    loginMenu.addOption("Sign-up", faznada);
    loginMenu.addOption("Admin", faznada);
    loginMenu.display();
    return 0;
}