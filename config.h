///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_animal_farm - EE 205 - Spr 2022
///
/// @file config.h
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   10_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <iomanip>

#define PROGRAM_TITLE "Animal Farm 3"
#define PROGRAM_NAME "animalfarm3"

#define PRINT_HEADING_FOR_DUMP                                              \
    /* Print =========================================================== */ \
    std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl

#define FORMAT_LINE_FOR_DUMP(className, member)                             \
    std::cout << std::setfill( ' ' )  /* Space pad    */                    \
              << std::left            /* Left justify */                    \
              << std::boolalpha  /* Print `true` or `false` for `bool`s */  \
              << std::setw( 8) << (className)                               \
              << std::setw(20) << (member)                                  \
              << std::setw(52)  /* (data) */
