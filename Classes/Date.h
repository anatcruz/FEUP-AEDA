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
    /**Default Constructor.
*/
    Date() = default;
    /** Constructor of a Date from the day, month and year given.
*/
    Date(int day, int month, int year);
    /** Constructor of a Date from a given date in the format of a string.
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
       * @return the Date's day.
*/
    int getDay() const;
    /**
       * @return the Date's month.
*/
    int getMonth() const;
    /**
       * @return the Date's year.
*/
    int getYear() const;
    //Other Methods
    /** Compares 2 Dates.
      * @param date is the Date you want to compare too.
      * @return true if the Date passed as parameter is after the Date.
     */
    bool operator<(const Date &date) const;
    bool operator==(const Date &date) const;
    bool operator!=(const Date &date) const { return !(*this == date);};
    /** Displays the Date in a nice format.
      * @param out is the ostream.
      * @param date is the Date you want to display.
     */
    friend ostream& operator<<(ostream& out, const Date & date);
    Date addDay(int numDays = 1);
};

/** Checks if a date is valid.
       * @param date is the Date in format of string you want to check.
       * @return true if the date is valid.
*/
bool validDate(string date);

#endif //AEDA_UGHEATS_DATE_H
