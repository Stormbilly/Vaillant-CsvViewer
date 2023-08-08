cmake_minimum_required(VERSION 3.20)
project("acceptance.tests" CXX)

add_executable(${PROJECT_NAME} Interactor.Tests.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE interactor gmock_main)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/AcceptanceTests)
file(COPY testInput.csv DESTINATION ${CMAKE_BINARY_DIR}/AcceptanceTests)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
