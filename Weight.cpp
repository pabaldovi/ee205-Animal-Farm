///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Weight.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Weight.h"

using namespace std;

#define FORMAT_LINE(className, member) cout << setw(8) << (className) << setw(20) << (member) << setw(52)

const Weight::t_weight Weight::UNKNOWN_WEIGHT = -1;
const Weight::t_weight Weight::KILOS_IN_A_POUND = 0.453592;
const Weight::t_weight Weight::SLUGS_IN_A_POUND = 0.031081;
const string Weight::POUND_LABEL = "Pound";
const string Weight::KILO_LABEL = "Kilo";
const string Weight::SLUG_LABEL = "Slug";

Weight::Weight() noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = POUND;
    weight =  Weight::UNKNOWN_WEIGHT;
    maxWeight = Weight::UNKNOWN_WEIGHT;
    assert(validate());
}

Weight::Weight(Weight::t_weight newWeight) {
    bHasMax = false;
    unitOfWeight = POUND;
    setWeight(newWeight);
    bIsKnown = true;
    maxWeight = Weight::UNKNOWN_WEIGHT;
    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight) noexcept {
    bIsKnown = false;
    bHasMax = false;
    unitOfWeight = newUnitOfWeight;
    weight =  Weight::UNKNOWN_WEIGHT;
    maxWeight = Weight::UNKNOWN_WEIGHT;
    assert(validate());
}

Weight::Weight(Weight::t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    bHasMax = false;
    setWeight(newWeight, newUnitOfWeight);
    bIsKnown = true;
    maxWeight = Weight::UNKNOWN_WEIGHT;
    assert(validate());
}

Weight::Weight(Weight::t_weight newWeight, Weight::t_weight newMaxWeight) {
    unitOfWeight = POUND;
    setWeight(newWeight);
    bIsKnown = true;
    setMaxWeight(newMaxWeight);
    bHasMax = true;
    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight) {
    bIsKnown = false;
    unitOfWeight = newUnitOfWeight;
    weight =  Weight::UNKNOWN_WEIGHT;
    setMaxWeight(newMaxWeight);
    bHasMax = true;
    assert(validate());
}

Weight::Weight(Weight::t_weight newWeight, Weight::UnitOfWeight newUnitOfWeight, Weight::t_weight newMaxWeight) {
    unitOfWeight = newUnitOfWeight;
    setWeight(newWeight);
    bIsKnown = true;
    setMaxWeight(newMaxWeight);
    bHasMax = true;
    assert(validate());
}

bool Weight::isWeightKnown() const noexcept {
    if (weight == UNKNOWN_WEIGHT)
        return false;
    return true;
}

bool Weight::hasMaxWeight() const noexcept {
    if (maxWeight == UNKNOWN_WEIGHT)
        return false;
    return true;
}

Weight::t_weight Weight::getWeight() const noexcept {
    return weight;
}

Weight::t_weight Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return convertWeight(getWeight(), getWeightUnit(), weightUnits);
}

Weight::t_weight Weight::getMaxWeight() const noexcept {
    return maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(Weight::t_weight newWeight) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    if (!bIsKnown)
        bIsKnown = true;
}

void Weight::setWeight(Weight::t_weight newWeight, Weight::UnitOfWeight weightUnits) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    unitOfWeight = weightUnits;
}

bool Weight::isWeightValid(Weight::t_weight checkWeight) const noexcept {
    assert(checkWeight > 0 || checkWeight == Weight::UNKNOWN_WEIGHT);
    if (bHasMax) {
        assert(checkWeight <= maxWeight);
    }
    return true;
}

bool Weight::validate() const noexcept {
    assert(isWeightValid(weight));
    assert(isWeightValid(maxWeight));
    return true;
}

void Weight::dump() const noexcept {
    cout << setw(80) << setfill( '=' ) << "" << endl ;
    cout << setfill( ' ' ) ;
    cout << left ;
    cout << boolalpha ;
    FORMAT_LINE( "Weight", "this" ) << this << endl;
    FORMAT_LINE( "Weight", "isKnown" ) << isWeightKnown() << endl;
    FORMAT_LINE( "Weight", "weight" ) << weight << endl;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << unitOfWeight << endl;
    FORMAT_LINE( "Weight", "hasMax" ) << hasMaxWeight() << endl;
    FORMAT_LINE( "Weight", "maxWeight" ) << maxWeight << endl;
}

bool Weight::operator==(const Weight &rhs_Weight) const {
    /// Remember to convert the two weight's units into a common unit!
    /// Treat unknown weights as 0 (so we can sort them without dealing
    /// with exceptions)
    Weight::t_weight lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    Weight::t_weight rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    Weight::t_weight lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    Weight::t_weight rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

Weight &Weight::operator+=(Weight::t_weight rhs_addToWeight) {
    weight += rhs_addToWeight;
    return *this;
}

Weight::t_weight Weight::fromKilogramToPound(Weight::t_weight kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}

Weight::t_weight Weight::fromPoundToKilogram(Weight::t_weight pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}

Weight::t_weight Weight::fromSlugToPound(Weight::t_weight slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}

Weight::t_weight Weight::fromPoundToSlug(Weight::t_weight pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}

Weight::t_weight Weight::convertWeight(Weight::t_weight fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    Weight::t_weight commonValue, toValue;
    switch (fromUnit) {
        case POUND:
            commonValue = fromWeight;
            break;
        case KILO:
            commonValue = fromKilogramToPound(fromWeight);
            break;
        case SLUG:
            commonValue = fromSlugToPound(fromWeight);
            break;
    }
    switch (toUnit) {
        case POUND:
            toValue = commonValue;
            break;
        case KILO:
            toValue = fromPoundToKilogram(commonValue);
            break;
        case SLUG:
            toValue = fromPoundToSlug(commonValue);
            break;
    }
    return toValue;
}

void Weight::setMaxWeight(Weight::t_weight newMaxWeight) {
//    assert(!hasMaxWeight());
    assert(isWeightValid(newMaxWeight));
    maxWeight = newMaxWeight;
    bHasMax = true;
}

std::ostream& operator<<( ostream& lhs_stream
        ,const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO:  return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG:  return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw out_of_range( "The unit can’t be mapped to a string" );
    }
}