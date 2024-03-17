#pragma once
#include "ingredient.h"
#include "time.h"
#include "utensil.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

typedef uint Amount;
enum class Difficulty { Easy, Medium, Hard };

class Recipe {
  private:
    std::string name;
    Difficulty difficulty;
    Time preparationTime;
    std::unordered_map<Ingredient, Amount> requiredIngredients;
    std::unordered_set<Utensil> requiredUtensils;

  public:
    Recipe(std::string, Difficulty, Time);
    Recipe(std::string, Difficulty, Time,
           std::unordered_map<Ingredient, Amount>, std::unordered_set<Utensil>);

    std::string getName() const;
    Time getTime() const;
    Difficulty getDifficulty() const;
    std::unordered_map<Ingredient, Amount> getIngredients() const;
    std::unordered_set<Utensil> getUtensils() const;

    Amount getIngredientAmount(Ingredient);
    bool hasUtensil(Utensil);

    void setName(std::string);
    void setTime(Time);
    void setDifficulty(Difficulty);

    void addIngredient(Ingredient, Amount);
    void addUtensil(Utensil);
};
