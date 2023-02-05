cmake_minimum_required(VERSION 3.25.0)
include(FetchContent)
project(orderbook)
set(CMAKE_CXX_STANDARD 20)

set(
    SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined,integer -g")

add_compile_options(
    -Wall -Wextra -Wpedantic -Weffc++ -Wshadow -Wformat
    -Wconversion -Wuninitialized -march=native
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE 
    ${PROJECT_SOURCE_DIR}/src
)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt)