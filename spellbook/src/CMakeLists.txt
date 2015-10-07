include_directories(${Eigen_INCLUDE_DIRS})
include_directories(include)

add_subdirectory(dubins)
add_subdirectory(mapgen)
add_subdirectory(memory)

install(
    DIRECTORY include/spellbook
    DESTINATION include
    FILES_MATCHING PATTERN "*.h")
