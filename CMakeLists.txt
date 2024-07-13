cmake_minimum_required(VERSION 3.14.0)

project(DataManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-g -Wall ${CMAKE_CXX_FLAGS} -O0")

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${COMMON_INCLUDES})

include(FetchContent)

FetchContent_Declare(
        libxlsxwriter
        GIT_REPOSITORY https://github.com/jmcnamara/libxlsxwriter.git
        GIT_TAG main
)
FetchContent_MakeAvailable(libxlsxwriter)

FetchContent_Declare(
        libxls
        GIT_REPOSITORY https://github.com/libxls/libxls.git
        GIT_TAG master
)
FetchContent_MakeAvailable(libxls)

find_package(PkgConfig REQUIRED)
pkg_check_modules(POPPLER REQUIRED poppler-cpp)

message("POPPLER_INCLUDE_DIRS: ${POPPLER_INCLUDE_DIRS}")
message("POPPLER_LIBRARY_DIRS: ${POPPLER_LIBRARY_DIRS}")

include_directories(${POPPLER_INCLUDE_DIRS})

link_directories(${POPPLER_LIBRARY_DIRS})

add_subdirectory(src)
enable_testing()
add_subdirectory(test)

add_custom_target(print-compiler-flags ALL
        COMMAND ${CMAKE_CXX_COMPILER} -E -x c++ - -v < /dev/null
)