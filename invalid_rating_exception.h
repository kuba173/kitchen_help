#pragma once
#include "dish.h"
#include <stdexcept>

class InvalidRatingException : public std::invalid_argument {
  public:
    InvalidRatingException(const Dish &);
};
