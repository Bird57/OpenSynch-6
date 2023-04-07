 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the OpenKuramoto Module
#

project(model)

include_directories(include)
set(SOURCE_LIB include/synchronizationmodel.h include/kuromotomodel.h
               src/synchronizationmodel.cpp src/kuromotomodel.cpp)
add_library(model STATIC ${SOURCE_LIB})

