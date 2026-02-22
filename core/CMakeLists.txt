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

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/Dependencies/
        ${CMAKE_SOURCE_DIR}/Dependencies/include
        ${CMAKE_SOURCE_DIR}/core
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        glfw3
        glm::glm
        assimp
        magic_enum        
)
