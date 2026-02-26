cmake_minimum_required(VERSION 3.20)
project(cpp_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# raylib from vcpkg (manifest mode via vcpkg.json)
find_package(raylib CONFIG REQUIRED)

add_executable(cpp_game src/main.cpp)

# Prefer modern imported target
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
        $<$<CONFIG:Debug>:-O0 -g3>
    )

    # Extra runtime checks for libstdc++ (helpful for vectors/strings)
    target_compile_definitions(cpp_game PRIVATE
        $<$<CONFIG:Debug>:_GLIBCXX_ASSERTIONS>
    )
elseif (MSVC)
    target_compile_options(cpp_game PRIVATE
        /W4
        $<$<CONFIG:Debug>:/Zi>
    )
endif()