file(GLOB DependencySourceFiles 
	${CMAKE_SOURCE_DIR}/dependencies/*.c
	${CMAKE_SOURCE_DIR}/dependencies/*.cpp
)

file(GLOB_RECURSE CoreSourceFiles 
    ${CMAKE_SOURCE_DIR}/core/*.cpp
)

set(SourceFiles
	${DependencySourceFiles}
	${CoreSourceFiles}
)
	
add_library(${PROJECT_NAME} 
    STATIC
    ${SourceFiles}
)

target_compile_features(${PROJECT_NAME} 
    PRIVATE 
        cxx_std_20
)

glad_add_library(glad_gl_core_33 REPRODUCIBLE API gl:core=3.3)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/Dependencies/
        ${CMAKE_SOURCE_DIR}/Dependencies/include
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_BINARY_DIR}/stb
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        glad_gl_core_33
        glfw
        glm::glm
        magic_enum
        miniaudio
)
