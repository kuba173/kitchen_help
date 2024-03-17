/*
@author Michał Sadlej
class Time:
represents a time,
stores the hour and minute,
defaults to 00:00.
*/

#include "time.h"
#include "invalid_time_exception.h"
#include <iomanip>
#include <stdexcept>

Time::Time() : hour(0), minute(0) {}

Time::Time(uint hour, uint minute) : hour(hour), minute(minute) {
    if (!isValidTime()) {
        throw InvalidTimeException(*this);
    }
}

uint Time::getHour() const { return hour; }

uint Time::getMinute() const { return minute; }

void Time::setHour(uint newHour) {
    hour = newHour;

    if (!isValidTime()) {
        throw InvalidTimeException(*this);
    }
}

void Time::setMinute(uint newMinute) {
    minute = newMinute;

    if (!isValidTime()) {
        throw InvalidTimeException(*this);
    }
}

std::string Time::toString() const {
    std::stringstream stream;
    stream << *this;
    return stream.str();
}

bool Time::isValidTime() const { return minute < 60 && hour < 24; }

bool operator==(const Time &first, const Time &second) {
    return first.getHour() == second.getHour() &&
           first.getMinute() == second.getMinute();
}

Time operator+(const Time &first, const Time &second) {
    uint resultMinute = first.getMinute() + second.getMinute();
    uint resultHour = first.getHour() + second.getHour();

    if (resultMinute >= 60) {
        resultMinute -= 60;
        resultHour += 1;
    }
    if (resultHour >= 24) {
        resultHour -= 24;
    }

    return Time(resultHour, resultMinute);
}

void operator+=(Time &first, const Time &second) { first = first + second; }

std::ostream &operator<<(std::ostream &stream, const Time &time) {
    stream << std::setfill('0') << std::setw(2) << time.getHour() << ":"
           << std::setw(2) << time.getMinute();
    return stream;
}

std::istream &operator>>(std::istream &stream, Time &time) {
    uint hour;
    uint minute;
    char separator;

    stream >> hour >> separator >> minute;
    time.setHour(hour);
    time.setMinute(minute);

    return stream;
}
