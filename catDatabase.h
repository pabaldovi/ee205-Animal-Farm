///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <stdbool.h>

#define MAX_NAME_LENGTH (50)
#define MAX_CATS        (1024)

enum Gender {
    UNKNOWN_GENDER,
    MALE,
    FEMALE
};
enum Breed {
    UNKNOWN_BREED,
    MAINE_COON,
    MANX,
    SHORTHAIR,
    PERSIAN,
    SPHYNX
};
enum Color {
    BLACK,
    WHITE,
    RED,
    BLUE,
    GREEN,
    PINK
};

typedef float Weight;
typedef int NumCats;

extern NumCats currentCat;

struct Cat {
    char names[MAX_NAME_LENGTH];
    enum Gender genders;
    enum Breed breeds;
    bool isFixedArr;
    Weight weights;
    enum Color collarColor1;
    enum Color collarColor2;
    unsigned long long license;
};

extern struct Cat cats[MAX_CATS];

extern int validateIndex(int i);

bool isCollarValid(const enum Color collar1, const enum Color collar2);