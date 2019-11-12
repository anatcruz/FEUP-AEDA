#ifndef AEDA_UGHEATS_UTILS_H
#define AEDA_UGHEATS_UTILS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

// Checks if a string is made up exclusively by numbers
bool isNumeric(const string &str);

// Removes whitespace from both ends of a string
string trim(string &str);

//Vector/String conversions
vector<string> strToVect(const string &str, char delim = ' ');

//Make a pair of coords from a string
pair<float,float> makeCoords(const string str);

//Menu utilities
void line(int size, char ch = '-');

void cinERR(const string &message);

void getOption(int &dest, const string &message = "Option: ");

//NIF verification
bool validNIF(string const &nif);

//Postcode verification
bool validPostcode(string const &postcode);

//Just useful
void enterWait();

#endif //AEDA_UGHEATS_UTILS_H
