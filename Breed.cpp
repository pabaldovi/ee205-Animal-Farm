///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file Breed.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Breed.h"
#include "config.h"

inline std::ostream& operator<<( std::ostream& lhs_stream, const Breed& rhs_Breed ) {
    switch( rhs_Breed ) {
        case Breed::UNKNOWN_BREED:
            lhs_stream << "Unknown breed";
            break;
        case Breed::MAINE_COON:
            lhs_stream << "Maine Coon";
            break;
        case Breed::MANX:
            lhs_stream << "Manx";
            break;
        case Breed::SHORTHAIR:
            lhs_stream << "Shorthair";
            break;
        case Breed::PERSIAN:
            lhs_stream << "Persian";
            break;
        case Breed::SPHYNX:
            lhs_stream << "Sphynx";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Breed not mapped to a string" );
    }
    return lhs_stream;
}