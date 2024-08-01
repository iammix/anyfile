cmake_minimum_required(VERSION 3.20)
project(neuroclue)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(${PROJECT_SOURCE_DIR}/external/json)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(neuroclue src/main.cpp
        src/FileDump.cpp
        src/CsvHandler.cpp
        src/FileDump.cpp
        src/JsonHandler.cpp)

# Platform-configs
if (WIN32)
    message(STATUS "Windows Configurations")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
elseif (UNIX)
    message(STATUS "Configuring for Unix/Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")
endif()


# Enable testing
enable_testing()

# Include tests directory
add_subdirectory(tests)