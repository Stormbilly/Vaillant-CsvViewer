cmake_minimum_required(VERSION 3.20)
project("domain" CXX)

add_library(${PROJECT_NAME} STATIC Domain.cpp)
target_link_libraries(${PROJECT_NAME} contracts)
target_include_directories(${PROJECT_NAME} PUBLIC .)

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)