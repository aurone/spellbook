cmake_minimum_required(VERSION 2.8)
project(spellbook)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules")

include(LocateEigen)
locate_eigen()

include(EnableCXX11)
enable_cxx11()

set(CMAKE_BUILD_TYPE Release)

add_subdirectory(src)

