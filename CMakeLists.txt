cmake_minimum_required(VERSION 3.23)

project(raytracer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/external/glm)
include_directories(${CMAKE_SOURCE_DIR}/external/imgui)
include_directories(${CMAKE_SOURCE_DIR}/external/gl3w/include)
include_directories(${CMAKE_SOURCE_DIR}/external/glfw/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glm)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/gl3w)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/imgui)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} src glfw gl3w imgui)