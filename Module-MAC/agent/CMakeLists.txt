 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the Module-MAC
#

project(agent)

include_directories(include)
set(SOURCE_LIB include/agent.h include/mathagent.h include/collective.h
               src/agent.cpp src/mathagent.cpp src/collective.cpp)
add_library(agent  STATIC ${SOURCE_LIB})

