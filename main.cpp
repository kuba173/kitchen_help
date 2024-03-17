#include "invalid_rating_exception.h"
#include "kitchen.h"
#include <iostream>

int main(int argc, char *argv[]) {
    std::unordered_map<Ingredient, Amount> pastaIngredients = {
        {Ingredient::Pasta, 150},
        {Ingredient::Salt, 5},
        {Ingredient::Water, 1500}};
    std::unordered_set<Utensil> pastaUtensils = {Utensil::Pot,
                                                 Utensil::Strainer};
    Recipe pastaRecipe("Pasta", Difficulty::Easy, Time(0, 30), pastaIngredients,
                       pastaUtensils);

    std::unordered_map<Ingredient, Amount> chickenIngredients = {
        {Ingredient::Chicken, 500},
        {Ingredient::Salt, 5},
        {Ingredient::Pepper, 5},
        {Ingredient::Oil, 10}};
    std::unordered_set<Utensil> chickenUtensils = {
        Utensil::Pan, Utensil::CuttingBoard, Utensil::Knife, Utensil::Spatula};
    Recipe chickenRecipe("Chicken", Difficulty::Medium, Time(1, 0),
                         chickenIngredients, chickenUtensils);

    std::unordered_map<Ingredient, Amount> saladIngredients = {
        {Ingredient::Salad, 200}, {Ingredient::Salt, 5},
        {Ingredient::Pepper, 5},  {Ingredient::Oil, 10},
        {Ingredient::Tomato, 50}, {Ingredient::Cucumber, 50},
        {Ingredient::Cheese, 25}};
    std::unordered_set<Utensil> saladUtensils = {
        Utensil::CuttingBoard, Utensil::Knife, Utensil::Bowl, Utensil::Spoon,
        Utensil::Grater};
    Recipe saladRecipe("Salad", Difficulty::Easy, Time(0, 15), saladIngredients,
                       saladUtensils);

    std::unordered_map<Ingredient, Amount> pizzaIngredients = {
        {Ingredient::Flour, 500}, {Ingredient::Salt, 5},
        {Ingredient::Water, 300}, {Ingredient::Oil, 10},
        {Ingredient::Tomato, 50}, {Ingredient::Cheese, 50}};
    std::unordered_set<Utensil> pizzaUtensils = {Utensil::CuttingBoard,
                                                 Utensil::Knife, Utensil::Oven};
    Recipe pizzaRecipe("Pizza", Difficulty::Hard, Time(2, 30), pizzaIngredients,
                       pizzaUtensils);

    std::unordered_map<Ingredient, Amount> cakeIngredients = {
        {Ingredient::Flour, 500},      {Ingredient::Sugar, 100},
        {Ingredient::Egg, 3},          {Ingredient::Oil, 100},
        {Ingredient::Chocolate, 200},  {Ingredient::Milk, 300},
        {Ingredient::BakingPowder, 10}};
    std::unordered_set<Utensil> cakeUtensils = {
        Utensil::CuttingBoard, Utensil::Knife, Utensil::Bowl,
        Utensil::Spoon,        Utensil::Oven,  Utensil::Whisk};
    Recipe cakeRecipe("Cake", Difficulty::Hard, Time(2, 0), cakeIngredients,
                      cakeUtensils);

    std::unordered_map<Ingredient, Amount> fridge = {
        {Ingredient::Pasta, 1000},   {Ingredient::Salt, 9},
        {Ingredient::Water, 2000},   {Ingredient::Chicken, 500},
        {Ingredient::Pepper, 4},     {Ingredient::Oil, 100},
        {Ingredient::Salad, 100},    {Ingredient::Tomato, 500},
        {Ingredient::Cucumber, 500}, {Ingredient::Cheese, 500},
        {Ingredient::Flour, 1000}};
    std::unordered_set<Utensil> drawer = {
        Utensil::Pot,          Utensil::Strainer, Utensil::Pan,
        Utensil::CuttingBoard, Utensil::Spatula,  Utensil::Bowl,
        Utensil::Spoon,        Utensil::Grater,   Utensil::Oven};
    Kitchen kitchen(fridge, drawer);

    std::vector<Recipe> Menu = {pastaRecipe, chickenRecipe, saladRecipe,
                                pizzaRecipe, cakeRecipe};
    std::cout << "Menu:" << std::endl;
    uint i = 1;
    char answer;
    for (auto recipe : Menu) {
        std::cout << std::endl << i << ". " << recipe.getName() << std::endl;
        i++;

        std::cout << "Do you want to order this recipe? (y/n): ";
        std::cin >> answer;
        if (answer == 'y') {
            kitchen.addRecipe(recipe);
        }
    }

    Time currentTime(8, 0);
    while (kitchen.hasRecipes()) {
        std::cout << "--------------------------------------------" << std::endl
                  << "Current time is: " << currentTime << std::endl
                  << std::endl;
        const auto &recipe = kitchen.getNextRecipe();

        if (kitchen.checkRecipeIngredients() && kitchen.checkRecipeUtensil()) {
            std::cout << "Enough ingredients and utensils to prepare "
                      << recipe.getName() << std::endl;

        } else {

            std::cout << "Not enough ingredients or utensils to prepare "
                      << recipe.getName() << ", going to the shop."
                      << std::endl;

            const auto &recipeIngredients = recipe.getIngredients();
            for (const auto &ingredientAmountPair : recipeIngredients) {
                const Ingredient &ingredient = ingredientAmountPair.first;
                const Amount &requiredAmount = ingredientAmountPair.second;

                if (kitchen.getIngredientAmount(ingredient) < requiredAmount) {
                    Amount missingAmount =
                        requiredAmount -
                        kitchen.getIngredientAmount(ingredient);
                    kitchen.addIngredient(ingredient, missingAmount);
                    std::cout << "\tAdded " << missingAmount << " of "
                              << ingredientToString(ingredient)
                              << " to the fridge" << std::endl;
                }
            }

            const auto &recipeUtensils = recipe.getUtensils();
            for (const auto &utensil : recipeUtensils) {
                if (!kitchen.hasUtensil(utensil)) {
                    kitchen.addUtensil(utensil);
                    std::cout << "\tAdded " << utensilToString(utensil)
                              << " to the drawer" << std::endl;
                }
            }

            currentTime += Time(0, 30);
        }

        std::cout << std::endl
                  << "Starting to prepare next recipe, current time is: "
                  << currentTime << std::endl;

        const auto &recipeIngredients = recipe.getIngredients();
        for (const auto &ingredientAmountPair : recipeIngredients) {
            const Ingredient &ingredient = ingredientAmountPair.first;
            const Amount &requiredAmount = ingredientAmountPair.second;

            kitchen.removeIngredient(ingredient, requiredAmount);
            std::cout << "\tRemoved " << requiredAmount << " of "
                      << ingredientToString(ingredient) << " from the fridge "
                      << std::endl;
        }
        currentTime += recipe.getTime();

        Dish dish(recipe.getName());
        uint rating;
        std::string opinion;
        bool invalidRating = true;

        std::cout << "Rate " << recipe.getName()
                  << " on the scale from 0 to 10:" << std::endl;

        while (invalidRating) {
            std::cin >> rating;

            try {
                dish.setRating(rating);
                invalidRating = false;
            } catch (const InvalidRatingException &e) {
                std::cout << "Enter a correct rating!" << std::endl;
            }
        }

        std::cout << "Enter your opinion on " << recipe.getName() << " :"
                  << std::endl;
        std::cin.ignore();
        std::getline(std::cin, opinion);
        dish.setOpinion(opinion);

        kitchen.addDish(dish);

        kitchen.popRecipe();
    }

    std::cout << "---------------------------------------" << std::endl
              << "All recipes are prepared, current time is: " << currentTime
              << std::endl
              << "Cooked dishes:" << std::endl
              << std::endl;

    i = 1;
    for (const auto &dish : kitchen.getCookedDishes()) {
        std::cout << i << ". " << dish << std::endl;
        i++;
    }

    return 0;
}
