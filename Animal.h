///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include "Node.h"
#include "Gender.h"
#include "Weight.h"

class Animal : public Node {
    private:
        /*private attributes*/
        std::string species;
        std::string classification;
        Gender gender;
        Weight weight;

    protected:
        /*protected member function*/
        void setGender(const Gender newGender);

    public:
        /*public member functions*/
        Animal (const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies);
        Animal (const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight, const std::string &newClassification, const std::string &newSpecies);
        std::string getKingdom() const noexcept;
        std::string getClassification() const noexcept;
        std::string getSpecies() const noexcept;
        Gender getGender() const noexcept;
        Weight::t_weight getWeight() const noexcept;
        void setWeight(const Weight::t_weight newWeight);
        virtual std::string speak() const noexcept = 0;
        void dump() const noexcept override;
        bool validate() const noexcept override;

        /*static public member functions*/
        static bool validateClassification(const std::string &checkClassification) noexcept;
        static bool validateSpecies(const std::string &checkSpecies) noexcept;

        /*static public attribute*/
        static const std::string KINGDOM_NAME;
};