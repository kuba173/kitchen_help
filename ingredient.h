#pragma once

#include <string>

enum class Ingredient {
    Pasta,
    Salt,
    Water,
    Chicken,
    Pepper,
    Oil,
    Salad,
    Tomato,
    Cucumber,
    Cheese,
    Flour,
    Egg,
    Milk,
    Sugar,
    Chocolate,
    BakingPowder
};

std::string ingredientToString(Ingredient ingredient);
