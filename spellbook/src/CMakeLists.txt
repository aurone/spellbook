include_directories(${Eigen_INCLUDE_DIRS})
include_directories(include)

add_library(
    spellbook
    dubins/dubins.cpp
    log/logging.cpp
    mapgen/DFSMazeGenerator.cpp
    mapgen/RandomMapGenerator.cpp
    memory/StackAllocator.cpp
    memory/mempool.cpp)

install(
    DIRECTORY include/spellbook
    DESTINATION include
    FILES_MATCHING PATTERN "*.h")
install(
    TARGETS spellbook
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION lib)
