cmake_minimum_required(VERSION 3.22)
project(allegro-snake)

set(CMAKE_CXX_STANDARD 11)



# SOURCE CODE

set(MATH_FILES Vec2I.cpp Vec2F.cpp math.cpp)
set(SOURCE_FILES main.cpp game.cpp options.cpp snake.cpp)

add_executable(snake ${SOURCE_FILES} ${MATH_FILES})

target_include_directories(snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(snake allegro allegro_image allegro_primitives allegro_font allegro_ttf)


# TESTS

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(test tests/mathtest.cpp ${MATH_FILES})
target_link_libraries(test ${GTEST_LIBRARIES} pthread )