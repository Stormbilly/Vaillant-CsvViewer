cmake_minimum_required(VERSION 3.20)
project("interactor.Tests" CXX)

add_executable(${PROJECT_NAME} Interactor.Tests.cpp)  
target_link_libraries(${PROJECT_NAME} PRIVATE gmock_main interactor)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTests)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
