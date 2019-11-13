#ifndef AEDA_UGHEATS_TIME_H
#define AEDA_UGHEATS_TIME_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../utils.h"

using namespace std;

class Time {
private:
    int hour;
    int min;
    int sec;
public:
    /** Constructor default.
*/
    Time() = default;
    /** Constructor of a Time from the hour,minutes and seconds given.
       * @param hour.
       * @param min.
       * @param sec.
*/
    Time(int hour, int min, int sec);
    /** Constructor of a Time from a given time in the format of string.
       * @param time_str is the Time.
*/
    Time(string time_str);
    //Metodos Set
    /** Sets the hour of a Time.
       * @param hour is the parameter you want the new Time to have.
*/
    void setHour(int hour);
    /** Sets the minutes of a Time.
      * @param min is the parameter you want the new Time to have.
*/
    void setMin(int min);
    /** Sets the seconds of a Time.
      * @param hour is the parameter you want the new Time to have.
*/
    void setSec(int sec);
    //Metodos Get
    /**
       * @return the hour.
*/
    int getHour() const;
    /**
     * @return the minutes.
*/
    int getMin() const;
    /**
     * @return the seconds.
*/
    int getSec() const;
    //Other Methods
    /** Displays the Time in a nice format.
      * @param out is the ostream.
      * @param time is the Time you want to display.
*/
    friend ostream& operator<<(ostream& out, const Time &time);
    /** Add certain minutes to a Time.
       * @param min is the amount of minutes to add.
       * @return the Time updated.
*/
    Time addtime(int min);
};


#endif //AEDA_UGHEATS_TIME_H
