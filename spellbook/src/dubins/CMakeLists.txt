add_library(dubins dubins.cpp)

install(
    TARGETS dubins
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
