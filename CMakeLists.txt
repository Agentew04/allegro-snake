project(allegro-snake)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp snake.cpp options.cpp)

add_executable(allegro-snake.exe ${SOURCE_FILES})

target_link_libraries(allegro-snake.exe allegro allegro_image allegro_primitives allegro_font allegro_ttf)