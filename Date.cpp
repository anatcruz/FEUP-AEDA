#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day=day;
    this->month=month;
    this->year=year;
}

Date::Date(string date) {
    vector<string> vdata = strToVect(date, '/');
    this->day = stoi(vdata.at(2));
    this->month = stoi(vdata.at(1));
    this->year = stoi(vdata.at(0));
}

//Metodos Set
void Date::setDay(int day) {
    this->day=day;
}

void Date::setMonth(int month) {
    this->month=month;
}

void Date::setYear(int year) {
    this->year=year;
}

//Metodos Get
int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

//Other Methods

bool validDate(string date) {
    if (date.empty())
        return false;

    vector<string> vsdate = strToVect(date, '/');

    if (vsdate.size() != 3)
        return false;

    vector<int> vdate(3);

    for (int i = 0; i < 3; i++) {
        try {
            vdate.at(i) = stoul(vsdate.at(i));
        } catch (invalid_argument) {
            return false;
        }
    }

    if (vdate.at(0) < 1) {
        return false;
    }
    else if (vdate.at(1) < 1 || vdate.at(1) > 12) {
        return false;
    }
    else if (vdate.at(2) < 1) {
        return false;
    }
    else {
        switch (vdate.at(1)) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (vdate.at(2) > 31) {
                    return false;
                }
                break;
            case 4: case 6: case 9: case 11:
                if (vdate.at(2) > 30) {
                    return false;
                }
                break;
            case 2:
                if (vdate.at(2) > 29) {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    return true;
}