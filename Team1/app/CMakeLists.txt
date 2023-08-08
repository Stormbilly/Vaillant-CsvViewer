cmake_minimum_required (VERSION 3.20)

project(app CXX)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Ui interactor)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#file(COPY questionnaire.txt DESTINATION ${CMAKE_BINARY_DIR}/bin)