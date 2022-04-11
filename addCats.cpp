///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "addCats.h"
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

/*
#include <stdio.h>
#include <string.h>
#include "catDatabase.h"

#include "config.h"

int addCat( const char name[],
            const enum Gender gender,
            const enum Breed breed,
            const bool isFixed,
            const Weight weight,
            const enum Color collar1,
            const enum Color collar2,
            const unsigned long long licenseNum) {

    for (int i = 0; i < MAX_CATS; i++) {
        if (strcmp(cats[i].names, name) == 0) {
            //printf("Name not unique\n");
            fprintf(stderr, "%s: Cat name [%s] is already in the database.\n", PROGRAM_NAME, name);
            return 1;
        }
    }

    if (validateIndex(currentCat) == 1) {
        fprintf(stderr, "%s: currentCat out of bounds.\n", PROGRAM_NAME);
        return 1;
    }

    if (strlen(name) == 0) {
        fprintf(stderr, "%s: Cat name [%s] is of invalid length.\n", PROGRAM_NAME, name);
        return 1;
    }

    if (strlen(name) > MAX_NAME_LENGTH) {
        fprintf(stderr, "%s: Cat name [%s] is of invalid length.\n", PROGRAM_NAME, name);
        return 1;
    }

    if (weight < 0) {
        fprintf(stderr, "%s: weight is of negative value.\n", PROGRAM_NAME);
        return 1;
    }

    strcpy(cats[currentCat].names, name);
    cats[currentCat].genders = gender;
    cats[currentCat].breeds = breed;
    cats[currentCat].isFixedArr = isFixed;
    cats[currentCat].weights = weight;
    cats[currentCat].collarColor1 = collar1;
    cats[currentCat].collarColor2 = collar2;
    cats[currentCat].license = licenseNum;
    currentCat++;
    return currentCat;
}*/
