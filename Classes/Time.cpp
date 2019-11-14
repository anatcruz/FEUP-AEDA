#include "Time.h"

Time::Time(int hour, int min, int sec) {
    this->hour = hour;
    this->min = min;
    this->sec = sec;
}

Time::Time(string time_str) {
    vector<string> tmp = strToVect(time_str, ':');
    this->hour =stoi(tmp.at(0));
    this->min = stoi(tmp.at(1));
    this->sec = stoi(tmp.at(2));
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
    out << ":" << setfill('0') << setw(2) << to_string(time.sec) << setfill(' ');
    return out;
}

Time Time::addtime(int min) {
    Time result(0,0,0);
    result.min = this->min + min;
    result.hour = this->hour + this->min / 60;
    result.min %= 60;
    result.hour %= 24;
    return result;
}
