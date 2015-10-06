cmake_minimum_required(VERSION 2.8)
project(spellbook)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules")
include(EnableCXX11)
include(LocateEigen)

set(SB_MAJOR_VER 0)
set(SB_MINOR_VER 0)
set(SB_PATCH_VER 0)
set(SB_VER ${SB_MAJOR_VER}.${SB_MINOR_VER}.${SB_PATCH_VER})

set(CMAKE_BUILD_TYPE Release)
enable_cxx11()

locate_eigen()

add_subdirectory(spellbook)
add_subdirectory(test)

set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/spellbook/src/include")
configure_file(
    spellbook-config.cmake.in
    "${PROJECT_BINARY_DIR}/spellbook-config.cmake"
    @ONLY)
configure_file(
    spellbook-config-version.cmake.in
    "${PROJECT_BINARY_DIR}/spellbook-config-version.cmake"
    @ONLY)

if(WIN32)
    set(CMAKE_CONFIG_INSTALL_DST spellbook/cmake)
elseif(UNIX)
    set(CMAKE_CONFIG_INSTALL_DST share/spellbook/cmake)
endif()

install(
    FILES
        "${PROJECT_BINARY_DIR}/spellbook-config.cmake"
        "${PROJECT_BINARY_DIR}/spellbook-config-version.cmake"
    DESTINATION "${CMAKE_CONFIG_INSTALL_DST}")
