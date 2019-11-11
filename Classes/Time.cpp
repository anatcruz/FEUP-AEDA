#include "Time.h"

Time::Time(int hour, int min, int sec) {
    this->hour = hour;
    this->min = min;
    this->sec = sec;
}

//Metodos Set
void Time::setHour(int hour) {
    this->hour = hour;
}

void Time::setMin(int min) {
    this->min = min;
}

void Time::setSec(int sec) {
    this->sec = sec;
}

//Metodos Get
int Time::getHour() const {
    return hour;
}

int Time::getMin() const {
    return min;
}

int Time::getSec() const {
    return sec;
}

//Other Methods
ostream &operator<<(ostream &out, const Time &time) {
    out << setfill('0') << right << setw(2) << to_string(time.hour);
    out << ":" << setfill('0') << setw(2) << to_string(time.min);
    out << ":" << setfill('0') << setw(2) << to_string(time.sec);
    return out;
}
