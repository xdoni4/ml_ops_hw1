cmake_minimum_required(VERSION 3.15)
project(cholesky_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(pybind11 REQUIRED)

pybind11_add_module(cholesky_cpp 
    cholesky/src/cholesky.cpp
    cholesky/python/bindings.cpp
)

target_include_directories(cholesky_cpp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/cholesky/src
)

install(TARGETS cholesky_cpp
        LIBRARY DESTINATION .
        RUNTIME DESTINATION .)
