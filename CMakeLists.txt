cmake_minimum_required(VERSION 3.10)

project(Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(calculator_lib STATIC
    calculator.cpp
)

target_include_directories(calculator_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(calculator
    main.cpp
)

target_link_libraries(calculator PRIVATE calculator_lib)