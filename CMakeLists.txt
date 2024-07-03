cmake_minimum_required(VERSION 3.14.0)

# Project Name
project(DataManager)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Compiler Flags
set(CMAKE_CXX_FLAGS "-g -Wall ${CMAKE_CXX_FLAGS} -O0")

# Common Includes
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

# Enable FetchContent module
include(FetchContent)

# Fetch libxlsxwriter
FetchContent_Declare(
        libxlsxwriter
        GIT_REPOSITORY https://github.com/jmcnamara/libxlsxwriter.git
        GIT_TAG main
)
FetchContent_MakeAvailable(libxlsxwriter)

# Fetch libxls
FetchContent_Declare(
        libxls
        GIT_REPOSITORY https://github.com/libxls/libxls.git
        GIT_TAG master
)
FetchContent_MakeAvailable(libxls)

# Find Poppler using PkgConfig
find_package(PkgConfig REQUIRED)
pkg_check_modules(POPPLER REQUIRED poppler-cpp)

# Print the value of POPPLER_INCLUDE_DIRS and POPPLER_LIBRARY_DIRS
message("POPPLER_INCLUDE_DIRS: ${POPPLER_INCLUDE_DIRS}")
message("POPPLER_LIBRARY_DIRS: ${POPPLER_LIBRARY_DIRS}")

# Add Poppler include directories
include_directories(${POPPLER_INCLUDE_DIRS})

# Add Poppler library directories
link_directories(${POPPLER_LIBRARY_DIRS})

# Add subdirectories
add_subdirectory(src)
enable_testing()
add_subdirectory(test)

# Custom target to print compiler flags
add_custom_target(print-compiler-flags ALL
        COMMAND ${CMAKE_CXX_COMPILER} -E -x c++ - -v < /dev/null
)
