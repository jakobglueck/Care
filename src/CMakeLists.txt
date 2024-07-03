# src/CMakeLists.txt

# Print debug message to verify POPPLER_INCLUDE_DIRS
message("POPPLER_INCLUDE_DIRS in src: ${POPPLER_INCLUDE_DIRS}")
message("POPPLER_LIBRARY_DIRS in src: ${POPPLER_LIBRARY_DIRS}")

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/include/*.h)

add_library(lib_extern ${SRC_FILES} ${HEADER_FILES})

# Include directories for the project
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${POPPLER_INCLUDE_DIRS})
include_directories(${CMAKE_BINARY_DIR}/_deps/libxlsxwriter-src/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/libxls-src/include)

# Link Poppler library
target_link_libraries(lib_extern PUBLIC ${POPPLER_LIBRARIES})
