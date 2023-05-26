cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

add_library(backend STATIC src/main.cpp)

file(GLOB BACKEND_SOURCES src/*.cpp src/*.c)
file(GLOB BACKEND_HEADERS inc/*.hpp inc/*.h)
file(GLOB BACKEND_SOURCES_DIRS src/**/*.cpp src/**/*.c)
file(GLOB BACKEND_HEADERS_DIRS inc/**/*.hpp inc/**/*.h)

target_sources(backend PRIVATE
    ${BACKEND_SOURCES}
    ${BACKEND_HEADERS}
    ${BACKEND_SOURCES_DIRS}
    ${BACKEND_HEADERS_DIRS}
)

target_include_directories(backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)