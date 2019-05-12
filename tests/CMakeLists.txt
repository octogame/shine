cmake_minimum_required(VERSION 3.3)

project(shine_test CXX)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} shine)
include_directories(${CMAKE_SOURCE_DIR}/include)

if(WIN32)
  if (MSVC)
    #SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows")
    #set_target_properties(${PROJECT_NAME}_test PROPERTIES CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows)
  endif()
  if (MINGW)
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--subsystem,windows")
  endif()
endif(WIN32)
