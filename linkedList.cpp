///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file linkedList.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include "linkedList.h"
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

void printAllCats() {
    assert(isDatabaseValid());
    Cat* temp = catDatabaseHeadPointer;
    while (temp != nullptr) {
        temp -> Cat::print();
        temp = temp -> next;
    }
}

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