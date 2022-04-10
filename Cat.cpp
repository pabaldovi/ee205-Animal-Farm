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
#include <cassert>
#include <iomanip>
#include "Cat.h"
#include "config.h"
#include "reportCats.h"

using namespace std;

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

Cat::Cat() {
    memset(name, 0, MAX_NAME_LENGTH);
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;
}

Cat::Cat(const char *newName, const Gender newGender, const Breed newBreed, const Weight newWeight) {
    setName(newName);
    setGender(newGender);
    setBreed(newBreed);
    setWeight(newWeight);
}

Cat::~Cat() {
    memset(name, 0, MAX_NAME_LENGTH);
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;
}

char *Cat::getName(){
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
    return breed;
}

void Cat::setBreed(Breed newBreed) {
    if (breed != UNKNOWN_BREED && newBreed != UNKNOWN_BREED)
        throw logic_error("Previous breed must be UNKNOWN_BREED");

    Cat::breed = newBreed;
}

bool Cat::isCatFixed() {
    return isFixed;
}

void Cat::fixCat() {
    Cat::isFixed = true;
}

Weight Cat::getWeight() {
    return weight;
}

void Cat::setWeight(Weight newWeight) {
    if (newWeight <= 0)
        throw invalid_argument("Weight must be > 0");

    Cat::weight = newWeight;
}

bool Cat::validate() {
    return true;
}

/// @returns true if everything worked correctly.  false if something goes
///          wrong
bool Cat::print() {
    assert( validate() ) ;
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Cat", "name" ) << getName() << endl;
    FORMAT_LINE( "Cat", "gender" ) << genderName(getGender()) << endl;
    FORMAT_LINE( "Cat", "breed" ) << breedName(getBreed()) << endl;
    FORMAT_LINE( "Cat", "isFixed" ) << isCatFixed() << endl;
    FORMAT_LINE( "Cat", "weight" ) << getWeight() << endl;
    return true ;
}
