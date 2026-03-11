function(populateDependencies)
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

    FetchContent_Declare(
            stb
            GIT_REPOSITORY https://github.com/nothings/stb
            GIT_TAG master
            SOURCE_DIR ${CMAKE_BINARY_DIR}/stb
    )
    FetchContent_MakeAvailable(stb)

    FetchContent_Declare(
            glad
            GIT_REPOSITORY https://github.com/Dav1dde/glad.git
            GIT_TAG        glad2
            SOURCE_DIR ${CMAKE_BINARY_DIR}/glad
            SOURCE_SUBDIR  cmake
    )
    FetchContent_MakeAvailable(glad)
endfunction()