 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the Module-MAC
#

project(protocol)

include_directories(include)
set(SOURCE_LIB include/protocol.h include/simpleprotocol.h include/nonadditiveprotocol.h include/targetprotocol.h include/connection.h
               src/protocol.cpp src/simpleprotocol.cpp src/nonadditiveprotocol.cpp src/targetprotocol.cpp src/connection.cpp)
add_library(protocol  STATIC ${SOURCE_LIB})

