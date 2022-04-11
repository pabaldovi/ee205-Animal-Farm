///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////
//#ifndef EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H
//#define EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H

#pragma once
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
        Cat(const char*     newName,
            const Gender    newGender,
            const Breed     newBreed,
            const Weight    newWeight);

        //Cat destructor
        virtual ~Cat();

        char *getName();
        void setName(const char *newName);

        Gender getGender();

        Breed getBreed();

        bool isCatFixed();
        void fixCat();

        Weight getWeight();
        void setWeight(Weight newWeight);

        bool isNameValid(const char *newName);
        bool isGenderValid(const Gender newGender);
        bool isBreedValid(const Breed newBreed);
        bool isWeightValid(const Weight newWeight);

        bool validate();
        bool print();
    protected:
        char name[MAX_NAME_LENGTH];
        enum Gender gender;
        enum Breed breed;
        bool isFixed;
        Weight weight;

        void setGender(Gender newGender);
        void setBreed(Breed newBreed);
};
//#endif //EE205_LAB_08D_ANIMAL_FARM_1_TO_CLION_CAT_H