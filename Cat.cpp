///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "Cat.h"
#include "config.h"

const std::string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight Cat::MAX_WEIGHT = 40;

std::string Cat::getName() const noexcept {
    return name;
}

void Cat::setName(const std::string &newName) {
    assert(validateName(newName));
    name = newName;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

void Cat::fixCat() noexcept {
    isCatFixed = true;
}

std::string Cat::speak () const noexcept {
    return "Meow";
}

void Cat::dump() const noexcept {
    assert(Cat::validate());
    Mammal::dump();
    FORMAT_LINE_FOR_DUMP("Cat", "name") << getName() << std::endl;
    FORMAT_LINE_FOR_DUMP("Cat", "isFixed") << isFixed() << std::endl;
}

bool Cat::validate() const noexcept {
    assert(Animal::validate());
    assert(validateName(getName()));
    return true;
}

bool Cat::validateName(const std::string &newName) {
    if (newName.empty())
        return false;

    return true;
}