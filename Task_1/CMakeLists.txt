cmake_minimum_required(VERSION 3.28)
project(Make_for_LB8)

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})