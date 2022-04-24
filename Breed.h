///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Breed.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ostream>

enum class Breed {
    UNKNOWN_BREED,
    MAINE_COON,
    MANX,
    SHORTHAIR,
    PERSIAN,
    SPHYNX
};

inline std::ostream& operator<<( std::ostream& lhs_stream, const Breed& rhs_Breed );