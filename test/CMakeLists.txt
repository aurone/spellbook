include_directories(${Eigen_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/spellbook/src/include)

add_executable(spellbook_tests main.cpp)
add_executable(matrix_test matrix_test.cpp)

