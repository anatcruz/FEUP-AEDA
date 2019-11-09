#ifndef AEDA_UGHEATS_MENU_H
#define AEDA_UGHEATS_MENU_H

#include <string>
#include <vector>

using namespace std;

class Menu {
private:
    vector<pair<string, void (*)()>> options;
public:
    void start();
    void display();
    vector<pair<string, void (*)()>> getOptions();
    void setOptions(vector<pair<string, void (*)()>>);
    void addOption(pair<string, void (*)()>);
};


#endif //AEDA_UGHEATS_MENU_H
