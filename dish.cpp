#include "dish.h"
#include "invalid_rating_exception.h"
#include <iostream>

Dish::Dish(std::string name) : name(name) {}
Dish::Dish(std::string name, uint rating, std::string opinion)
    : name(name), rating(rating), opinion(opinion) {
    if (!isValidRating()) {
        throw InvalidRatingException(*this);
    }
}

bool Dish::isValidRating() const { return rating <= 10; }

std::string Dish::getName() const { return name; }

uint Dish::getRating() const { return rating; }

std::string Dish::getOpinion() const { return opinion; }

void Dish::setName(std::string newName) { name = newName; }

void Dish::setRating(uint newRating) {
    rating = newRating;

    if (!isValidRating()) {
        throw InvalidRatingException(*this);
    }
}

void Dish::setOpinion(std::string newOpinion) { opinion = newOpinion; }

bool operator==(const Dish &first, const Dish &second) {
    return first.getName() == second.getName();
}

std::ostream &operator<<(std::ostream &stream, const Dish &dish) {
    stream << dish.getName() << " " << dish.getRating() << "/10"
           << ", opinion:\n\t" << dish.getOpinion() << std::endl;
    return stream;
}
