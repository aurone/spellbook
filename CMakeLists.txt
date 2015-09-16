cmake_minimum_required(VERSION 2.8)
project(spellbook)

find_package(Boost REQUIRED system thread)

find_package(Eigen3)
if (${EIGEN3_FOUND})
    set(EIGEN_INCLUDES ${EIGEN3_INCLUDE_DIR})
else()
    find_package(Eigen REQUIRED)
    set(EIGEN_INCLUDES ${Eigen_INCLUDE_DIRS})
endif()

find_package(PkgConfig REQUIRED)

find_package(catkin REQUIRED)

catkin_package(
    INCLUDE_DIRS
        include
    LIBRARIES
        mapgen
    DEPENDS
        Boost
        Eigen)

set(BUILD_SHARED_LIBS On)

# inspect for c++11 flags
if (CMAKE_COMPILER_IS_GNUCXX)
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GNUCXX_VERSION)
    if (GNUCXX_VERSION VERSION_LESS 4.7)
        set(C11_FLAGS "-std=c++0x")
    else()
        set(C11_FLAGS "-std=c++11")
    endif()
else()
    message("Compiler is not g++. You're on your own for C++11 features")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${C11_FLAGS}")

set(CMAKE_BUILD_TYPE Release)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${Eigen_INCLUDE_DIRS})
include_directories(include)

add_subdirectory(src)

