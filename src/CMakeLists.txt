add_library(src Image.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

target_link_libraries(src glfw gl3w)