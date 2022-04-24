///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Gender.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Gender.h"
#include "config.h"

inline std::ostream& operator<<( std::ostream& lhs_stream, const Gender& rhs_Gender ){
    switch( rhs_Gender ) {
        case Gender::UNKNOWN_GENDER:
            lhs_stream << "Unknown gender";
            break;
        case Gender::MALE:
            lhs_stream << "Male";
            break;
        case Gender::FEMALE:
            lhs_stream << "Female";
            break;
        default:
            /// @throw out_of_range If the enum is not mapped to a string.
            throw std::out_of_range( PROGRAM_NAME ": Gender not mapped to a string" );
    }
    return lhs_stream;
}