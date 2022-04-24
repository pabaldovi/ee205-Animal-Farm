///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>

using namespace std;

#define MAX_NAME_LENGTH (50)
#define UNKNOWN_WEIGHT  (-1)

typedef float Weight;
typedef int NumCats;

class Cat {
    public:
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

        Cat *next;

        // Cat constructor with no parameters
        Cat();
        // Cat constructor with all fields for valid cat
        Cat(const string    newName,
            const Gender    newGender,
            const Breed     newBreed,
            const Weight    newWeight);

        //Cat destructor
        virtual ~Cat();

        string getName();
        void setName(const string newName);

        Gender getGender();
        void setGender(Gender newGender);

        Breed getBreed();
        void setBreed(Breed newBreed);

        bool isCatFixed();
        void fixCat();

        Weight getWeight();
        void setWeight(Weight newWeight);

        bool isNameValid(const string newName);
        bool isGenderValid(const Gender newGender);
        bool isBreedValid(const Breed newBreed);
        bool isWeightValid(const Weight newWeight);

        bool validate();
        bool print();
    protected:
//        char name[MAX_NAME_LENGTH];
        string name;
        enum Gender gender;
        enum Breed breed;
        bool isFixed;
        Weight weight;
};

extern const string genderName(const enum Cat::Gender gender);
extern const string breedName(const enum Cat::Breed breed);