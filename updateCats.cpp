///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "catDatabase.h"
#include "updateCats.h"
#include "config.h"

int updateCatName(int index, const char* newName) {
    if (validateIndex(index) == 0 && strlen(newName) > 0) {
        for (int i = 0; i < MAX_CATS; i++) {
            if (strcmp(cats[i].names, newName) ==  0) {
                //printf("Name not unique\n");
                fprintf(stderr, "%s: Cat name [%s] is already in the database.\n", PROGRAM_NAME, newName);
                return 1;
            }
        }
        strcpy(cats[index].names, newName);
        return 0;
    }
    return 1;
}

void fixCat(int index) {
    if (validateIndex(index) == 0) {
        cats[index].isFixedArr = true;
    }
}

void updateCatWeight(int index, Weight newWeight) {
    if (validateIndex(index) == 0) {
        if (newWeight > 0) {
            cats[index].weights = newWeight;
        }
    }
}

void updateCatCollar1(int index, const enum Color color) {
    if (validateIndex(index) == 0) {
        cats[index].collarColor1 = color;
    }
}

void updateCatCollar2(int index, const enum Color color) {
    if (validateIndex(index) == 0) {
        cats[index].collarColor2 = color;
    }
}

void updateLicense(int index, unsigned long long licenseNum) {
    if (validateIndex(index) == 0) {
        cats[index].license = licenseNum;
    }
}
