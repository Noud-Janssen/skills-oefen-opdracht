# Minimum required CMake version
cmake_minimum_required(VERSION 3.14)

# Project name and version
project(magic_tool VERSION 1.0 LANGUAGES C CXX)

# Specify the C++ standard (if using C++, otherwise remove)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
# Fetch curlpp
FetchContent_Declare(
    curlpp
    GIT_REPOSITORY https://github.com/jpbarrette/curlpp.git
    GIT_TAG v0.8.0 # Use a specific tag or branch as needed
)

FetchContent_Declare(
    cxxopts
    GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
    GIT_TAG v3.2.1
)

# Fetch libcurl (curlpp dependency)
FetchContent_Declare(
    curl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG master # Use a specific tag or branch as needed
)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)

# Make content available
FetchContent_MakeAvailable(curl curlpp json cxxopts)

# Add sources (adjust the file names and paths)
set(SOURCES
    src/main.cpp
    src/app.cpp
    src/console.cpp
    src/controller/fetch.cpp
    src/controller/csv.cpp
    src/model/set.cpp
    src/model/date.cpp
)

# Add an executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    curlpp
    nlohmann_json::nlohmann_json
    cxxopts::cxxopts
)
