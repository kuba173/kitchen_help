#pragma once
#include "time.h"
#include <stdexcept>

class InvalidTimeException : public std::invalid_argument {
  public:
    InvalidTimeException(const Time &);
};
