cmake_minimum_required(VERSION 2.8)

project (StockSimulation)
set(CMAKE_INSTALL_PREFIX "debug")
add_definitions(-Wall -Werror) # enable all warnings and mark warnings as errors
add_definitions(-O3)  # enable optimizations
add_definitions(-g)  # enable debugging 
add_definitions(-std=c++0x)  # use tr1
if(DEBUG)
   add_definitions(-DDEBUG)
endif()

add_subdirectory (source)
