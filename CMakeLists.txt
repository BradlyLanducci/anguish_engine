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

add_definitions(-DGLFW_INCLUDE_NONE=1)

add_library(glfw3
        STATIC
        IMPORTED
)

set_target_properties(glfw3
        PROPERTIES
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/Dependencies/lib/glfw3.lib
)

add_library(assimp
        SHARED
        IMPORTED
)

set_target_properties(assimp
        PROPERTIES
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/builds/Debug/assimp-vc143-mt.dll
        IMPORTED_IMPLIB ${PROJECT_SOURCE_DIR}/Dependencies/lib/assimp-vc143-mt.lib
)

add_subdirectory(core)
add_subdirectory(example)
