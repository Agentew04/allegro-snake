cmake_minimum_required(VERSION 3.22)
project(allegro-snake)

set(CMAKE_CXX_STANDARD 11)
set(SRC_DIR ./src)
set(BIN_DIR ./bin)
set(TEST_DIR ${SRC_DIR}/tests)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

# SOURCE CODE

set(MATH_FILES ${SRC_DIR}/Vec2I.cpp ${SRC_DIR}/Vec2F.cpp ${SRC_DIR}/math.cpp)
set(SOURCE_FILES ${SRC_DIR}/main.cpp ${SRC_DIR}/game.cpp
                 ${SRC_DIR}/options.cpp ${SRC_DIR}/snake.cpp)

add_executable(snake ${SOURCE_FILES} ${MATH_FILES})

target_include_directories(snake PRIVATE ${SRC_DIR})
target_link_libraries(snake allegro allegro_image allegro_primitives allegro_font allegro_ttf)


# TESTS

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test ${TEST_DIR}/mathtest.cpp ${MATH_FILES})
target_link_libraries(test ${GTEST_LIBRARIES} pthread )