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
    Time() = default;
    Time(int hour, int min, int sec);
    Time(string time_str);
    //Metodos Set
    void setHour(int hour);
    void setMin(int min);
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
    friend ostream& operator<<(ostream& out, const Time &time);
    /** Add certain minutes to a Time.
       * @param min is the amount of minutes to add.
       * @return the Time updated.
*/
    Time addtime(int min);
};


#endif //AEDA_UGHEATS_TIME_H
