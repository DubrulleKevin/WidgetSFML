#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(WidgetSFML)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

include_directories("include")

file(
        GLOB_RECURSE
        source_files
        src/*.cpp
)

# Define sources and executable
set(EXECUTABLE_NAME "WidgetSFML")
add_executable(${EXECUTABLE_NAME} ${source_files})


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
