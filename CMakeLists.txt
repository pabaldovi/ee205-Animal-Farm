cmake_minimum_required(VERSION 3.22)
project(ee205_lab_08d_animal_farm_1_to_clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_08d_animal_farm_1_to_clion
        catDatabase.cpp
        catDatabase.h
        config.h
        main.cpp
        Cat.cpp
        Cat.h
        linkedList.cpp
        linkedList.h
        Weight.cpp
        Weight.h)
