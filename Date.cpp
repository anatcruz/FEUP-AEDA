#include "Date.h"

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
