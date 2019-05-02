cmake_minimum_required(VERSION 3.3)
	
project(kivy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJ_ROOT_DIR ${CMAKE_SOURCE_DIR})

message("libs prefix path is " ${LIBS_PREFIX_PATH})

list (APPEND CMAKE_PREFIX_PATH ${LIBS_PREFIX_PATH})

		# list(APPEND CMAKE_PREFIX_PATH "C:\\ProgrammingSoftware\\tools\\vcpkg\\packages\\")
if (GLAD_LOADER)
	message(STATUS "use glad boot")
	#	list(APPEND CMAKE_PREFIX_PATH "C:\\ProgrammingSoftware\\tools\\vcpkg\\packages\\glad_x86-windows")
	find_package(glad CONFIG REQUIRED)
	message(STATUS "glad inc dir "${GLAD_INCLUDE_DIR}" end")
	if (GLAD_LIBRARY_FOUND)
		message(STATUS "-- Found glad: glad32")
	else()
		message("why ?")
	endif()
	add_definitions(-DGLAD_LOADER)
elseif (GLEW_LOADER)
	message(STATUS " -- use glew boot")
	# list(APPEND CMAKE_PREFIX_PATH "C:\\ProgrammingSoftware\\tools\\vcpkg\\packages\\glew_x86-windows")
	find_package(GLEW REQUIRED)
	if (GLEW_LIBRARY_FOUND)
		message(STATUS "-- Found GLEW: glew")
	endif()
	add_definitions(-DGLEW_LOADER)
endif()

#if (WIN32) 
#	find_library(GDI32_LIBRARY gdi32)
# 	if(GDI32_LIBRARY_FOUND)
#		message(STATUS "GDI32 found")
#  		link_libraries(${GDI32_LIBRARY})
#	else()
#		message(FATAL "GDI32 notfound")
#	endif()
#endif()

find_package(OpenGL REQUIRED)


if (GLAD_LOADER)
	target_link_libraries(${PROJECT_NAME} ${GLAD_LIBRARY})
elseif(GLEW_LOADER)
	target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARY})
endif()

