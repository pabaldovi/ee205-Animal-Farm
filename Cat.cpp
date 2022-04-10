///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Cat.h"
#include "config.h"

using namespace std;

Cat::Cat() {

}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) {

}

char *Cat::getName() {
    return name;
}

void Cat::setName(const char *newName) {
    if (strlen(newName) == 0)
        throw invalid_argument("Cat name length must be > 0.");

    if (strlen(newName) > MAX_NAME_LENGTH)
        throw invalid_argument("Cat name length must be <= " + to_string(MAX_NAME_LENGTH));

    strcpy(name , newName);
}

Gender Cat::getGender() {
    return gender;
}

void Cat::setGender(Gender newGender) {
    if (gender != UNKNOWN_GENDER && newGender != UNKNOWN_GENDER)
        throw logic_error("Previous gender must be UNKNOWN_GENDER");

    Cat::gender = newGender;
}

Breed Cat::getBreed() {
    return PERSIAN;
}

void Cat::setBreed(Breed newBreed) {

}

bool Cat::isCatFixed() {
    return false;
}

void Cat::fixCat() {

}

Weight Cat::getWeight() {
    return 0;
}

void Cat::setWeight(Weight newWeight) {

}



