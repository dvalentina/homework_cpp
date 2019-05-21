cmake_minimum_required(VERSION 3.8)
project(snake)

# Use C++11 standard for compiling
set(CMAKE_CXX_STANDARD 11)

# Find SFML library
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Choose dynamic or static linking of SFML
if(WIN32)
    option(SFML_STATIC_LIBRARIES "Build the executable with static linking" ON)
endif(WIN32)

set(SOURCE_FILES 
    src/main.cpp
    src/apple.cpp 
    src/game.cpp
    src/message_box.cpp
    src/snake.cpp
    src/wall.cpp
    src/window.cpp
    src/world.cpp)

set(HEADER_FILES
    include/apple.h
    include/game.h
    include/message_box.h
    include/snake.h
    include/wall.h
    include/window.h
    include/world.h)

add_executable(snake
    ${SOURCE_FILES} ${HEADER_FILES})

# Add paths to include 
target_include_directories(snake PUBLIC include)

# Linking
target_link_libraries(snake sfml-graphics sfml-window sfml-system)