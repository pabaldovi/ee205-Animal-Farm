///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <cassert>
#include <sstream>
#include "Animal.h"
#include "config.h"

const std::string Animal::KINGDOM_NAME = "Animalia";

void Animal::setGender(const Gender newGender) {
    if (gender != Gender::UNKNOWN_GENDER)
        throw std::logic_error("Gender is set and must not change");

    Animal::gender = newGender;
}


Animal::Animal (const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies) {
    assert(validateClassification(newClassification));
    assert(validateSpecies(newSpecies));
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
    assert(Animal::validate());
}

Animal::Animal (const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies) {
    assert(validateClassification(newClassification));
    assert(validateSpecies(newSpecies));
    gender = newGender;
    weight.setWeight(newWeight);
    weight.setMaxWeight(newMaxWeight);
    classification = newClassification;
    species = newSpecies;
    assert(Animal::validate());
}

std::string Animal::getKingdom() const noexcept {
    return KINGDOM_NAME;
}

std::string Animal::getClassification() const noexcept {
    return classification;
}

std::string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight();
}

void Animal::setWeight(const Weight::t_weight newWeight) {
    weight.setWeight(newWeight);
}

void Animal::dump() const noexcept {
    assert(Animal::validate());
    std::stringstream str_weight_buffer;
    str_weight_buffer << getWeight() << " out of " << weight.getMaxWeight() << " " << weight.getWeightUnit() ;

    Node::dump();
    FORMAT_LINE_FOR_DUMP("Animal", "this") << this << std::endl;
    FORMAT_LINE_FOR_DUMP("Animal", "kingdom") << getKingdom() << std::endl;
    FORMAT_LINE_FOR_DUMP("Animal", "classification") << getClassification() << std::endl;
    FORMAT_LINE_FOR_DUMP("Animal", "species") << getSpecies() << std::endl;
    FORMAT_LINE_FOR_DUMP("Animal", "gender") << getGender() << std::endl;
    FORMAT_LINE_FOR_DUMP("Animal", "weight") << str_weight_buffer.str() << std::endl;
}

bool Animal::validate() const noexcept {
    assert(validateClassification(getClassification()));
    assert(!getKingdom().empty());
    assert(validateSpecies(getSpecies()));
    assert(Node::validate());
    assert(weight.validate());
    return true;
}

bool Animal::validateClassification(const std::string &checkClassification) noexcept {
    if (checkClassification.empty()) {
        std::cout << "Classification must not be empty" << std::endl;
        return false;
    }

    return true;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {
    if (checkSpecies.empty()) {
        std::cout << "Species must not be empty" << std::endl;
        return false;
    }

    return true;
}