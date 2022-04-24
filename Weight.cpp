///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
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

const float Weight::UNKNOWN_WEIGHT = -1;
const float Weight::KILOS_IN_A_POUND = 0.453592;
const float Weight::SLUGS_IN_A_POUND = 0.031081;
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

Weight::Weight(float newWeight) {
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

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    bHasMax = false;
    setWeight(newWeight, newUnitOfWeight);
    bIsKnown = true;
    maxWeight = Weight::UNKNOWN_WEIGHT;
    assert(validate());
}

Weight::Weight(float newWeight, float newMaxWeight) {
    unitOfWeight = POUND;
    setWeight(newWeight);
    bIsKnown = true;
    setMaxWeight(newMaxWeight);
    bHasMax = true;
    assert(validate());
}

Weight::Weight(Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    bIsKnown = false;
    unitOfWeight = newUnitOfWeight;
    weight =  Weight::UNKNOWN_WEIGHT;
    setMaxWeight(newMaxWeight);
    bHasMax = true;
    assert(validate());
}

Weight::Weight(float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
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

float Weight::getWeight() const noexcept {
    return weight;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return convertWeight(getWeight(), getWeightUnit(), weightUnits);
}

float Weight::getMaxWeight() const noexcept {
    return maxWeight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

void Weight::setWeight(float newWeight) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    if (!bIsKnown)
        bIsKnown = true;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    unitOfWeight = weightUnits;
}

bool Weight::isWeightValid(float checkWeight) const noexcept {
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
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<(const Weight &rhs_Weight) const {
    float lhs_weight = (bIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.bIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

Weight &Weight::operator+=(float rhs_addToWeight) {
    weight += rhs_addToWeight;
    return *this;
}

float Weight::fromKilogramToPound(float kilogram) noexcept {
    return kilogram / KILOS_IN_A_POUND;
}

float Weight::fromPoundToKilogram(float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}

float Weight::fromSlugToPound(float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}

float Weight::fromPoundToSlug(float pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    float commonValue, toValue;
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

void Weight::setMaxWeight(float newMaxWeight) {
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