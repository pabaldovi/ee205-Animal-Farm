///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>
#include "Cat.h"

#define MAX_CATS        (1024)

extern NumCats currentCat;
extern Cat* catDatabaseHeadPointer;

bool isDatabaseValid();

