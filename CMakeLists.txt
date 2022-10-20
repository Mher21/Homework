cmake_minimum_required (VERSION 3.20)

project(my_project VERSION 0.0.1)
add_executable (Helloworld main.cpp)
set_target_properties(
    Helloworld PROPERTIES
    CXX_STANDART 11
    CXX_STANDART_REQUIRED ON
)
configure_file (config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
target_include_directories(
    Helloworld 
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
