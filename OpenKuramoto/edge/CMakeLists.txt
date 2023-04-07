 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the OpenKuramoto Module
#

project(edge)

include_directories(include)
set(SOURCE_LIB include/edge.h include/staticedge.h include/dynamicedge.h
             src/edge.cpp src/staticedge.cpp src/dynamicedge.cpp)
add_library(edge STATIC ${SOURCE_LIB})
