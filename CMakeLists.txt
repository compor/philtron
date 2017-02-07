# cmake file

cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "philtron")

project(${PROJECT_NAME} C CXX)


# requirements


# configuration

set(LIB_NAME ${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(${LIB_NAME} SHARED
  src/philtron.cpp)


# installation

install(DIRECTORY include DESTINATION .)
install(TARGETS ${LIB_NAME} LIBRARY DESTINATION "lib")

