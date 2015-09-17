cmake_minimum_required(VERSION 2.8)
project(spellbook)

# Attempt to find Eigen3 through a variety of methods:

# officially supported cmake find module
find_package(Eigen3)
if (${EIGEN3_FOUND})
    set(EIGEN_INCLUDES ${EIGEN3_INCLUDE_DIR})
else()
    # unofficially suported cmake find module
    find_package(Eigen)
    if (${EIGEN_FOUND})
        set(EIGEN_INCLUDES ${Eigen_INCLUDE_DIRS})
    else()
        # pkg-config file
        find_package(PkgConfig REQUIRED)
        pkg_check_module(Eigen REQUIRED Eigen3)
    endif()
endif()

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

include_directories(${Eigen_INCLUDE_DIRS})
include_directories(include)

add_subdirectory(src)

