 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the OpenKuramoto Module
#

project(fdm)

include_directories(include)
set(SOURCE_LIB include/model.h include/eulerscheme.h include/finitedifferencemethod.h
               src/model.cpp src/eulerscheme.cpp src/finitedifferencemethod.cpp)
add_library(fdm  STATIC ${SOURCE_LIB})

