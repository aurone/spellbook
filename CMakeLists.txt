cmake_minimum_required(VERSION 2.8)
project(spellbook)

include(cmake/Modules/EnableCXX11.cmake)
include(cmake/Modules/LocateEigen.cmake)

add_subdirectory(spellbook)
add_subdirectory(test)
