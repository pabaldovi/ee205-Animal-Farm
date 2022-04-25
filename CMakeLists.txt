cmake_minimum_required(VERSION 3.22)
project(ee205_lab_13a_animal_farm_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_13a_animal_farm_3
        config.h
        main.cpp
        Cat.cpp Cat.h
        Weight.cpp Weight.h
        Gender.cpp Gender.h
        Breed.cpp Breed.h
        Color.cpp Color.h
        Node.cpp Node.h
        List.cpp List.h
        SinglyLinkedList.cpp SinglyLinkedList.h
        Animal.cpp Animal.h
        Mammal.cpp Mammal.h)
