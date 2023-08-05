cmake_minimum_required(VERSION 3.26)

project(basic_cmake_project)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(${PROJECT_NAME}-static main.cpp)
# Find package arba-wgen:
find_package(arba-wgen 0.2.0 CONFIG REQUIRED)
# Use arba-wgen release shared target:
target_link_libraries(${PROJECT_NAME} PRIVATE arba-wgen)
# Use arba-wgen release static target:
target_link_libraries(${PROJECT_NAME}-static PRIVATE arba-wgen-static)
