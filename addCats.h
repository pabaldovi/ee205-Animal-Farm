///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include <stdbool.h>

extern int addCat(   const char name[],
                     const enum Gender gender,
                     const enum Breed breed,
                     const bool isFixed,
                     const Weight weight,
                     const enum Color collar1,
                     const enum Color collar2,
                     const unsigned long long licenseNum);
