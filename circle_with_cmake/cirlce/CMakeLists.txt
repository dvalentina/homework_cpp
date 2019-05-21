cmake_minimum_required(VERSION 3.8)

project(circle)

# Use C++11 standard for compiling
set(CMAKE_CXX_STANDARD 11)

# Find SFML library
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Choose dynamic or static linking of SFML
if(WIN32)
    option(SFML_STATIC_LIBRARIES "Build the executable with static linking" ON)
endif(WIN32)

# Bring source files in src/ directory into the project
set(SOURCE_FILES src/main.cpp)

# Bring header files in include/ directory into the project
set(HEADER_FILES )

# Add all sources to target
add_executable(circle ${SOURCE_FILES} ${HEADER_FILES})

# Add paths to includes
target_include_directories(circle PUBLIC include)

# Linking
target_link_libraries(circle sfml-graphics sfml-window sfml-system)