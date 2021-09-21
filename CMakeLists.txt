cmake_minimum_required(VERSION 3.17)
project(ADT_IteratedList___sll)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ADT_IteratedList___sll
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IteratedList.cpp
        IteratedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
