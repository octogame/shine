cmake_minimum_required(VERSION 3.3)
  
project(kivy)

set(PROJ_ROOT_DIR ${CMAKE_SOURCE_DIR})

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include)
set(INCLUDE_DIR ${INCLUDE_DIRECTORIES}/${PROJECT_NAME})

set(SUBMODULES_ROOT ${PROJ_ROOT_DIR}/submodules/)




include_directories(${CMAKE_SOURCE_DIR}/include)

# setup part

add_subdirectory(${SUBMODULES_ROOT}/glad glad)
add_subdirectory(${SUBMODULES_ROOT}/glfw glfw)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


find_package(OpenGL REQUIRED)

# target part
# add_executable(${PROJECT_NAME} main.cpp)

add_library(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
 PRIVATE ${SOURCE_DIR}/CEngine.cpp
 PRIVATE ${SOURCE_DIR}/CGame.cpp
 PRIVATE ${SOURCE_DIR}/CRender.cpp
)

target_sources(${PROJECT_NAME}
 PRIVATE ${INCLUDE_DIR}/CEngine.hpp
 PRIVATE ${INCLUDE_DIR}/IEngine.h
 PRIVATE ${INCLUDE_DIR}/CGame.hpp
 PRIVATE ${INCLUDE_DIR}/IGame.h
 PRIVATE ${INCLUDE_DIR}/CRender.hpp
 PRIVATE ${INCLUDE_DIR}/IRender.h

)


target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})