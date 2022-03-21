///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

extern int updateCatName(int index, const char* newName);
extern void fixCat(int index);
extern void updateCatWeight(int index, float newWeight);
extern void updateCatCollar1(int index, const enum Color color);
extern void updateCatCollar2(int index, const enum Color color);
extern void updateLicense(int index, unsigned long long licenseNum);
