///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file linkedList.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Cat.h"

bool addCat(Cat* newCat);
bool deleteCat(Cat* targetPointer);
void deleteAllCats();
void printAllCats();
Cat* findCatByName(const string name);