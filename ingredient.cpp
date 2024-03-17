#include "ingredient.h"

#include <string>

std::string ingredientToString(Ingredient ingredient) {
    switch (ingredient) {
    case Ingredient::Pasta:
        return "Pasta";
    case Ingredient::Salt:
        return "Salt";
    case Ingredient::Water:
        return "Water";
    case Ingredient::Chicken:
        return "Chicken";
    case Ingredient::Pepper:
        return "Pepper";
    case Ingredient::Oil:
        return "Oil";
    case Ingredient::Salad:
        return "Salad";
    case Ingredient::Tomato:
        return "Tomato";
    case Ingredient::Cucumber:
        return "Cucumber";
    case Ingredient::Cheese:
        return "Cheese";
    case Ingredient::Flour:
        return "Flour";
    case Ingredient::Egg:
        return "Egg";
    case Ingredient::Milk:
        return "Milk";
    case Ingredient::Sugar:
        return "Sugar";
    case Ingredient::Chocolate:
        return "Chocolate";
    case Ingredient::BakingPowder:
        return "BakingPowder";
    default:
        return "Unknown";
    }
}
