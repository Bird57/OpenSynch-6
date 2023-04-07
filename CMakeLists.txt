cmake_minimum_required(VERSION 3.14)

project(OpenSynch-6 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


INCLUDE_DIRECTORIES ("C:/Program Files/Eigen3")
# find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
# find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

# Define of the OpenPH:
include_directories(OpenPH/math/algebra/include)
include_directories(OpenPH/math/mathlist/include)
include_directories(OpenPH/phys/physlist/include)
add_subdirectory(OpenPH/math/algebra)
add_subdirectory(OpenPH/math/mathlist)
add_subdirectory(OpenPH/phys/physlist)

# Define of this library (OpenKuramoto):
#include_directories(OpenKuramoto/fdm/include)
#include_directories(OpenKuramoto/model/include)
#include_directories(OpenKuramoto/object/include)
#include_directories(OpenKuramoto/selector/include)
#include_directories(OpenKuramoto/time/include)
#add_subdirectory(OpenKuramoto/fdm)
#add_subdirectory(OpenKuramoto/model)
#add_subdirectory(OpenKuramoto/object)
#add_subdirectory(OpenKuramoto/selector)
#add_subdirectory(OpenKuramoto/time)



# Define of this library (Module-Math):
include_directories(Module-Math/graph/include)
include_directories(Module-Math/fdm/include)
include_directories(Module-Math/selector/include)
include_directories(Module-Math/time/include)
add_subdirectory(Module-Math/graph)
add_subdirectory(Module-Math/fdm)
add_subdirectory(Module-Math/selector)
add_subdirectory(Module-Math/time)


# Define of this library (Module-MAC):
include_directories(Module-MAC/agent/include)
include_directories(Module-MAC/network/include)
include_directories(Module-MAC/protocol/include)
include_directories(Module-MAC/mas/include)
add_subdirectory(Module-MAC/agent)
add_subdirectory(Module-MAC/network)
add_subdirectory(Module-MAC/protocol)
add_subdirectory(Module-MAC/mas)

add_executable(main main.cpp)

target_link_libraries(main  	physlist
                                mathlist
                                graph
                                time
                                selector
                                fdm
                                agent
                                network
                                protocol
                                mas
                                ${SOURCE_LIB})


# add_executable(OpenSynch-2
#  main.cpp
#)

