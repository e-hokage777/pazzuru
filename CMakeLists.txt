cmake_minimum_required(VERSION 3.10)

## Includes
include(FetchContent)

project(pazzuru VERSION 1.0.0 LANGUAGES CXX C)

file(GLOB EXEC_SOURCES "src/*.cpp")

#-----------------------------
# Fetching external libraries
#-----------------------------

## glfw
fetchcontent_declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

## glm
fetchcontent_declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863 #refs/tags/1.0.1
)

## glad
fetchcontent_declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG v2.0.8
    GIT_SHALLOW ON
)

## stb
set(STB_INCLUDE_DIR ${CMAKE_BINARY_DIR}/_deps/stb)

file(MAKE_DIRECTORY ${STB_INCLUDE_DIR})

file(DOWNLOAD
    https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
    ${STB_INCLUDE_DIR}/stb_image.h
)


FetchContent_MakeAvailable(glfw glm glad)

# Include GLAD's CMake functions
add_subdirectory(${glad_SOURCE_DIR}/cmake glad_cmake)

glad_add_library(glad
    STATIC
    REPRODUCIBLE
    LOADER
    API gl:core=3.3
)

## loading opengl
find_package(OpenGL REQUIRED)


add_executable(${PROJECT_NAME} ${EXEC_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad glm::glm OpenGL::GL)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${STB_INCLUDE_DIR})
