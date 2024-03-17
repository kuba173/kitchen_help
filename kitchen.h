#pragma once
#include "dish.h"
#include "recipe.h"
#include <queue>
#include <vector>

class Kitchen {
  private:
    std::queue<Recipe> recipesQueue;
    std::unordered_map<Ingredient, Amount> fridge;
    std::unordered_set<Utensil> drawer;
    std::vector<Dish> cookedDishes;

  public:
    Kitchen() = default;
    Kitchen(std::unordered_map<Ingredient, Amount>,
            std::unordered_set<Utensil>);

    std::vector<Dish> getCookedDishes() const;
    Recipe getNextRecipe() const;

    Amount getIngredientAmount(Ingredient);
    bool hasUtensil(Utensil);
    bool hasRecipes();
    bool checkRecipeIngredients();
    bool checkRecipeUtensil();

    void addRecipe(const Recipe &);
    void addIngredient(const Ingredient &, Amount);
    void addUtensil(const Utensil &);
    void addDish(const Dish &);

    void popRecipe();
    void removeIngredient(const Ingredient &, Amount);
    void removeUtensil(const Utensil &);
};
