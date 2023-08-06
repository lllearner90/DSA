cmake_minimum_required(VERSION 3.10)
include(CMakePrintHelpers)
project(Graphs)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/.)
enable_testing()
add_subdirectory(test)

set(BINARY ${CMAKE_PROJECT_NAME})

# file(GLOB SOURCES LIST_DIRECTORIES true *.h *.cpp)
set(SOURCES main.cpp
            graph.cpp
            adj_matrix_graph.cpp)
cmake_print_variables("sources are....\n ${SOURCES}")

add_executable(${BINARY} ${SOURCES})
add_library(${BINARY}_lib STATIC ${SOURCES}) 

target_include_directories(${BINARY} PUBLIC ("$(git rev-parse --show-toplevel)/googletest"))

