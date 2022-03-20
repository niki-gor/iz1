cmake_minimum_required(VERSION 3.0.0)
project(documents)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")

file(GLOB SOURCES "*.c" "**/*.c")
file(GLOB INCLUDE_DIRS include)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})