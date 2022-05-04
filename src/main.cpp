///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_13a_animal_farm_3 - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author Paulo Baldovi <pbaldovi@hawaii.edu>
/// @date   24_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include "config.h"
#include "SinglyLinkedList.h"
#include "Cat.h"

int main() {
    std::cout << "Starting " << PROGRAM_TITLE << std::endl ;
    SinglyLinkedList catDB ;
    catDB.push_front( new Cat( "Loki",  Color::CREAM, true,  Gender::MALE,   1.0 ) ) ;
    catDB.push_front( new Cat( "Milo",  Color::BLACK, true,  Gender::MALE,   1.1 ) ) ;
    catDB.push_front( new Cat( "Bella", Color::BROWN, true,  Gender::FEMALE, 1.2 ) ) ;
    catDB.push_front( new Cat( "Kali",  Color::CALICO, true, Gender::FEMALE, 1.3 ) ) ;
    catDB.push_front( new Cat( "Trin",  Color::WHITE, true,  Gender::FEMALE, 1.4 ) ) ;
    catDB.insert_after(catDB.get_first(), new Cat( "Chili", Color::GINGER, true,
                                                   Gender::MALE,   1.5 ) );
    for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal =
                                                                                     (Animal*)List::get_next( (Node*)pAnimal ) ) {
        std::cout << pAnimal->speak() << std::endl;
    }
    catDB.validate() ;
    catDB.dump() ;
    catDB.deleteAllNodes() ;
    catDB.dump() ;
    std::cout << "Done with " << PROGRAM_TITLE ;
    return( EXIT_SUCCESS ) ;
}