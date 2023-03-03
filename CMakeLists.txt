cmake_minimum_required(VERSION 3.24)
project(SFML_PONG)

set(CMAKE_CXX_STANDARD 23)
find_package(SFML 2.5.1 COMPONENTS graphics)
set(SOURCES scr/main.cpp
            scr/pang.cpp
            scr/states/game_state.cpp
            scr/states/splashscreen_state.cpp
            scr/states/menu_state.cpp
            scr/states/playing_state.cpp
            scr/objects/visible_object.cpp)

add_executable(PANG ${SOURCES})
target_link_libraries(PANG sfml-graphics)
