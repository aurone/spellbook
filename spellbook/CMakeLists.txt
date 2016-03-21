cmake_minimum_required(VERSION 2.8)
project(libspellbook)

include(${CMAKE_SOURCE_DIR}/cmake/Modules/EnableCXX11.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/Modules/LocateEigen.cmake)

set(SB_MAJOR_VER 0)
set(SB_MINOR_VER 0)
set(SB_PATCH_VER 0)
set(SB_VER ${SB_MAJOR_VER}.${SB_MINOR_VER}.${SB_PATCH_VER})

set(CMAKE_BUILD_TYPE Release)
enable_cxx11()

locate_eigen()

add_subdirectory(src)

configure_file(
    spellbook-config-version.cmake.in
    "${PROJECT_BINARY_DIR}/spellbook-config-version.cmake"
    @ONLY)

# export the build tree...

export(TARGETS dubins mapgen memory FILE spellbook-targets.cmake)

set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/src/include")
configure_file(
    spellbook-config.cmake.in
    "${PROJECT_BINARY_DIR}/spellbook-config.cmake"
    @ONLY)

export(PACKAGE spellbook)

# export the install tree...

if(WIN32)
    set(CMAKE_CONFIG_INSTALL_DST spellbook/cmake)
elseif(UNIX)
    set(CMAKE_CONFIG_INSTALL_DST share/spellbook/cmake)
endif()

set(CONF_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include")
configure_file(
    spellbook-config.cmake.in 
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/spellbook-config.cmake"
    @ONLY)

install(
    FILES
        "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/spellbook-config.cmake"
        "${PROJECT_BINARY_DIR}/spellbook-config-version.cmake"
    DESTINATION "${CMAKE_CONFIG_INSTALL_DST}")
