include_directories(${Eigen_INCLUDE_DIRS})
include_directories(include)

add_subdirectory(mapgen)

install(
    DIRECTORY include/spellbook
    DESTINATION include
    FILES_MATCHING PATTERN "*.h")
