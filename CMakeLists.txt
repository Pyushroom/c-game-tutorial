cmake_minimum_required(VERSION 3.20)
project(cpp_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

add_executable(cpp_game src/main.cpp)
target_link_libraries(cpp_game PRIVATE raylib)

# --- Warnings / quality flags ---
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(cpp_game PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Wsign-conversion
    )
endif()

# --- Debug-friendly options ---
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(cpp_game PRIVATE -O0 -g3)
        # Extra runtime checks for libstdc++ (helpful for vectors/strings)
        target_compile_definitions(cpp_game PRIVATE _GLIBCXX_ASSERTIONS)
    endif()
endif()

