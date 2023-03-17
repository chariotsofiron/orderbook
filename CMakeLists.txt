cmake_minimum_required(VERSION 3.25.0)
project(orderbook)
set(CMAKE_CXX_STANDARD 17)


add_compile_options(
    # Reasonable and standard
    -Wall
    -Wextra
    # Others
    -Wpedantic
    -Wshadow
    -Wold-style-cast
    -Weffc++
    -Wformat
    -Wconversion
    -Wuninitialized
    -march=native
)

# Generate compile_commands.json to make it easier to work
# with clang based tools. Used in combination with Ninja.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(dependencies)

set(CMAKE_CXX_FLAGS_DEBUG_INIT "-fsanitize=address,undefined,integer -g")
