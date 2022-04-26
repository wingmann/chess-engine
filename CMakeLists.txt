cmake_minimum_required(VERSION 3.22)
project(chess_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PROJECT_INCLUDE_DIR
    include
    include/ai
    include/conditions
    include/io
    include/pieces
    include/pieces/base
    include/pieces/types
    include/resource_management
    include/utility_components)

include_directories(${PROJECT_INCLUDE_DIR})

add_subdirectory(src)
