#ifndef AEDA_UGHEATS_TIME_H
#define AEDA_UGHEATS_TIME_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hour;
    int min;
    int sec;
public:
    Time() = default;
    Time(int hour, int min, int sec);
    //Metodos Set
    void setHour(int hour);
    void setMin(int min);
    void setSec(int sec);
    //Metodos Get
    int getHour() const;
    int getMin() const;
    int getSec() const;
    //Other Methods
    friend ostream& operator<<(ostream& out, const Time &time);
    Time addtime(int min);
};


#endif //AEDA_UGHEATS_TIME_H
