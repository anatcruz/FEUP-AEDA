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

/** Checks if a string is made up exclusively by numbers.
       * @param str is the string you want to test.
       * @return true if the string is only made up by numbers.
*/
bool isNumeric(const string &str);

/** Removes whitespace from both ends of a string.
       * @param str is the string you want to trim.
       * @return the string passed as parameter without the whitespace at the beginning and ending.
*/
string trim(string &str);

/** Transforms a string into a vector.
       * @param str is the string you want to transform.
       * @param delim is the separator of the elements of the string.
       * @return the vector with the elements of the string separated by delim.
*/
vector<string> strToVect(const string &str, char delim = ' ');

/** Makes a pair of coords from a string
       * @param str is the string you want to transform into coords.
       * @return the pair of coods.
*/
pair<float,float> makeCoords(const string str);

//Menu utilities
/** Prints a line of a specified size with a specified character.
       * @param size is the size of the line.
       * @param ch is the character, by default is '-'.
*/
void line(int size, char ch = '-');

/** Outputs an error message and clears cin flags.
       * @param message is what you want to display.
*/
void cinERR(const string &message);

/** Tries to get a valid int option from cin to use in a switch-case.
       * @param dest is the variable where you want to save the option selected.
       * @param message is the message to be display before selecting an option, by default is "Option: ".
*/
void getOption(int &dest, const string &message = "Option: ");

/** Checks if the nif is valid.
       * @param nif is what you want to check.
       * @return true if the nif is valid.
*/
bool validNIF(string const &nif);

/** Checks if the postcode is valid.
       * @param postcode is what you want to check.
       * @return true if the postcode is valid.
*/
bool validPostcode(string const &postcode);

//Just useful
/** The program waits until the user presses Enter to continue.
*/
void enterWait();

#endif //AEDA_UGHEATS_UTILS_H
