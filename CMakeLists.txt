cmake_minimum_required(VERSION 3.30)
project(DavidsonEigensolver)

set(CMAKE_CXX_STANDARD 17)

# Bring in TA
include(cmake/FindOrFetchTiledArray.cmake)

add_executable(solver main.cpp
        src/davidson.cpp
        src/davidson.h
        src/util.h)

if (TARGET tiledarray)
    target_link_libraries(solver PRIVATE tiledarray)
else (TARGET tiledarray)
    message(FATAL_ERROR "did not find target tiledarray")
endif (TARGET tiledarray)


