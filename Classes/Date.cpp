#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day=day;
    this->month=month;
    this->year=year;
}

Date::Date(string date) {
    vector<string> vdata = strToVect(date, '/');
    this->day = stoi(vdata.at(0));
    this->month = stoi(vdata.at(1));
    this->year = stoi(vdata.at(2));
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

bool Date::operator<(const class Date & date) const {
    if (this->year < date.getYear()) {
        return true;
    } else if (this->year == date.getYear() && this->month < date.getMonth()) {
        return true;
    } else if (this->year == date.getYear() && this->month == date.getMonth() && this->day < date.getDay()) {
        return true;
    }
    return false;
}

bool Date::operator==(const Date &date) const {
    return (day == date.getDay() && month == date.getMonth() && year == date.getYear());
}

Date Date::addDay() {
    Date result(0,00,year);
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
        if(day == 31){
            result.setDay(1);
            result.setMonth(month+1);
        }
        else{
            result.setDay(day+1);
        }
    }
    else if(month == 2){
        if((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)){
            if(day == 29){
                result.setDay(1);
                result.setMonth(month+1);
            }
            else{
                result.setDay(day+1);
            }
        }
        else{
            if(day == 28){
                result.setDay(1);
                result.setMonth(month+1);
            }
            else{
                result.setDay(day+1);
            }
        }

    }
    else if(month == 4 || month == 6 || month == 9 || month == 11){
        if(day == 30){
            result.setDay(1);
            result.setMonth(month+1);
        }
        else{
            result.setDay(day+1);
        }
    }
    else if(month == 12){
        if(day == 31){
            result.setDay(1);
            result.setMonth(1);
            result.setYear(year+1);
        }
    }
    return result;
}

ostream& operator<<(ostream& out, const Date & date){
    out << right << setw(2) << setfill('0') << to_string(date.day);
    out << "/" << setfill('0') << setw(2) << to_string(date.month);
    out << "/" << setfill('0') << setw(4) << to_string(date.year) << setfill(' ');
    return out;
}

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
                if (vdate.at(0) > 31) {
                    return false;
                }
                break;
            case 4: case 6: case 9: case 11:
                if (vdate.at(0) > 30) {
                    return false;
                }
                break;
            case 2:
                if (vdate.at(0) > 29) {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    return true;
}

