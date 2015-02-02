cmake_minimum_required(VERSION 2.8)
project(spellbook)

find_package(Boost REQUIRED system thread)

find_package(Eigen REQUIRED)
include_directories(${Eigen_INCLUDE_DIRS})

find_package(PkgConfig REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    geometry_msgs
    moveit_msgs
    nav_msgs
    octomap_msgs
    octomap_ros
    roscpp
    rosbag
    sbpl_geometry_utils
    sensor_msgs
    std_msgs
    tf
    trajectory_msgs
    visualization_msgs)

pkg_check_modules(openni REQUIRED libopenni)
include_directories(${openni_INCLUDE_DIRS})
link_directories(${openni_LIBRARY_DIRS})

catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS
    DEPENDS Boost Eigen)
include_directories(${catkin_INCLUDE_DIRS})

include_directories(include)

set(BUILD_SHARED_LIBS On)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(CMAKE_BUILD_TYPE Release)

add_subdirectory(src)

