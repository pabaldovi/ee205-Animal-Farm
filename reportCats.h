///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Cat.h"

//void printCat(int index);
//void printAllCats();
//int findCat(const char name[]);
extern const char* genderName(const enum Cat::Gender gender);
extern const char* breedName(const enum Cat::Breed breed);
//extern const char* colorName (const enum Cat::Color color);
Cat* findCatByName(const char *name);
