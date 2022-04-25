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
#include "Mammal.h"

class Cat : public Mammal {
    protected:
        /*protected attributes*/
        std::string name;
        bool isCatFixed;

    public:
        /*public member functions*/
        Cat(const std::string &newName)
            : Mammal(MAX_WEIGHT, SPECIES_NAME) {
                name = newName;
                isCatFixed = false;
        };
        Cat(const std::string &newName, const Color newColor, const bool newIsFixed, const Gender newGender, const Weight::t_weight newWeight)
            : Mammal(newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME) {
                name = newName;
                isCatFixed = false;
        };
        std::string getName() const noexcept;
        void setName(const std::string &newName);
        bool isFixed() const noexcept;
        void fixCat() noexcept;
        std::string speak () const noexcept override;
        void dump() const noexcept override;
        bool validate() const noexcept override;

        /*static public member function*/
        static bool validateName(const std::string &newName);

        /*static public attributes*/
        static const std::string SPECIES_NAME;
        static const Weight::t_weight MAX_WEIGHT;
};