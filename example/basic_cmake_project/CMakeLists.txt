cmake_minimum_required(VERSION 3.16)

project(basic_cmake_project)

# Find package wgen:
find_package(wgen 0.2.0 CONFIG REQUIRED)
# Here, strn is used as a PRIVATE dependency
add_executable(${PROJECT_NAME} main.cpp)
# Use strn release shared library:
target_link_libraries(${PROJECT_NAME} PRIVATE arba::wgen)
# Use strn release static library:
#target_link_libraries(${PROJECT_NAME} PRIVATE arba::wgen-static)
