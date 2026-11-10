cmake_minimum_required(VERSION 3.10)

## Includes
include(FetchContent)

project(pazzuru VERSION 1.0.0 LANGUAGES CXX C)

file(GLOB EXEC_SOURCES CONFIGURE_DEPENDS "src/*.cpp")

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

# ---------------------------------------------------------
# 3. Fetch FreeType (truetype text rendering)
# ---------------------------------------------------------
FetchContent_Declare(
    freetype
    GIT_REPOSITORY https://github.com/freetype/freetype.git
    GIT_TAG VER-2-14-3
)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        6.2
)

# --- STRIP RAYLIB DOWN TO AUDIO ONLY ---
set(CUSTOMIZE_BUILD ON CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Disable graphic modules
set(SUPPORT_MODULE_RCORE OFF CACHE BOOL "" FORCE)
set(SUPPORT_MODULE_RSHAPES OFF CACHE BOOL "" FORCE)
set(SUPPORT_MODULE_RTEXTURES OFF CACHE BOOL "" FORCE)
set(SUPPORT_MODULE_RTEXT OFF CACHE BOOL "" FORCE)
set(SUPPORT_MODULE_RMODELS OFF CACHE BOOL "" FORCE)

# Ensure standalone audio mode is active
set(SUPPORT_MODULE_RAUDIO ON CACHE BOOL "" FORCE)


FetchContent_MakeAvailable(glm glad freetype raylib)
# FetchContent_MakeAvailable(glfw glm glad freetype raylib)

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
target_compile_definitions(${PROJECT_NAME} PRIVATE GLFW_INCLUDE_NONE) ## prevent GLFW from including OpenGL headers
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad glm::glm OpenGL::GL freetype raylib)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include ${STB_INCLUDE_DIR})
