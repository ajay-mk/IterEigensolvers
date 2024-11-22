cmake_minimum_required(VERSION 3.30)
project(DavidsonEigensolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(DavidsonEigensolver main.cpp
        src/davidson.cpp
        src/davidson.h)
