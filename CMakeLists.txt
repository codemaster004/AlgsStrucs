cmake_minimum_required(VERSION 3.27)
project(AlgsStrucs)

set(CMAKE_CXX_STANDARD 17)

add_executable(AlgsStrucs src/main.cpp
        src/lab1/polygonArea.cpp
        src/mergeSort.cpp
        src/lab2/bigNumSort.cpp
        src/lab2/quickSort.h
        src/lab2/quickSortTest.h
)
