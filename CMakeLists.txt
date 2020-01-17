#Change this if you need to target a specific CMake version
cmake_minimum_required(VERSION 2.6)
project(WidgetSFML)

if(CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
  endif ()
else ()
  set (CMAKE_CXX_STANDARD 11)
endif ()

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Release)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

include_directories("include")

file(
        GLOB_RECURSE
        source_files
        src/*.cpp
        include/*
)

file(
		GLOB_RECURSE
        example_demo_files
        example/demo/main.cpp
)

# Define sources and executable
set(LIBRARY_NAME "WidgetSFML")
set(EXAMPLE_DEMO_NAME "Demo")
add_definitions(-DWIDGETSFML_EXPORT)
add_library(${LIBRARY_NAME} SHARED ${source_files})
add_executable(${EXAMPLE_DEMO_NAME} ${example_demo_files})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${LIBRARY_NAME} ${SFML_LIBRARIES})
  target_link_libraries(${EXAMPLE_DEMO_NAME} ${SFML_LIBRARIES} ${LIBRARY_NAME})
endif()

#add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD
#                   COMMAND ${CMAKE_COMMAND} -E copy_directory
#                   ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${LIBRARY_NAME}>/../share/WidgetSFML/res)

install(TARGETS ${LIBRARY_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
    )

install(TARGETS ${EXAMPLE_DEMO_NAME}
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    )

install(FILES ${CMAKE_SOURCE_DIR}/res/*
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/WidgetSFML/res/
    )

