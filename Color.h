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
#include "config.h"

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

inline std::ostream& operator<<( std::ostream& lhs_stream, const Color& rhs_Color ) {
    switch( rhs_Color ) {
        case Color::UNKNOWN_COLOR:
            lhs_stream << "Unknown color";
            break;
        case Color::BLACK:
            lhs_stream << "Black";
            break;
        case Color::WHITE:
            lhs_stream << "White";
            break;
        case Color::RED:
            lhs_stream << "Red";
            break;
        case Color::BLUE:
            lhs_stream << "Blue";
            break;
        case Color::GREEN:
            lhs_stream << "Green";
            break;
        case Color::PINK:
            lhs_stream << "Pink";
            break;
        case Color::CREAM:
            lhs_stream << "Cream";
            break;
        case Color::BROWN:
            lhs_stream << "Brown";
            break;
        case Color::CALICO:
            lhs_stream << "Calico";
            break;
        case Color::GINGER:
            lhs_stream << "Ginger";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Color not mapped to a string" );
    }
    return lhs_stream;
}