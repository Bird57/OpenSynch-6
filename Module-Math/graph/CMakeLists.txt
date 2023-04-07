 
cmake_minimum_required(VERSION 3.0.0)

# List internal includes needed.

#include_directories(${CMAKE_SOURCE_DIR})

#
# Define the Module-Math
#

project(graph)

include_directories(include)
set(SOURCE_LIB include/edge.h include/staticedge.h include/vertex.h include/graph.h include/undirectedge.h include/graphgenerator.h include/circlegraph.h include/wattsstrogatzgraph.h include/linegraph.h
               src/edge.cpp src/staticedge.cpp src/vertex.cpp src/graph.cpp src/undirectedge.cpp src/graphgenerator.cpp src/circlegraph.cpp src/wattsstrogatzgraph.cpp src/linegraph.cpp)
add_library(graph  STATIC ${SOURCE_LIB})

