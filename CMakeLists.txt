
cmake_minimum_required(VERSION 3.17)

list(PREPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/include)

# Standard includes
include(CMakePrintHelpers)
# Custom include
include(cmtk/CppLibraryProject)

#-----
# PROJECT

set_build_type_if_undefined()

#-----
# C++ PROJECT

project(wgen
        VERSION 0.1.0
#        DESCRIPTION ""
#        HOMEPAGE_URL ""
        LANGUAGES CXX)

include(CTest)

add_public_cpp_library(
    VERSION_HEADER "version.hpp"
    VERBOSE_PACKAGE_CONFIG_FILE
)

#-----
