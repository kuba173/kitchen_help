#pragma once
#include "ingredient.h"
#include <string>
#include <unordered_map>
typedef unsigned int uint;

class Dish {
  private:
    std::string name;
    uint rating;
    std::string opinion;
    bool isValidRating() const;

  public:
    Dish(std::string);
    Dish(std::string, uint, std::string);

    std::string getName() const;
    uint getRating() const;
    std::string getOpinion() const;

    void setName(std::string);
    void setRating(uint);
    void setOpinion(std::string);
};

bool operator==(const Dish &, const Dish &);
std::ostream &operator<<(std::ostream &, const Dish &);
