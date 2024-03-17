#include "kitchen.h"

Kitchen::Kitchen(std::unordered_map<Ingredient, Amount> fridge,
                 std::unordered_set<Utensil> drawer)
    : fridge(fridge), drawer(drawer) {}

std::vector<Dish> Kitchen::getCookedDishes() const { return cookedDishes; }

Recipe Kitchen::getNextRecipe() const { return recipesQueue.front(); }

Amount Kitchen::getIngredientAmount(Ingredient ingredient) {
    if (!fridge.contains(ingredient))
        return 0;

    return fridge[ingredient];
}

bool Kitchen::hasUtensil(Utensil utenstil) { return drawer.contains(utenstil); }

bool Kitchen::hasRecipes() { return !recipesQueue.empty(); }

bool Kitchen::checkRecipeIngredients() {
    const auto &recipeIngredients = getNextRecipe().getIngredients();
    for (const auto &ingredientAmountPair : recipeIngredients) {
        const Ingredient &ingredient = ingredientAmountPair.first;
        const Amount &requiredAmount = ingredientAmountPair.second;

        if (!fridge.contains(ingredient) ||
            fridge[ingredient] < requiredAmount) {
            return false;
        }
    }

    return true;
}

bool Kitchen::checkRecipeUtensil() {
    const auto& recipeUtensils = getNextRecipe().getUtensils();
    for (const auto& utensil : recipeUtensils) {
        if (drawer.find(utensil) == drawer.end()) {
            return false;
        }
    }
    return true;
}

void Kitchen::addRecipe(const Recipe &recipe) { recipesQueue.push(recipe); }

void Kitchen::addIngredient(const Ingredient &ingredient, Amount amount) {
    fridge[ingredient] += amount;
}

void Kitchen::addUtensil(const Utensil &utensil) { drawer.insert(utensil); }

void Kitchen::addDish(const Dish &dish) { cookedDishes.push_back(dish); }

void Kitchen::popRecipe() { recipesQueue.pop(); }

void Kitchen::removeIngredient(const Ingredient &ingredient, Amount amount) {
    fridge[ingredient] -= amount;

    if (fridge[ingredient] == 0) {
        fridge.erase(ingredient);
    }
}

void Kitchen::removeUtensil(const Utensil &utensil) { drawer.erase(utensil); }
