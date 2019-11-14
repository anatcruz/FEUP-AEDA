#ifndef AEDA_UGHEATS_DATE_H
#define AEDA_UGHEATS_DATE_H

#include <string>
#include <vector>
#include "../utils.h"

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;
public:
    /** Constructor default.
*/
    Date() = default;
    /** Constructor of a Date from the day,month and year given.
*/
    Date(int day, int month, int year);
    /** Constructor of a Date from a given date in the format of string.
       * @param date is what you want to transform in a Date.
*/
    Date(string date);
    //Metodos Set
    /** Sets the day of a Date.
       * @param day is the parameter you want the new Date to have.
*/
    void setDay(int day);
    /** Sets the month of a Date.
       * @param month is the parameter you want the new Date to have.
*/
    void setMonth(int month);
    /** Sets the year of a Date.
       * @param year is the parameter you want the new Date to have.
*/
    void setYear(int year);
    //Metodos Get
    /**
       * @return the day.
*/
    int getDay() const;
    /**
       * @return the month.
*/
    int getMonth() const;
    /**
       * @return the year.
*/
    int getYear() const;
    //Other Methods
    /** Displays the Date in a nice format.
      * @param out is the ostream.
      * @param date is the Date you want to display.
     */
    friend ostream& operator<<(ostream& out, const Date & date);
};

/** Checks if a date is valid.
       * @param date is the Date in format of string you want to check.
       * @return true if the date is valid.
*/
bool validDate(string date);

#endif //AEDA_UGHEATS_DATE_H
