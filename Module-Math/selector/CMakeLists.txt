 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the OpenKuramoto Module
#

project(selector)

include_directories(include)
set(SOURCE_LIB include/selector.h include/intervalselector.h
               src/selector.cpp src/intervalselector.cpp)
add_library(selector  STATIC ${SOURCE_LIB})

