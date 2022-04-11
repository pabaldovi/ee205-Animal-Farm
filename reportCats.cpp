///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstring>
#include "catDatabase.h"
#include "reportCats.h"
#include "Cat.h"

/*void printCat(int i) {
    if (i < 0 || i > MAX_CATS) {
        printf("animalFarm0; Bad cat [%d]\n", i);
    } else {
        printf("cat index = [%d] "
               "name=[%s] "
               "gender=[%s] "
               "breed=[%s] "
               "isFixed=[%d] "
               "weight=[%f] "
               "collarColor1=[%s] "
               "collarColor2=[%s] "
               "license=[%llu]\n",  i, cats[i].names, genderName(cats[i].genders), breedName(cats[i].breeds),
               cats[i].isFixedArr, cats[i].weights,
               colorName(cats[i].collarColor1), colorName(cats[i].collarColor2), cats[i].license);
    }
}

void printAllCats() {
    for (int i = 0; i < MAX_CATS; i++) {
        printf("cat index = [%d] "
               "name=[%s] "
               "gender=[%s] "
               "breed=[%s] "
               "isFixed=[%d] "
               "weight=[%f] "
               "collarColor1=[%s] "
               "collarColor2=[%s] "
               "license=[%llu]\n",  i, cats[i].names, genderName(cats[i].genders), breedName(cats[i].breeds),
               cats[i].isFixedArr, cats[i].weights,
               colorName(cats[i].collarColor1), colorName(cats[i].collarColor2), cats[i].license);
    }
}

int findCat(const char name[]){
    for (int i = 0; i < MAX_CATS; i++) {
        if (strcmp(cats[i].names, name) ==  0) {
            return i;
        }
    }
    return 1;
}*/

const char* genderName(const enum Cat::Gender gender) {
    switch (gender) {
        case 0   :  return "Unknown gender";
        case 1   :  return "Male";
        case 2   :  return "Female";
        default  :  return "NULL";
    }
}

const char* breedName(const enum Cat::Breed breed) {
    switch (breed) {
        case 0   :  return "Unknown breed";
        case 1   :  return "Maine coon";
        case 2   :  return "Manx";
        case 3   :  return "Shorthair";
        case 4   :  return "Persian";
        case 5   :  return "Sphynx";
        default  :  return "NULL";
    }
}

//const char* colorName (const enum Color color) {
//    switch (color) {
//        case 0   :  return "Black";
//        case 1   :  return "White";
//        case 2   :  return "Red";
//        case 3   :  return "Blue";
//        case 4   :  return "Green";
//        case 5   :  return "Pink";
//        default  :  return "NULL";
//    }
//}

Cat* findCatByName(const char *name) {
    Cat* temp = catDatabaseHeadPointer;
    while (temp != nullptr) {
        if (strcmp(name, temp->getName()) == 0) {
            return temp;
        }
        temp = temp -> next;
    }
    return nullptr;
}
