///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "catDatabase.h"
#include "addCats.h"
#include "deleteCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "config.h"

using namespace std;

int main() {
   cout << "Starting " << PROGRAM_NAME << endl;

   /*addCat( "Loki",   MALE,             PERSIAN,    true,    8.5,  BLACK, WHITE, 101 ) ;
   addCat( "Milo",   MALE,             MANX,       true,    7.0,  BLACK, RED,   102 ) ;
   addCat( "Bella",  FEMALE,           MAINE_COON, true,    18.2, BLACK, BLUE,  103 ) ;
   addCat( "Kali",   FEMALE,           SHORTHAIR,  false,   9.2,  BLACK, GREEN, 104 ) ;
   addCat( "Trin",   FEMALE,           MANX,       true,    12.2, BLACK, PINK,  105 ) ;
   addCat( "Chili",  UNKNOWN_GENDER,   SHORTHAIR,  false,   19.0, WHITE, BLACK, 106 ) ;
   printAllCats();
   int kali = findCat( "Kali" ) ;
   updateCatName( kali, "Chili" ) ; // this should fail
   printCat( kali );
   updateCatName( kali, "Capulet" ) ;
   updateCatWeight( kali, 9.9 ) ;
   updateCatCollar1(kali, WHITE);
   updateCatCollar2(kali, WHITE);
   updateLicense(kali, 123);
   fixCat( kali ) ;
   printCat( kali );
   printAllCats();
   deleteAllCats();
   addCat( "Loki",   MALE,             PERSIAN,    true,    8.5,  BLACK, WHITE, 101 ) ;
   deleteCat(0);
   printAllCats();
   //addCat( "Loki", MALE, PERSIAN, true, 8.5 ) ;
   //addCat( "Loki", MALE, PERSIAN, true, 8.5 ) ;*/

   cout << "Done with " << PROGRAM_NAME << endl;
   return 0;
}