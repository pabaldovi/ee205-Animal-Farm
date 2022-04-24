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

#include <iostream>
#include <cstring>
#include <cassert>
#include <iomanip>
#include "Cat.h"

using namespace std;

/// Format a line for printing the members of a class
#define FORMAT_LINE( className, member ) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

Cat::Cat() {
//    memset(name, 0, MAX_NAME_LENGTH);
    name = "";
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;
}

Cat::Cat(const string newName, const Gender newGender, const Breed newBreed, const Weight newWeight) {
    setName(newName);
    setGender(newGender);
    setBreed(newBreed);
    setWeight(newWeight);
}

Cat::~Cat() {
//    memset(name, 0, MAX_NAME_LENGTH);
    name = "";
    gender = UNKNOWN_GENDER;
    breed = UNKNOWN_BREED;
    isFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;
}

string Cat::getName(){
    return name;
}

void Cat::setName(const string newName) {
    assert(isNameValid(newName));
    name = newName;
}

Cat::Gender Cat::getGender() {
    return gender;
}

void Cat::setGender(Gender newGender) {
    if (gender != UNKNOWN_GENDER)
        throw logic_error("Previous gender must be UNKNOWN_GENDER");
    assert(isGenderValid(newGender));
    Cat::gender = newGender;
}

Cat::Breed Cat::getBreed() {
    return breed;
}

void Cat::setBreed(Breed newBreed) {
    if (breed != UNKNOWN_BREED)
        throw logic_error("Previous breed must be UNKNOWN_BREED");
    assert(isBreedValid(newBreed));
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
    assert(isWeightValid(newWeight));
    Cat::weight = newWeight;
}

bool Cat::isNameValid(const string newName) {
    if (newName.compare(nullptr) == 0)
        throw invalid_argument("Cat name must not be null");

    if (newName.length() == 0)
        throw invalid_argument("Cat name length must be > 0.");

    if (newName.length() >= MAX_NAME_LENGTH)
        throw invalid_argument("Cat name length must be <= " + to_string(MAX_NAME_LENGTH));

    return true;
}

bool Cat::isGenderValid(const Gender newGender) {
    if (newGender == UNKNOWN_GENDER)
        throw logic_error("New gender can not be unknown");

    return true;
}

bool Cat::isBreedValid(const Breed newBreed) {
    if (newBreed == UNKNOWN_BREED)
        throw logic_error("New breed can not be unknown");

    return true;
}

bool Cat::isWeightValid(const Weight newWeight) {
    if (newWeight <= 0)
        throw invalid_argument("Weight must be > 0");

    return true;
}

bool Cat::validate() {
    try {
        isNameValid(name);
        isGenderValid(gender);
        isBreedValid(breed);
        isWeightValid(weight);
    } catch (exception const& e) {
        cout << e.what() << endl;
        return false;
    }
    return true;
}

const string genderName(const enum Cat::Gender gender) {
    switch (gender) {
        case 0   :  return "Unknown gender";
        case 1   :  return "Male";
        case 2   :  return "Female";
        default  :  return "NULL";
    }
}

const string breedName(const enum Cat::Breed breed) {
    switch (breed) {
        case 0   :  return "Unknown breed";
        case 1   :  return "Maine coon";
        case 2   :  return "Manx";
        case 3   :  return "Shorthair";
        case 4   :  return "Persian";
        case 5   :  return "Sphynx";
        default  :  return "NULL";
    }
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
