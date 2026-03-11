cmake_minimum_required(VERSION 3.21)

project(AnguishEngine)

include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG master
        SOURCE_DIR ${CMAKE_BINARY_DIR}/glm
        BINARY_DIR ${CMAKE_BINARY_DIR}/glm_build
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
        magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG master
        SOURCE_DIR ${CMAKE_BINARY_DIR}/magic_enum
        BINARY_DIR ${CMAKE_BINARY_DIR}/magic_enum_build
)
FetchContent_MakeAvailable(magic_enum)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
        SOURCE_DIR ${CMAKE_BINARY_DIR}/glfw
        BINARY_DIR ${CMAKE_BINARY_DIR}/glfw_build
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
        miniaudio
        GIT_REPOSITORY https://github.com/mackron/miniaudio
        GIT_TAG master
        SOURCE_DIR ${CMAKE_BINARY_DIR}/miniaudio
        BINARY_DIR ${CMAKE_BINARY_DIR}/miniaudio_build
)
FetchContent_MakeAvailable(miniaudio)

add_compile_options("-Werror")

add_definitions(-DGLFW_INCLUDE_NONE=1)

add_subdirectory(core)
add_subdirectory(example)
