cmake_minimum_required(VERSION 3.20)
project("Ui" CXX)

add_library(${PROJECT_NAME} STATIC Ui.cpp)
target_link_libraries(${PROJECT_NAME} Contracts)
target_include_directories(${PROJECT_NAME} PUBLIC .)

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)