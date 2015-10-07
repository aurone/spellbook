add_library(memory mempool.cpp StackAllocator.cpp)

install(
    TARGETS memory
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
