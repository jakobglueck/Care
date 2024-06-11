#[[
Created by Jakob Glück 2024

Copyright © 2024 CARENOBLE Gesellschaft für Gesundheitsökonomie mbH & Co. KG

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
]]

# Use Version greater than 3.11 to use Fetch-Content
CMAKE_MINIMUM_REQUIRED(VERSION 3.14.0)

# SET name of the Project
PROJECT(DataManager)
# create execute command
SET(CMAKE_CXX_FLAGS "-g -Wall ${CMAKE_CXX_FLAGS} -O0")

# set the c++ standard
SET(CMAKE_CXX_STANDARD 17)

#  make include-directory public to the other files
SET(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${COMMON_INCLUDES})

# enable Fetch-Content use cases
INCLUDE(FetchContent)

# Fetch and include libxlsxwriter
FetchContent_Declare(
        libxlsxwriter
        GIT_REPOSITORY https://github.com/jmcnamara/libxlsxwriter.git
        GIT_TAG        main
)
FetchContent_MakeAvailable(libxlsxwriter)

# Fetch and include libxls
FetchContent_Declare(
        libxls
        GIT_REPOSITORY https://github.com/libxls/libxls.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(libxls)

# link src-directory
ADD_SUBDIRECTORY(src)

# allow Unit-Tests
ENABLE_TESTING()

# link test-directory
ADD_SUBDIRECTORY(test)
