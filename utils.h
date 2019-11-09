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

// Removes whitespace from both ends of a string
string trim(string &str);

//Vector/String conversions
vector<string> strToVect(const string &str, char delim = ' ');

//Make a pair of coords from a string
pair<float,float> makeCoords(const string str);


#endif //AEDA_UGHEATS_UTILS_H
