message("POPPLER_INCLUDE_DIRS in src: ${POPPLER_INCLUDE_DIRS}")
message("POPPLER_LIBRARY_DIRS in src: ${POPPLER_LIBRARY_DIRS}")

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB PDF_FILES ${PROJECT_SOURCE_DIR}/src/*.pdf)

add_library(lib_extern ${SRC_FILES} ${HEADER_FILES} ${PDF_FILES})

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${POPPLER_INCLUDE_DIRS})
include_directories(${CMAKE_BINARY_DIR}/_deps/libxlsxwriter-src/include)
include_directories(${CMAKE_BINARY_DIR}/_deps/libxls-src/include)

target_link_libraries(lib_extern PUBLIC ${POPPLER_LIBRARIES} xlsreader xlsxwriter)