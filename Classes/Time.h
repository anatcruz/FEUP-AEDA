#ifndef AEDA_UGHEATS_TIME_H
#define AEDA_UGHEATS_TIME_H


class Time {
public:
    int hour;
    int min;
    int sec;
    Time() = default;
    Time(int hour, int min, int sec);
};


#endif //AEDA_UGHEATS_TIME_H
