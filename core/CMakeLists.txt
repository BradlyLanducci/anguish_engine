file(GLOB_RECURSE CoreSourceFiles 
    ${CMAKE_CURRENT_LIST_DIR}/*.cpp
)

set(SourceFiles
	${CoreSourceFiles}
)
	
add_library(${PROJECT_NAME} 
    STATIC
    ${SourceFiles}
)

target_compile_features(${PROJECT_NAME} 
    PRIVATE 
        cxx_std_23
)

glad_add_library(glad_gl_core_33 REPRODUCIBLE API gl:core=3.3)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${CMAKE_BINARY_DIR}/stb
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_BINARY_DIR}/jsoncpp/include
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        glad_gl_core_33
        glfw
        glm::glm
        magic_enum
        miniaudio
        JsonLib
)
