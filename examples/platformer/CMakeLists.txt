file(GLOB_RECURSE ExampleSourceFiles 
	${CMAKE_SOURCE_DIR}/examples/platformer/*.cpp
)

set(EXAMPLE_PROJECT ${PROJECT_NAME}_platformer)
	
add_executable(${EXAMPLE_PROJECT}
	${DependencySourceFiles}
	${CoreSourceFiles}    
    ${ExampleSourceFiles}
)

target_compile_features(${EXAMPLE_PROJECT} 
    PRIVATE 
        cxx_std_20
)

target_include_directories(${EXAMPLE_PROJECT} 
    PRIVATE
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_SOURCE_DIR}/Dependencies/
        ${CMAKE_SOURCE_DIR}/Dependencies/include
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_SOURCE_DIR}/examples/platformer
)

target_link_libraries(${EXAMPLE_PROJECT}
    AnguishEngine
)
