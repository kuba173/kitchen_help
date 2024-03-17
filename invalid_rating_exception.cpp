#include "invalid_rating_exception.h"
#include <string>

InvalidRatingException::InvalidRatingException(const Dish &dish)
    : std::invalid_argument(
          "Given rating for " + dish.getName() +
          " is invalid: " + std::to_string(dish.getRating())) {}
