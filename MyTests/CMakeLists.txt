cmake_minimum_required(VERSION 3.20)
project(MyTests)
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_SOURCES
        test.cpp
        test.h

        fieldgenerator.cpp
        fieldgenerator.h
)

add_executable(MyTests
        ${PROJECT_SOURCES}
    )