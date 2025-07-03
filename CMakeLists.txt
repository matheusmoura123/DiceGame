cmake_minimum_required(VERSION 3.14)
project(DiceGame VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include header files
include_directories(include)

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    main.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Optional: Add Windows GUI options (icon/resources)
# add_executable(${PROJECT_NAME} WIN32 ${SOURCES} resources.rc)

# Optional: Set as GUI app (no console window on Windows)
# set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
