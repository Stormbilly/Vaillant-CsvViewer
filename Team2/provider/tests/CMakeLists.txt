cmake_minimum_required(VERSION 3.20)
project("provider.Tests" CXX)

enable_testing()

add_executable(${PROJECT_NAME} CSVFileProvider.Tests.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE gmock_main provider)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}
        )

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/UnitTests)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
add_test(NAME unit-tests COMMAND ${PROJECT_NAME} --gtest_output= "xml:./${PROJECT_NAME}.xml")
