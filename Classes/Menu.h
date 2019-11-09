#ifndef AEDA_UGHEATS_MENU_H
#define AEDA_UGHEATS_MENU_H

#include <string>
#include <vector>
#include "../utils.h"

using namespace std;

typedef void (*function)();

class Menu {
private:
    string name;
    vector<pair<string, function>> options;
public:
    Menu(string name);
    void start();
    void display();
    string getName();
    vector<pair<string, function>> getOptions();
    void setName(string name);
    void setOptions(vector<pair<string, function>> options);
    void addOption(string option, function func);
};


#endif //AEDA_UGHEATS_MENU_H
