#pragma once
#include <iostream>
typedef unsigned int uint;

class Time {
  private:
    uint hour;
    uint minute;
    bool isValidTime() const;

  public:
    Time();
    Time(uint, uint);
    uint getHour() const;
    uint getMinute() const;
    void setHour(uint);
    void setMinute(uint);
    std::string toString() const;
};

bool operator==(const Time &, const Time &);
Time operator+(const Time &, const Time &);
void operator+=(Time &, const Time &);
std::ostream &operator<<(std::ostream &, const Time &);
std::istream &operator>>(std::istream &, Time &);
