 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the OpenKuramoto Module
#

project(fdm)

include_directories(include)
set(SOURCE_LIB include/eulerscheme.h include/finitedifferencemethod.h include/rungekuttascheme.h
               src/eulerscheme.cpp src/finitedifferencemethod.cpp src/rungekuttascheme.cpp)
add_library(fdm STATIC ${SOURCE_LIB})

