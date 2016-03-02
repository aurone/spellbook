include_directories(${Eigen_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/spellbook/src/include)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(spellbook_tests main.cpp)

add_executable(matrix_test matrix_test.cpp)
target_link_libraries(matrix_test ${Boost_LIBRARIES})
