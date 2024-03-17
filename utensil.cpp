#include "utensil.h"

#include <string>

std::string utensilToString(Utensil utensil) {
    switch (utensil) {
    case Utensil::Pot:
        return "Pot";
    case Utensil::Pan:
        return "Pan";
    case Utensil::CuttingBoard:
        return "Cutting Board";
    case Utensil::Knife:
        return "Knife";
    case Utensil::Bowl:
        return "Bowl";
    case Utensil::Oven:
        return "Oven";
    case Utensil::Strainer:
        return "Strainer";
    case Utensil::Spatula:
        return "Spatula";
    case Utensil::Spoon:
        return "Spoon";
    case Utensil::Whisk:
        return "Whisk";
    case Utensil::Grater:
        return "Grater";
    default:
        return "Unknown";
    }
}
