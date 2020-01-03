#include "Time.h"

Time::Time(int hour, int min, int sec) {
    this->hour = hour;
    this->min = min;
    this->sec = sec;
    date = Date(0,0,0);
}

Time::Time(string time_str) {
    vector<string> tmp = strToVect(time_str, ':');
    this->hour =stoi(tmp.at(0));
    this->min = stoi(tmp.at(1));
    this->sec = stoi(tmp.at(2));
    date = Date(0, 0, 0);
}

Time::Time(int hour, int min, int sec, Date date):Time(hour, min, sec) {
    this->date = date;
}

Time::Time(const time_t &time) {
    tm* t = localtime(&time);
    this->hour = t->tm_hour;
    this->min = t->tm_min;
    this->sec = t->tm_sec;
    this->date = Date(t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
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

void Time::setDate(Date date) {
    this->date = date;
}

void Time::setTime(Time time) {
    hour = time.hour;
    min = time.min;
    sec = time.sec;
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

Date Time::getDate() const {
    return date;
}

//Other Methods
ostream &operator<<(ostream &out, const Time &time) {
    out << setfill('0') << right << setw(2) << to_string(time.hour);
    out << ":" << setfill('0') << setw(2) << to_string(time.min);
    out << ":" << setfill('0') << setw(2) << to_string(time.sec) << setfill(' ');
    return out;
}

Time Time::addtime(int min) {
    Time result = *this;
    result.min += min;
    result.hour += result.min / 60;
    result.date = result.date.addDay(result.hour / 24);
    result.min %= 60;
    result.hour %= 24;
    return result;
}

bool Time::operator<(const Time &t) {
    Date null_date = Date(0,0,0);
    if (date != null_date && t.getDate() != null_date) {
        if (date < t.getDate()) {
            return true;
        } else if (date == t.getDate() && hour < t.getHour()) {
            return true;
        } else if (date == t.getDate() && hour == t.getHour() && min < t.getMin()) {
            return true;
        } else if (date == t.getDate() && hour == t.getHour() && min == t.getMin() && sec < t.getSec()) {
            return true;
        }
    } else {
        if (date == t.getDate() && hour < t.getHour()) {
            return true;
        } else if (date == t.getDate() && hour == t.getHour() && min < t.getMin()) {
            return true;
        } else if (date == t.getDate() && hour == t.getHour() && min == t.getMin() && sec < t.getSec()) {
            return true;
        }
    }
    return false;
}

bool Time::operator>(const Time &t) {
    return !(*this < t) && !(*this == t);
}

bool Time::operator==(const Time &t) {
    return (hour == t.getHour() && min == t.getMin() && sec == t.getSec() && date == t.getDate());
}
