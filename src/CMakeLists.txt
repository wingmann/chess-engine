set(TARGET chess_engine)

file(GLOB TARGET_PROJECT_SOURCES
    *.cpp
    ai/*.cpp
    conditions/*.cpp
    io/*.cpp
    pieces/*.cpp
    pieces/base/*.cpp
    pieces/types/*.cpp
    resource_management/*.cpp
    utility_components/*.cpp)

add_library(${TARGET} ${TARGET_PROJECT_SOURCES})