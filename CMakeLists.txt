cmake_minimum_required(VERSION 3.24)
project(linalgebra)

set(CMAKE_CXX_STANDARD 17)

include_directories(include data)

set(SOURCES
        source/Matrix.cpp
        source/Fraction.cpp
        source/Timer.cpp
        source/TUI.cpp
        source/main.cpp
        source/combinatorics.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

configure_file(data/matrix.txt matrix.txt COPYONLY)
configure_file(data/test.txt test.txt COPYONLY)
