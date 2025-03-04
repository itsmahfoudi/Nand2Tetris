cmake_minimum_required(VERSION 3.0)
project(HackAssembler)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_STANDARD 17)

# Add the source files
set(SOURCES
    HackAssembler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Code.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Parser.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/Symbol.cpp
)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Inc)

# Add executable target
add_executable(HackAssembler ${SOURCES})
