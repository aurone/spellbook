cmake_minimum_required(VERSION 2.8)
project(testspellbook)

include(${CMAKE_SOURCE_DIR}/cmake/Modules/EnableCXX11.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/Modules/LocateEigen.cmake)

enable_cxx11()

locate_eigen()
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
find_package(spellbook REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Eigen_INCLUDE_DIRS})
include_directories(${spellbook_INCLUDE_DIRS})

add_executable(spellbook_tests main.cpp)

add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test ${Boost_LIBRARIES})

#add_executable(line_test line_test.cpp)
#target_link_libraries(line_test ${Boost_LIBRARIES})

add_executable(rotations_test rotations_test.cpp)
target_link_libraries(rotations_test ${Boost_LIBRARIES})
