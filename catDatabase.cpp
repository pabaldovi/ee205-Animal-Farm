///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "catDatabase.h"
#include "config.h"

int currentCat = 0;

struct Cat cats[MAX_CATS];

int validateIndex(int i) {
    if (i < 0 || i > MAX_CATS - 1) {
        fprintf(stderr, "%s: Index out of bounds.\n", PROGRAM_NAME);
        return 1;
    }
    return 0;
}