cmake_minimum_required(VERSION 3.10)

# Project name and language
project(CodePad VERSION 0.0.1)

set(CMAKE_C_STANDART 99)
set(CMAKE_CXX_STANDARD 11)

# Define paths
set(CODEPAD_INCLUDE_DIR "include/")
set(CODEPAD_LIB_DIR "lib/")
set(CODEPAD_SRC_DIR "src/")
set(CODEPAD_BUILD_DIR "build/")
set(CODEPAD_MAIN_EXECUTABLE_NAME "CodePad")

# Define paths for libraries
set(GLFW_INCLUDE_DIR "${CODEPAD_INCLUDE_DIR}")
set(GLFW_LIB_DIR "${CODEPAD_LIB_DIR}")
set(CGLM_INCLUDE_DIR "${CODEPAD_INCLUDE_DIR}")
set(CGLM_LIB_DIR "${CODEPAD_LIB_DIR}")
set(GLAD_INCLUDE_DIR "${CODEPAD_INCLUDE_DIR}")
set(GLAD_SRC_DIR "${CODEPAD_SRC_DIR}/glad")       

# Add include directories
include_directories(${CODEPAD_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIR})
include_directories(${CGLM_INCLUDE_DIR})
include_directories(${GLAD_INCLUDE_DIR})

# Find all source files
file(GLOB SOURCES "${CODEPAD_SRC_DIR}*.cpp")

# Add the shared library for glad
add_library(glad SHARED ${GLAD_SRC_DIR}/glad.c)

# Set the library output directory
set_target_properties(glad PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CODEPAD_LIB_DIR})
set_target_properties(glad PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CODEPAD_LIB_DIR})

FILE(MAKE_DIRECTORY ${CODEPAD_BUILD_DIR})

# Add the executable for your project
add_executable(${CODEPAD_MAIN_EXECUTABLE_NAME} ${SOURCES})

# Link libraries to the executable
target_link_libraries(${CODEPAD_MAIN_EXECUTABLE_NAME}
    PRIVATE
    glad
    glfw3
    OpenGL32
    cglm
    -lm
)

set_target_properties(${CODEPAD_MAIN_EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CODEPAD_BUILD_DIR})

add_custom_target(run COMMAND ${CODEPAD_BUILD_DIR}${CODEPAD_MAIN_EXECUTABLE_NAME})
