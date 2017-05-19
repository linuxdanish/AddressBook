cmake_minimum_required(VERSION 3.7)
project(FinalProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp CardType.cpp CardType.h LinkedList.cpp LinkedList.h AddressBook.cpp AddressBook.h)
add_executable(FinalProject ${SOURCE_FILES})