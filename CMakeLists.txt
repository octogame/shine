cmake_minimum_required(VERSION 3.3)
	
project(kivy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include)
set(${PROJECT_NAME} ${INCLUDE_DIRECTORIES}/${PROJECT_NAME})

set(SUBMODULES_ROOT "submodules/")

set(PROJ_ROOT_DIR ${CMAKE_SOURCE_DIR})


# setup part

add_subdirectory(${SUBMODULES_ROOT}/glad glad)
add_subdirectory(submodules/glfw)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


find_package(OpenGL REQUIRED)

# target part
if(DEV_TESTS)
	add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)
else()
	add_library(${PROJECT_NAME})
endif()

#target_sources(${PROJECT_NAME}
#	PRIVATE ${SOURCE_DIR}/main.cpp
#)


target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
