#include "invalid_time_exception.h"

InvalidTimeException::InvalidTimeException(const Time &time)
    : std::invalid_argument("Given time is invalid: " + time.toString()) {}
