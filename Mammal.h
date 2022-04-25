///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Animal.h"
#include "Color.h"

class Mammal : public Animal {
    protected:
        /*protected attribute*/
        Color color;

    public:
        /*static public attribute*/
        static const std::string MAMMAL_NAME;

        /*public member functions*/
        Mammal(const Weight::t_weight newMaxWeight, const std::string &newSpecies);
        Mammal(const Color newColor, const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newSpecies);
        Color getColor() const noexcept;
        void setColor(const Color newColor) noexcept;
        void dump() const noexcept override;
};