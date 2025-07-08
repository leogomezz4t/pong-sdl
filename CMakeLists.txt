cmake_minimum_required(VERSION 3.5)
project(bitboarder LANGUAGES CXX)

# Make executables come out in bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

option(MAIN_VENDORED "Use vendored libraries" OFF)

if (MAIN_VENDORED)
    add_subdirectory(vendored/SDL3 EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
    Move library files to bin
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL3.dll
            DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endif()


file(GLOB sources src/*.cpp)

add_executable(bitboarder ${sources})

target_link_libraries(bitboarder PRIVATE SDL3::SDL3)