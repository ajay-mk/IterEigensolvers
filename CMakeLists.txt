cmake_minimum_required(VERSION 3.30)
project(IterativeEigensolvers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
include(FeatureSummary)
include(CMakePackageConfigHelpers)

# Bring in TA
include(cmake/FindOrFetchTiledArray.cmake)

add_executable(solver main.cpp
        itersolvers/davidson.cpp
        itersolvers/davidson.h
        itersolvers/util.h
        itersolvers/meta.h
        itersolvers/solver.cpp
        itersolvers/solver.h)

include_directories(${CMAKE_SOURCE_DIR})

if (TARGET tiledarray)
    target_link_libraries(solver PRIVATE tiledarray)
else (TARGET tiledarray)
    message(FATAL_ERROR "did not find target tiledarray")
endif (TARGET tiledarray)
