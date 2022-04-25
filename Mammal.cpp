///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "Mammal.h"
#include "config.h"

const std::string Mammal::MAMMAL_NAME = "Mammilian";

Mammal::Mammal(const Weight::t_weight newMaxWeight, const std::string &newSpecies)
        : Animal(newMaxWeight, MAMMAL_NAME, newSpecies) {
}

Mammal::Mammal(const Color newColor, const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newSpecies)
        : Animal(newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies) {
    color = newColor;
}

Color Mammal::getColor() const noexcept {
    return color;
}

void Mammal::setColor(const Color newColor) noexcept {
    color = newColor;
}

void Mammal::dump() const noexcept {
    assert(Animal::validate());
    Animal::dump();
    FORMAT_LINE_FOR_DUMP("Mammal", "color") << getColor() << std::endl;
}