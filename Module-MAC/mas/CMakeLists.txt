cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the Module-MAC
#

project(mas)

include_directories(include)
set(SOURCE_LIB include/masmodel.h include/linearmodel.h include/integratormodel.h
               src/masmodel.cpp src/linearmodel.cpp src/integratormodel.cpp)
add_library(mas  STATIC ${SOURCE_LIB})

