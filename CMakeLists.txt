cmake_minimum_required(VERSION 3.20)
project(cpp_game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(raylib CONFIG REQUIRED)

add_executable(cpp_game
    src/main.cpp
    src/Spaceship.cpp
    src/game.cpp
    src/laser.cpp
)

target_link_libraries(cpp_game PRIVATE raylib)

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
    target_compile_definitions(cpp_game PRIVATE
        $<$<CONFIG:Debug>:_GLIBCXX_ASSERTIONS>
    )
elseif (MSVC)
    target_compile_options(cpp_game PRIVATE
        /W4
        $<$<CONFIG:Debug>:/Zi>
    )
endif()