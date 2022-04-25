///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <ostream>

class Weight {
public:
    /*public types*/
    typedef float t_weight;
    enum UnitOfWeight {POUND, KILO, SLUG};

    /*public member functions*/
    Weight() noexcept;
    Weight(t_weight newWeight);
    Weight(UnitOfWeight newUnitOfWeight) noexcept;
    Weight(t_weight newWeight, UnitOfWeight newUnitOfWeight);
    Weight(t_weight newWeight, t_weight newMaxWeight);
    Weight(UnitOfWeight newUnitOfWeight, t_weight newMaxWeight);
    Weight (t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight);

    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    t_weight getWeight() const noexcept;
    t_weight getWeight(UnitOfWeight weightUnits) const noexcept;
    t_weight getMaxWeight() const noexcept;
    UnitOfWeight getWeightUnit() const noexcept;
    void setWeight(t_weight newWeight);
    void setWeight(t_weight newWeight, UnitOfWeight weightUnits);
    bool isWeightValid(t_weight checkWeight) const noexcept;
    bool validate() const noexcept;
    void dump() const noexcept;
    bool operator== (const Weight &rhs_Weight) const;
    bool operator< (const Weight &rhs_Weight) const;
    Weight &operator+= (t_weight rhs_addToWeight);

    /*static public member functions*/
    static t_weight fromKilogramToPound(t_weight kilogram) noexcept;
    static t_weight fromPoundToKilogram(t_weight pound) noexcept;
    static t_weight fromSlugToPound(t_weight slug) noexcept;
    static t_weight fromPoundToSlug(t_weight pound) noexcept;
    static t_weight convertWeight(t_weight fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit) noexcept;

    /*static public attributes*/
    static const t_weight UNKNOWN_WEIGHT;
    static const t_weight KILOS_IN_A_POUND;
    static const t_weight SLUGS_IN_A_POUND;
    static const std::string POUND_LABEL;
    static const std::string KILO_LABEL;
    static const std::string SLUG_LABEL;

private:
    /*private member functions*/
    void setMaxWeight(t_weight newMaxWeight);

    /*private attributes*/
    bool bIsKnown;
    bool bHasMax;
    enum UnitOfWeight unitOfWeight;
    t_weight weight;
    t_weight maxWeight;
};