add_library(mapgen DFSMazeGenerator.cpp RandomMapGenerator.cpp)

install(
    TARGETS mapgen
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
