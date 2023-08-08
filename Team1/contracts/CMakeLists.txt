cmake_minimum_required(VERSION 3.20)
project("contracts" CXX)

add_library(${PROJECT_NAME} INTERFACE Page.h)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})