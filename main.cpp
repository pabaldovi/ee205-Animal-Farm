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
//#include "Cat.h"

using namespace std;

int main() {
   cout << "Starting " << PROGRAM_NAME << endl;

   addCat( new Cat("Loki",   Cat::MALE,     Cat::PERSIAN,    1.0 )) ;
   addCat( new Cat("Milo",   Cat::MALE,     Cat::MANX,       1.1 )) ;
   addCat( new Cat("Bella",  Cat::FEMALE,   Cat::MAINE_COON, 1.2 )) ;
   addCat( new Cat("Kali",   Cat::FEMALE,   Cat::SHORTHAIR,  1.3 )) ;
   addCat( new Cat("Trin",   Cat::FEMALE,   Cat::MANX,       1.4 )) ;
   addCat( new Cat("Chili",  Cat::MALE,     Cat::SHORTHAIR,  1.5)) ;
   printAllCats();
   deleteAllCats();
   printAllCats();
   /*
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