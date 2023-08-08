cmake_minimum_required(VERSION 3.20)
project("domain.Tests" CXX)

set(PAGE_TEST "PageTest")
add_executable(${PAGE_TEST} PageTest.cpp)
set_target_properties(${PAGE_TEST} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTests)
target_link_libraries(${PAGE_TEST} PRIVATE gmock_main domain)
gtest_discover_tests(${PAGE_TEST})

set(CSV_LOADER_TEST "CSVLoaderTest")
add_executable(${CSV_LOADER_TEST} CSVLoaderTests.cpp)
set_target_properties(${CSV_LOADER_TEST} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTests)
target_link_libraries(${CSV_LOADER_TEST} PRIVATE gmock_main domain)
gtest_discover_tests(${CSV_LOADER_TEST})

set(FILE_LOADER_TEST "FileLoaderTest")
add_executable(${FILE_LOADER_TEST} FileLoaderTests.cpp)
set_target_properties(${FILE_LOADER_TEST} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTests)
target_link_libraries(${FILE_LOADER_TEST} PRIVATE gmock_main domain)
gtest_discover_tests(${FILE_LOADER_TEST})

set(FILE_CMD_LINE_TEST "CommandLineParserTests")
add_executable(${FILE_CMD_LINE_TEST} CommandLineArguments.Tests.cpp)
set_target_properties(${FILE_CMD_LINE_TEST} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTests)
target_link_libraries(${FILE_CMD_LINE_TEST} PRIVATE gmock_main domain)
gtest_discover_tests(${FILE_CMD_LINE_TEST})

file(COPY testInput.csv DESTINATION ${CMAKE_BINARY_DIR}/UnitTests)

include(GoogleTest)
