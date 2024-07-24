# Set output directories for the test binaries and libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

# Pfad zur Excel-Datei
set(EXCEL_FILE "${PROJECT_SOURCE_DIR}/test/AOK Bayern_01012024_01.24-12.24.xlsx")

# Include directories for factories and common includes
set(FACTORIES_INCLUDES ${PROJECT_SOURCE_DIR}/test/ValueFactory/)
include_directories(${FACTORIES_INCLUDES})
include_directories(${COMMON_INCLUDES})

# Include FetchContent module
include(FetchContent)

# Fetch GoogleTest
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

# Include directories for GoogleTest
include_directories(${googletest_SOURCE_DIR}/googletest/include)

# Glob test source files
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
message("HEADER : ${TEST_SRC_FILES}")

# Glob factory source and header files
file(GLOB FACTORIES_SRC ${PROJECT_SOURCE_DIR}/test/ValueFactory/src/*.cpp)
file(GLOB FACTORIES_H ${PROJECT_SOURCE_DIR}/test/ValueFactory/include/*.h)

# Add library for factories
add_library(FACTORIES STATIC ${FACTORIES_H} ${FACTORIES_SRC})

# Add executable for running unit tests
add_executable(runUnitTest ${TEST_SRC_FILES})

# Kopieren der Excel-Datei ins Ausgabeverzeichnis
add_custom_command(
        TARGET runUnitTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${EXCEL_FILE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/test/ValueFactory)
include_directories(${POPPLER_INCLUDE_DIRS})

# Include GoogleTest
include(GoogleTest)

# Link libraries to the unit test executable
target_link_libraries(runUnitTest PRIVATE gtest gtest_main FACTORIES lib_extern ${POPPLER_LIBRARIES})

# Discover and add tests
gtest_discover_tests(runUnitTest)
