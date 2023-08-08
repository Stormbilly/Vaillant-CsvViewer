cmake_minimum_required(VERSION 3.20)
project("interactor" CXX)

add_library(${PROJECT_NAME} STATIC Interactor.cpp)
target_link_libraries(${PROJECT_NAME} contracts domain)
target_include_directories(${PROJECT_NAME} PUBLIC .)

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)