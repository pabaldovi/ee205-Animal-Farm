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

void printCat(int index);
void printAllCats();
int findCat(const char name[]);
extern char* genderName(const enum Gender gender);
extern char* breedName(const enum Breed breed);
extern char* colorName (const enum Color color);
