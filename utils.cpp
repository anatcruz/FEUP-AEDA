#include "utils.h"

string trim(string &str) {
    auto str_init = str.find_first_not_of(" \t");
    if (str_init == string::npos)
        return ""; // String is all whitespace
    auto str_end = str.find_last_not_of(" \t");
    auto str_range = str_end - str_init + 1;

    return str.substr(str_init, str_range);
}

vector<string> strToVect(const string &str, char delim) {
    vector<string> result;
    string tmp;
    // Create stream from string
    istringstream ss(str);
    // Grab the elements from the stream, separated by delim
    while (getline(ss, tmp, delim)) {
        result.push_back(trim(tmp));
        // Skip whitespace
        ss >> ws;
    }
    return result;
}

pair<float,float> makeCoords(const string str){
    pair<float,float> coords;
    vector<string> temp;
    temp = strToVect(str,',');
    coords.first=stof(temp.at(0));
    coords.second=stof(temp.at(1));
    return coords;
}