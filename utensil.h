#pragma once

#include <string>

enum class Utensil {
    Pot,
    Pan,
    CuttingBoard,
    Knife,
    Bowl,
    Oven,
    Strainer,
    Spatula,
    Spoon,
    Whisk,
    Grater
};

std::string utensilToString(Utensil Utensil);
