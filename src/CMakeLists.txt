cmake_minimum_required(VERSION 3.3)

project(shine CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJ_ROOT_DIR ${CMAKE_SOURCE_DIR})

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/include)
set(INCLUDE_DIR ${INCLUDE_DIRECTORIES}/${PROJECT_NAME})

find_package(glad CONFIG REQUIRED)

#if (GLAD_LIBRARY_FOUND)
	#	message(STATUS "glad founded")
	add_definitions(-DGLAD_LOADER)
	#else ()
	#	message(FATAL "glad not found")
	#endif ()



find_package(glfw3 CONFIG REQUIRED)

#if (GLFW_LIBRARY_FOUND)
#	message(STATUS "glfw founded")
	add_definitions(-DGLFW_BASED)
	#else ()
	#	message(FATAL "glfw not found")
	#endif ()


find_package(glm REQUIRED)


#if (GLM_LIBRARY_FOUND)
#	message(STATUS "glm founded")
#else ()
#	message(FATAL "glm not found")
#endif (GLFW_LIBRARY_FOUND)





add_library(${PROJECT_NAME})



target_sources(${PROJECT_NAME}
	PRIVATE ${INCLUDE_DIR}/IEngine.h
	PRIVATE ${INCLUDE_DIR}/CEngine.hpp
)
target_include_directories(${PROJECT_NAME}
	PRIVATE ${INCLUDE_DIR}
)



target_link_libraries(${PROJECT_NAME} PUBLIC glad::glad) # glad
target_link_libraries(${PROJECT_NAME} PUBLIC glfw) # glfw
target_link_libraries(${PROJECT_NAME} PUBLIC glm) # glm



















