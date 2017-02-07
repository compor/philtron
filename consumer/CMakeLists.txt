# cmake file

cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "philtron_consumer")

project(${PROJECT_NAME} C)


# requirements

if(NOT DEFINED MEMALLOC_ROOT)
  message(FATAL_ERROR "Memory allocator root directory was not specified")
endif()


# configuration

set(EXE_NAME ${PROJECT_NAME})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

link_directories("${MEMALLOC_ROOT}/lib")


add_executable(${EXE_NAME} 
  src/philtron_consumer.c)


target_include_directories(${EXE_NAME} PUBLIC "${MEMALLOC_ROOT}/include")

target_link_libraries(${EXE_NAME} "libjemalloc.so")


# installation

install(TARGETS ${EXE_NAME} RUNTIME DESTINATION "bin")

