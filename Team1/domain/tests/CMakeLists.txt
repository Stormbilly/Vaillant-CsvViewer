cmake_minimum_required(VERSION 3.20)
project("domain.Tests" CXX)

add_executable(${PROJECT_NAME} PageTest.cpp CSVLoaderTests.cpp FileLoaderTests.cpp CommandLineArguments.Tests.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE gmock_main domain)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTests)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

file(COPY testInput.csv DESTINATION ${CMAKE_BINARY_DIR}/UnitTests)
