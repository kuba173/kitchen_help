#include "recipe.h"
#include <iostream>

Recipe::Recipe(std::string name, Difficulty difficulty, Time preparationTime)
    : name(name), difficulty(difficulty), preparationTime(preparationTime) {}

Recipe::Recipe(std::string name, Difficulty difficulty, Time preparationTime,
               std::unordered_map<Ingredient, Amount> requiredIngredients,
               std::unordered_set<Utensil> requiredUtensils)
    : name(name), difficulty(difficulty), preparationTime(preparationTime),
      requiredIngredients(requiredIngredients),
      requiredUtensils(requiredUtensils) {}

std::string Recipe::getName() const { return name; }

Time Recipe::getTime() const { return preparationTime; }

Difficulty Recipe::getDifficulty() const { return difficulty; }

std::unordered_map<Ingredient, Amount> Recipe::getIngredients() const {
    return requiredIngredients;
}

std::unordered_set<Utensil> Recipe::getUtensils() const {
    return requiredUtensils;
}

Amount Recipe::getIngredientAmount(Ingredient ingredient) {
    if (!requiredIngredients.contains(ingredient))
        return 0;

    return requiredIngredients[ingredient];
}

bool Recipe::hasUtensil(Utensil utenstil) {
    return requiredUtensils.contains(utenstil);
}

void Recipe::setName(std::string newName) { name = newName; }

void Recipe::setTime(Time newPreparationTime) {
    preparationTime = newPreparationTime;
}

void Recipe::setDifficulty(Difficulty newDifficulty) {
    difficulty = newDifficulty;
}

void Recipe::addIngredient(Ingredient newIngredient, Amount amount) {
    requiredIngredients[newIngredient] += amount;
}

void Recipe::addUtensil(Utensil utensil) { requiredUtensils.insert(utensil); }
