cmake_minimum_required(VERSION 3.5)
project(pongsdl LANGUAGES CXX)

# Make executables come out in bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
# Move library files to bin
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/lib/SDL3.dll
        DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


file(GLOB sources src/*.cpp)

add_executable(pongsdl ${sources})

target_link_libraries(pongsdl PRIVATE SDL3::SDL3)