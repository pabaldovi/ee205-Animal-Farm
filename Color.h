///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Color.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ostream>

enum class Color {
    UNKNOWN_COLOR,
    BLACK,
    WHITE,
    RED,
    BLUE,
    GREEN,
    PINK,
    CREAM,
    BROWN,
    CALICO,
    GINGER
};

inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color );
