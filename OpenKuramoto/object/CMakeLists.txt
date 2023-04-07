 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the OpenKuramoto Module
#

project(object)

include_directories(include)
set(SOURCE_LIB include/oscillator.h include/oscillatorsystem.h include/materialpoint.h include/materialpointsystem.h include/edge.h include/staticedge.h include/dynamicedge.h
               src/oscillator.cpp src/oscillatorsystem.cpp src/materialpoint.cpp src/materialpointsystem.cpp src/edge.cpp src/staticedge.cpp src/dynamicedge.cpp)
add_library(object STATIC ${SOURCE_LIB})

