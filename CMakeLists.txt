cmake_minimum_required(VERSION 3.22)
project(ee205_lab_13a_animal_farm_3)

set(CMAKE_CXX_STANDARD 14 -Wall)

add_executable(ee205_lab_13a_animal_farm_3
        src/config.h
        src/main.cpp
        src/Cat.cpp src/Cat.h
        src/Weight.cpp src/Weight.h
        src/Gender.h
        src/Breed.cpp src/Breed.h
        src/Color.h
        src/Node.cpp src/Node.h
        src/List.cpp src/List.h
        src/SinglyLinkedList.cpp src/SinglyLinkedList.h
        src/Animal.cpp src/Animal.h
        src/Mammal.cpp src/Mammal.h)
