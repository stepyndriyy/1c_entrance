cmake_minimum_required(VERSION 3.19)
project(1c_entrance_task)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

set(SOURCES src/AI.cpp src/solitaire.cpp src/CardStack.cpp)
set(HEADERS src/AI.h src/solitaire.h src/CardStack.h)
add_library(lib ${SOURCES} ${HEADERS})

add_executable(1c_entrance_task main.cpp)
target_link_libraries(1c_entrance_task lib)