///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file linkedList.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "linkedList.h"
#include "catDatabase.h"

bool addCat(Cat* newCat) {
    assert(isDatabaseValid());
    newCat -> Cat::validate();
    newCat -> next = catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat;
    currentCat++;
    assert(isDatabaseValid());
    return true;
}