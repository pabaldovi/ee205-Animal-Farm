///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "deleteCats.h"
#include "catDatabase.h"

bool deleteCat(Cat* targetPointer) {
    assert(isDatabaseValid());
    Cat* temp = catDatabaseHeadPointer;
    Cat* prev = nullptr;

    //check if head node holds targetPointer
    if (temp != nullptr && temp == targetPointer) {
        catDatabaseHeadPointer = temp -> next;
        delete temp;
        currentCat--;
        assert(isDatabaseValid());
        return true;
    }

    while (temp != nullptr && temp != targetPointer) {
        prev = temp;
        temp = temp -> next;
    }

    //after iterating through list, targetPointer was not found
    if (temp == nullptr)
        return false;

    //unlink node from list
    prev -> next = temp -> next;
    delete temp;
    currentCat--;
    assert(isDatabaseValid());
    return true;
}

void deleteAllCats() {
    assert(isDatabaseValid());
    while (catDatabaseHeadPointer != nullptr) {
        deleteCat(catDatabaseHeadPointer);
    }
    currentCat = 0;
}
/*
#include <string.h>
#include "catDatabase.h"


void deleteAllCats() {
    memset(cats, 0, sizeof(cats));
    currentCat = 0;
}

void deleteCat(int index) {
    if (validateIndex(index) == 0) {
        for (int i = index; i < MAX_CATS - 1; i++) {
            strcpy(cats[i].names, cats[i + 1].names);
            cats[i].genders = cats[i + 1].genders;
            cats[i].breeds = cats[i + 1].breeds;
            cats[i].isFixedArr = cats[i + 1].isFixedArr;
            cats[i].weights = cats[i + 1].weights;

        }
    }
}*/
