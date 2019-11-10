#include "utils.h"

bool isNumeric(const string &str) {
    if (str.empty())
        return false;
    for (int i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

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

//Menu utilities
void line(int size, char ch) {
    // Prints a line of specified size with specified character
    cout << setfill(ch) << setw(size) << "" << endl << setfill(' ');
}

void cinERR(const string &message) {
    // Outputs an error message and clears cin flags
    cerr << message;
    cout << endl;
    cin.clear();
}

void getOption(int &dest, const string &message) {
    // Tries to get a valid int option from cin to use in a switch-case
    string str;

    while (true) {
        try {
            cout << endl << message;
            getline(cin, str);
            cout << endl;
            dest = stoi(str);
            break;
        }
        catch (invalid_argument) {
            str = "";
            cinERR("ERROR: Invalid entry, try again");
        }
    }
}


//NIF verification
bool validNIF(string const &nif) {
    if (nif.length() != 9 || !isNumeric(nif))
        return false;
    return true;
}