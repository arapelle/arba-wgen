cmake_minimum_required(VERSION 3.16)

project(basic_cmake_project)

# Find package wgen:
find_package(wgen 0.1.0 CONFIG REQUIRED)

# Here, wgen is used as a PRIVATE dependency
add_executable(${PROJECT_NAME} main.cpp)
get_target_property(wgen_compile_features wgen INTERFACE_COMPILE_FEATURES)
target_compile_features(${PROJECT_NAME} PRIVATE ${wgen_compile_features}) # For C++ standard
# Use wgen release shared library:
get_target_property(wgen_include_directories wgen INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(wgen_location wgen IMPORTED_LOCATION_RELEASE)
get_target_property(wgen_link_libraries wgen INTERFACE_LINK_LIBRARIES) # For strn
# Use wgen release static library:
#get_target_property(wgen_include_directories wgen-static INTERFACE_INCLUDE_DIRECTORIES)
#get_target_property(wgen_location wgen-static IMPORTED_LOCATION_RELEASE)
#get_target_property(wgen_link_libraries wgen-static INTERFACE_LINK_LIBRARIES) # For strn
target_include_directories(${PROJECT_NAME} PRIVATE ${wgen_include_directories})
target_link_libraries(${PROJECT_NAME} PRIVATE ${wgen_location} ${wgen_link_libraries})
