cmake_minimum_required(VERSION 3.21)

project(AnguishEngine)

include(dependencies.cmake)

populateDependencies()

add_compile_options("-Werror")

add_definitions(-DGLFW_INCLUDE_NONE=1)

add_subdirectory(core)
add_subdirectory(example)
