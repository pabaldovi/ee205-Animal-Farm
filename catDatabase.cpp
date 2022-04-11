///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "catDatabase.h"
#include "Cat.h"

NumCats currentCat = 0;
Cat* catDatabaseHeadPointer = nullptr;

bool isDatabaseValid() {
    Cat* currentPointer = catDatabaseHeadPointer;
    while (currentPointer != nullptr) {
        assert(currentPointer -> Cat::validate());
        currentPointer = currentPointer -> next;
    }
    return true;
}