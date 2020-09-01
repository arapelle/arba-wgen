cmake_minimum_required(VERSION 3.16)

project(basic_cmake_project)

# Find package wgen:
find_package(strn 0.1.0 CONFIG REQUIRED)
find_package(wgen 0.1.4 CONFIG REQUIRED)
# Here, strn is used as a PRIVATE dependency
add_executable(${PROJECT_NAME} main.cpp)
# Use strn release shared library:
target_link_libraries(${PROJECT_NAME} PRIVATE wgen::wgen)
# Use strn release static library:
#target_link_libraries(${PROJECT_NAME} PRIVATE wgen::wgen-static)
